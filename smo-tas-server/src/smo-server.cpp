#include <server.h>

int main()
{
    smo::Server server;
    server.start(7904);
    return 0;
}
