//
// Created by o2174867 on 13/02/20.
//

#ifndef DRIEUX_JOFFROY_WALCAK_MERCIER_SERVER_HPP
#define DRIEUX_JOFFROY_WALCAK_MERCIER_SERVER_HPP

#define SIZE 1024

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <iostream>

enum server_status { OK, FAILED, PORT, BINDING, RECV, ACK };

class Server {

    private:
        server_status _status;
        unsigned short int _port;
        int _sock;
        struct sockaddr_in _server;
        struct sockaddr_in _from;
        socklen_t _fromlen;
        char _buffer[SIZE];

        void error();

    public:
        explicit Server(unsigned short int port);
        void start();
};

#endif //PROJET_SOCKET_HPP
