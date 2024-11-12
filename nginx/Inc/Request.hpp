#pragma once

#include "Server.hpp"
#include "Response.hpp"


class Request {
    private:
        string  method;
        string  path;
        string  version;
        map<string, string> headers;
        string  body;
    public:
        Request(const string &rawRequest);
        const   string& getMethod() const;
        const   string& getPath() const;
        const   string& getVersion() const;
        const   string& getHeader(const string &key) const;
        const   string& getBody() const;
        void    parseRequestLine(const  string& line);
        void    parseHeaders(const  string& headerSection);
        ~Request();
};