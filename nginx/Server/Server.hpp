#pragma once

#include "Client.hpp"

class Server : public Connection {
    private:
//Attributes
        struct sockaddr_in _serverAddr;
        std::vector<Client*> _clients;
    public:
//Constructors
        Server();
        Server(int port);
        Server(const Server& obj);
//Operators Overload
        Server& operator=(const Server& obj);
        friend std::ostream& operator<< (std::ostream &out, const Server& obj);
//Methods
        void    acceptClients();
        void    handleClients();
        void    run();
//Destructor
        ~Server();
};