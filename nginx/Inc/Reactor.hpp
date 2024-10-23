#include "EventHandler.hpp"
#include "AcceptorHandler.hpp"

class Reactor {
    private:
        int socketFd;
        std::map<int, EventHandler*> handlers;
    public:
        Reactor(int port);
        void    run();
};