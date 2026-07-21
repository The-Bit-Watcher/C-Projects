#ifndef INCOMING_H
#define INCOMING_H

#include "call.h"
#include "call_handler.h"

class Incoming : public CallHandler{
    Call* tail;
    public:
    Incoming(int capacity);
    ~Incoming();
    virtual bool addCall(std::string id);
    virtual Call* removeCall();
    virtual bool contains(std::string id);
};

#endif

//dynamic class. Queue implementation linked list