#include "serverUI.hpp"
#include "server.hpp"

int main(int argc, char *argv[])
{
//    ServerUI* serverUI = new ServerUI();
//    serverUI->start();
    Server* srv = new Server(6000);
    srv->start();

    return 0;
}