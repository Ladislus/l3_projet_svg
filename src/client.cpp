//
// Created by ladislus on 05/03/2020.
//

#include "client.hpp"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cerr << "ERROR : No address provided !" << std::endl;
        return 1;
    }
    if (argc < 3) {
        std::cerr << "ERROR : No port provided !" << std::endl;
        return 1;
    }

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (socket_fd < 0) std::cerr << "ERROR : Socket creation failed !" << std::endl;

    struct addrinfo hints{};
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_canonname = nullptr;
    hints.ai_addr = nullptr;
    hints.ai_next = nullptr;

    struct addrinfo *server;

    int found = getaddrinfo(argv[1], argv[2], &hints  , &server);
    if (found < 0) {
        std::cerr << "ERROR : Host not found" << std::endl;
        return 1;
    }

    std::string x_input(""), y_input("");
    int x_value = -1, y_value = -1;
    bool x_ok = false, y_ok = false;

    while (!x_ok || !y_ok) {
        x_ok = false; y_ok = false;

        std::cout << "Enter 'x y' (65535 >= x >= 0, 65535 >= y >= 0) : ";
        std::cin >> x_input >> y_input;

        x_ok = parse(x_input, x_value);
        y_ok = parse(y_input, y_value);
    }

    unsigned char *buffer;

    cbor_item_t *chroot = cbor_new_definite_map(2);
    cbor_map_add(chroot, (struct cbor_pair) {
        .key = cbor_move(cbor_build_string("sun_x")),
        .value = cbor_move(cbor_build_uint16(x_value))
    });
    cbor_map_add(chroot, (struct cbor_pair) {
            .key = cbor_move(cbor_build_string("sun_y")),
            .value = cbor_move(cbor_build_uint16(y_value))
    });

    size_t buffer_size;
    size_t length = cbor_serialize_alloc(chroot, &buffer, &buffer_size);

    sendto(socket_fd, buffer, length, 0, server->ai_addr, server->ai_addrlen);

    free(buffer);
    freeaddrinfo(server); //Special free for addrinfo structs
    cbor_decref(&chroot); //Special free for CBor items

    return 0;
}

bool parse(const std::string& input, int& output) {
    try {
        output = std::stoi(input);
        return (output > 0);
    } catch (std::invalid_argument&) {
        return false;
    }
}