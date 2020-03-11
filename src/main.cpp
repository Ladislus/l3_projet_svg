#include "server.hpp"

int main(int argc, char *argv[])
{
    //TODO : Get port from argv
    auto* server = new Server(5555);
    server->start();

    return 0;
}