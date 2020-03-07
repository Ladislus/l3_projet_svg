#include "serverUI.hpp"

int main(int argc, char *argv[])
{
    ServerUI* serverUI = new ServerUI();
    serverUI->start();

    return 0;
}