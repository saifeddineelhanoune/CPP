#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <fstream>

#define PORT 8080
#define BUFFER_SIZE 1024

// Simple HTML response
const std::string HTML_RESPONSE =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Content-Length: 47\r\n"
    "\r\n"
    "<html><body><h1>Hello from C++ Server!</h1></body></html>";