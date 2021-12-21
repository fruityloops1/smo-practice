#include <server.h>

int main()
{
    smo::Server server;
    server.start(7901);
    return 0;
}