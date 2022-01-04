#include <server.h>

int main()
{
    smo::Server server;
    server.start(7902);
    return 0;
}