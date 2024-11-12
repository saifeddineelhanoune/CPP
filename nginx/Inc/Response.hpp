#pragma once

# include "Server.hpp"
# include <string>
# include <map>

class Response {
    private:
        int statusCode;
        string  statusMessage;
        map<string, string> headers;
        string  body;

    public:
        Response(int code, const string &message);
        void    setStatus(int code, const string &message);
        void    setHeader(const string &key, const string &value);
        void    setBody(const string &content);
        string  toString() const;
};