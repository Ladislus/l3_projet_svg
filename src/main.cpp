#include "server.hpp"

int main(int argc, char *argv[]) {

    unsigned short int port = 6789;
    if (argc >= 2) {
        port = atoi(argv[1]);
    } else {
        std::cout << "No port provided, using default port 6789" << std::endl;
    }

    Server server(port);
    server.start();

    return 0;
}