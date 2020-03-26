//
// Created by o2174867 on 13/02/20.
//

#ifndef DRIEUX_JOFFROY_WALCAK_MERCIER_SERVER_HPP
#define DRIEUX_JOFFROY_WALCAK_MERCIER_SERVER_HPP

#define SIZE 1024

#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <strings.h>
#include <cbor/data.h>
#include <cbor.h>
#include <cstring>
#include <thread>

#include "XMLController.hpp"

enum server_status { OK, FAILED, PORT, BINDING, RECV };

class Server {

    private:

        //Use of a pointer for the controller to prevent it from calling the default constructor now
        XMLController *_controller;
        server_status _status;
        unsigned short int _port;
        int _sock;
        struct sockaddr_in _server{};
        struct sockaddr_in _from{};
        socklen_t _fromlen;
        char _buffer[SIZE]{};

        void error();

    public:
        explicit Server(unsigned short int port);
        ~Server();

        void start();
};

#endif //DRIEUX_JOFFROY_WALCAK_MERCIER_SERVER_HPP
