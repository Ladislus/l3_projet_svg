//
// Created by o2174867 on 13/02/20.
//
#include "server.hpp"

Server::Server(unsigned short int port) {

    if (port == 0) {
        this-> _status = PORT;
        error();
        return;
    }

    this->_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->_sock < 0) {
        this->_status = FAILED;
        error();
        return;
    }

    socklen_t length = sizeof(this->_server);
    bzero(&(this->_server), length);
    this->_server.sin_family = AF_INET;
    this->_server.sin_addr.s_addr = INADDR_ANY;
    this->_server.sin_port = htons(this->_port);
    if (bind(this->_sock, (struct sockaddr *)&(this->_server), length) < 0) {
        this->_status = BINDING;
        error();
        return;
    }
    this->_fromlen = sizeof(struct sockaddr_in);
    this->_status = OK;
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
        default:
            std::cerr << "Unknown error !";
            break;
    }

    std::cerr << std::endl;
}

void Server::start() {
    if (this->_status != OK) {
        error();
        return;
    }
    else {

        ssize_t msg_size;

        while(true) {
            msg_size = recvfrom(this->_sock, this->_buffer, 1024, 0, (struct sockaddr *)&this->_from, &this->_fromlen);
            if (msg_size < 0) {
                this->_status = RECV;
                error();
            }
            else {
                std::cout << "Received datagram : " << this->_buffer << std::endl;
                msg_size = sendto(this->_sock,"ACK\n", 4, 0,(struct sockaddr *)&this->_from, this->_fromlen);
                if (msg_size  < 0) {
                    this->_status = ACK;
                    error();
                }
            }


            this->_status = OK;
        }
    }
}