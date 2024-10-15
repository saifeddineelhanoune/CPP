#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdexcept>

class Connection {
    protected:
        int _sockFd;
    public:
//Constructors
        Connection();
        Connection(int sockFd);
        Connection(const Connection& obj);
//Operators Overload
        Connection& operator=(const Connection& obj);
//Methods
        void    setNonBlocking();
        void    closeConnection();
//Destructor
        virtual ~Connection();
};