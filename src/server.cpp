//
// Created by o2174867 on 13/02/20.
//

#include "server.hpp"

Server::Server(unsigned short int port) {

    if (port == 0) {
        this-> _status = PORT;
        error();
        exit(1);
    }
    this->_port = port;

    this->_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->_sock < 0) {
        this->_status = FAILED;
        error();
        exit(1);
    }

    socklen_t length = sizeof(this->_server);
    bzero(&(this->_server), length);
    this->_server.sin_family = AF_INET;
    this->_server.sin_addr.s_addr = INADDR_ANY;
    this->_server.sin_port = htons(this->_port);
    if (bind(this->_sock, (struct sockaddr *)&(this->_server), length) < 0) {
        this->_status = BINDING;
        error();
        exit(1);
    }
    this->_fromlen = sizeof(struct sockaddr_in);
    this->_status = OK;

    this->_controller = new XMLController();
}

void Server::error() {

    std::cerr << "ERROR : ";

    switch (this->_status) {
        case PORT:
            std::cerr << "No port provided !";
            break;
        case FAILED:
            std::cerr << "Failed to open the socket !";
            break;
        case BINDING:
            std::cerr << "Couldn't bind server !";
            break;
        case RECV:
            std::cerr << "Received data is invalid !";
            this->_status = OK;
            break;
        default:
            std::cerr << "Unknown error !";
            break;
    }

    std::cerr << std::endl;
}

void Server::start() {

    //TODO : Split in smaller methods

    if (this->_status != OK) {
        error();
        return;
    }
    else {

        ssize_t msg_size;

        //TODO : Find a way to stop the server infinite loop
        std::clog << "Start listening !" << std::endl << std::endl;
        while(true) {
            msg_size = recvfrom(this->_sock, this->_buffer, 1024, 0, (struct sockaddr *)&this->_from, &this->_fromlen);
            std::clog << "Received data !" << std::endl;
            if (msg_size < 0) {
                this->_status = RECV;
                error();
                continue;
            } else {

                //TODO : Better loading of the buffer
                struct cbor_load_result result;
                cbor_item_t * item = cbor_load(reinterpret_cast<cbor_data>(this->_buffer), msg_size, &result);

                if (!cbor_map_is_definite(item) || cbor_map_size(item) != 2) {
                    this->_status = RECV;
                    error();
                    continue;
                } else {

                    std::clog << "Type : " << item->type << "; ";
                    std::clog << "Is definite ? : " << cbor_map_is_definite(item) << "; ";
                    std::clog << "Size : " << cbor_map_size(item) << std::endl;

                    cbor_describe(item, stdout);

                    //FIXME : After adding a thread, cbor_map_handle corrupt the map
                    struct cbor_pair *map_test = cbor_map_handle(item);
                    cbor_describe(map_test[0].key, stdout);
                    std::clog << "Key 1 : " << map_test[0].key->data << " = " << map_test[0].value->data << "; ";
                    std::clog << "Key 2 : " << map_test[1].key->data << " = " << map_test[1].value->data << std::endl;

                    //TODO : Better way to get the keys in strings
                    std::string key_1 = reinterpret_cast<const char *>(map_test[0].key->data),
                                key_2 = reinterpret_cast<const char *>(map_test[1].key->data);

                    if (key_1 != "sun_x" || key_2 != "sun_y") {
                        this->_status = RECV;
                        error();
                        continue;
                    } else {
                        std::clog << "Valid data !" << std::endl;

                        //TODO : Better way to get the values in ints
                        int sun_y = *(map_test[1].value->data);
                        int sun_x = *(map_test[0].value->data);
                        std::clog << std::endl << "After extraction : " << std::endl;
                        std::clog << '[' << key_1 << "] " << sun_x << std::endl;
                        std::clog << '[' << key_2 << "] " << sun_y << std::endl;

                        cbor_decref(&item); //Cbor free of intermediate object

                        //TODO : Update value
                    }
                }
            }
        }
    }
}

void Server::stop() {
    //TODO : Free
}