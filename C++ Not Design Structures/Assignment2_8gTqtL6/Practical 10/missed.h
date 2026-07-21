#ifndef MISSED_H
#define MISSED_H

#include "call_handler.h"
#include "call.h"

class Missed : public CallHandler{
    public:
    Missed(int capacity);
    ~Missed();
    virtual bool addCall(std::string);
    virtual Call* removeCall();
    virtual bool contains(std::string id);
};


//Stack implementation. Using linked lists

#endif