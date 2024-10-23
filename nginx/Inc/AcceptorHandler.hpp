#include "EventHandler.hpp"

class AcceptorHandler : public EventHandler {
    int listenFd;
    std::map<int, EventHandler*> &handlers;

public:
    AcceptorHandler(int fd, std::map<int, EventHandler*> &handlers_map);
    void    handleEvent(int);
};
