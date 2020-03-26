#include "server.hpp"

int main(int argc, char *argv[]) {

    unsigned short int port = 6789;
    if (argc >= 2) {
        char *error;
        port = strtol(argv[1], &error, strlen(argv[1]));
        if (*error) {
            std::cout << "Bad port provided, using default port 6789" << std::endl;
            port = 6789;
        }
    } else {
        std::cout << "No port provided, using default port 6789" << std::endl;
    }

    Server server(port);
    server.start();

    return 0;
}