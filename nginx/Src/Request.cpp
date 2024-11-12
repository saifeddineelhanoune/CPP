#include "../Inc/Server.hpp"

Request::Request(const string &rawRequest) {
    size_t headerEnd;
    size_t pos = rawRequest.find("\r\n");
    if (pos != string::npos) {
        parseRequestLine(rawRequest.substr(0, pos));
        headerEnd = rawRequest.find("\r\n\r\n");
        if (headerEnd != string::npos) {
            parseHeaders(rawRequest.substr(pos + 2, headerEnd - pos - 2));
            body = rawRequest.substr(headerEnd + 4);
        }
    }
}

void    Request::parseRequestLine(const string& line) {
    
}