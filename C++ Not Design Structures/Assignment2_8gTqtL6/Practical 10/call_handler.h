#ifndef CALLHANDLER_H
#define CALLHANDLER_H

#include "call.h"

class CallHandler{
    private: 
    int capacity;

    protected:
       int size;
       Call* head;
       public: 
       CallHandler(int capacity);
       ~CallHandler();
       int getSize() ; 
       int getCapacity() ;
       Call* getHead();
       void updateCapacity(int adjustment);
       bool isEmpty();
       bool isFull();
       std::string callLog();
       virtual bool addCall(std::string id) = 0;
       virtual Call* removeCall() = 0;
       virtual bool contains(std::string id) = 0;
};//abstratc class. Is interface for the 2 inheritance classes

#endif