#include "server.hpp"

int main(int argc, char *argv[]) {

    unsigned short int port = 6789;
    if (argc >= 2) {
        port = strtoul(argv[1], nullptr, 10);
        //If port == 0, an error occured
        if (!port) {
            port = 6789;
            std::cerr << "Bad port provided, using default port 6789" << std::endl;
        }
    } else {
        std::cout << "No port provided, using default port 6789" << std::endl;
    }

    Server server(port);
    server.start();

    return 0;
}