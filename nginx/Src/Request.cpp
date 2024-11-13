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
    size_t  methodEnd = line.find(' ');
    size_t  pathEnd = line.find(' ', methodEnd + 1);

    method = line.substr(0, methodEnd);
    path = line.substr(methodEnd + 1, pathEnd - methodEnd - 1);
    version = line.substr(pathEnd + 1);
}

void    Request::parseHeaders(const string &headerSection) {
    size_t pos = 0;
    size_t prev = 0;
    while((pos = headerSection.find("\r\n", prev)) != string::npos) {
        string  header = headerSection.substr(prev, pos - prev);
        size_t  colonPos = header.find(": ");

        if (colonPos != string::npos) {
            string key = header.substr(0, colonPos);
            string value = header.substr(colonPos + 2);
            headers[key] = value;
        }
        prev = pos + 2;
    }
}

const   string& Request::getHeader(const string& key) const {
    static const string empty;
    map<string, string>::const_iterator it = headers.find(key);
    return it != headers.end() ? it->second : empty;
}

const   string& Request::getMethod() const {
    return method;
}

const   string& Request::getPath() const {
    return path;
}

const   string& Request::getVersion() const {
    return version;
}

const   string& Request::getBody() const {
    return body;
}

Request::~Request() {
    std::cout << "request Destructor called" << std::endl;
}