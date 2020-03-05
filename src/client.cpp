//
// Created by ladislus on 05/03/2020.
//

#include <iostream>
#include <cbor.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

int main(int argc, char *argv[]) {

    if (argc < 2) std::cerr << "ERROR : No address provided !" << std::endl;
    if (argc < 3) std::cerr << "ERROR : No port provided !" << std::endl;

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (socket_fd < 0) std::cerr << "ERROR : Socket creation failed !" << std::endl;

    struct addrinfo hints{};
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    struct addrinfo *server;

    int found = getaddrinfo(argv[1], argv[2], &hints  , &server);
    if (found < 0) std::cerr << "ERROR : Host not found" << std::endl;

    unsigned char *buffer;

    cbor_item_t *chroot = cbor_new_definite_map(2);
    cbor_map_add(chroot, (struct cbor_pair) {
        .key = cbor_move(cbor_build_string("sun_x")),
        .value = cbor_move(cbor_build_uint8(10))
    });
    cbor_map_add(chroot, (struct cbor_pair) {
            .key = cbor_move(cbor_build_string("sun_y")),
            .value = cbor_move(cbor_build_uint8(5))
    });

    size_t buffer_size;
    size_t length = cbor_serialize_alloc(chroot, &buffer, &buffer_size);

    sendto(socket_fd, buffer, length, 0, server->ai_addr, server->ai_addrlen);

    free(buffer);
    cbor_decref(&chroot); //Free for CBor items

    return 0;
}