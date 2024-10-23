#include "Headers.hpp"

class EventHandler {
    public:
        virtual void    handleEvent(int fd) = 0;
        virtual ~EventHandler();
};