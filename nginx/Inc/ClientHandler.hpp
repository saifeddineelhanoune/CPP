#include "EventHandler.hpp"

class ClientHandler : public EventHandler {
    private:
        int clientFd;
        std::map<int, EventHandler*> &handlers;
    public: 
        ClientHandler(int fd, std::map<int, EventHandler*> &handlers);
        void    handleEvent(int fd);
        void    closeConnection();
};