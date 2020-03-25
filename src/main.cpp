#include "server.hpp"

int main(int argc, char *argv[]) {

    Server* server;
    if (argc < 2) {
        std::cout << "No port provided, using default port 6789" << std::endl;
        server = new Server(6789);
    }
    else {
        server = new Server(atoi(argv[1]));
    }
    server->start();

    return 0;
}