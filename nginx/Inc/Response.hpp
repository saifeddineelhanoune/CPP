/*
     Common HTTP/1.1 Response:
        Date: Current GMT time for response generation.
        Server: Server identifier, set to CustomHTTPServer/1.0 as an example.
        Cache-Control: Default no-cache policy; configurable.
        Expires: Set to -1 to prevent caching by default.
        ETag: Set as an example, configurable for cache validation.
        Last-Modified: Placeholder for the last modified date of static resources.
        Content-Type: Default is text/html; set dynamically based on content.
        Content-Encoding: Default is identity, changeable for GZIP or Brotli if supported.
        Content-Language: Default to en; customizable based on application needs.
        Keep-Alive: Configures timeout and max requests for persistent connections.
        Transfer-Encoding: Set to chunked to allow chunked encoding for large responses.
        X-Frame-Options: Security header to prevent clickjacking.
        X-Content-Type-Options: Prevents MIME-sniffing, set to nosniff.
        X-XSS-Protection: Basic XSS protection for modern browsers.
        Strict-Transport-Security: Enforces HTTPS for up to 1 year (when HTTPS enabled).
        Accept-Ranges: Allows partial content requests, useful for video/audio streaming.
        Vary: Informs cache proxies of encoding variations (e.g., Accept-Encoding).
        Access-Control-Allow-Origin: Allows CORS, default to * for simplicity.
*/

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>

using namespace std;

class Response {
    private:
//Attributes
        map<string, string> headers;
        int     statusCode;
        string  statusMsg;
        string  body;
        struct statusEntry {
            int code;
            const char *message;
        };
        static const statusEntry statusTable[];
        static const    size_t  statusTableSize;
//private functions
        string  getDateTime();
    public:
//constructors
        Response();
        Response(const Response& resp);
//accessors
        map<string, string> getHeaders() const;
        int getStatusCode() const;
        string    getStatusMsg() const;
//member methods
        string  generateStatusLine() const;
        void  generateHeaders() const;
        string  generateStringHeader();
        void    setStatusCode(int code);
        void    addHeader(const string &key, const string &value);
        void    setBody(const string &content);
        void    setErrorPage(int errorCode);
        void    sendResponse(int clientSocket) const;
        void    clearHeaders();
        void    setContentLenght(size_t length);
        string  getFullResponse();  
};