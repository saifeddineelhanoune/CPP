#pragma once

#include "Connection.hpp"

class Client : public Connection {
    public:
//Attributes
        struct sockaddr_in _clientAddr;
//Constructors
        Client();
        Client(struct sockaddr_in clientAddr, struct sockaddr_in clientAddr);
        Client(const Client& obj);
//Operators Overload
        Client& operator=(const Client& obj);
        friend std::ostream& operator<<(std::ostream& out, const Client &obj);
//Methods
        std::string     readRequest();
        void            sendResponse(const std::string &response);
//Destructor
        ~Client();
};