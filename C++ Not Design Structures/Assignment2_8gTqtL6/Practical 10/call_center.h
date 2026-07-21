#ifndef CALLCENTER_H
#define CALLCENTER_H    

#include "call_handler.h"
#include <fstream>
#include <sstream>
#include <string>

class CallCenter{
   private:
   CallHandler*** operators;
   int* phones;
   int numOperators;
   int callLimit;
   public:
   CallCenter(std::string filename);
   ~CallCenter();
   CallHandler*** getOperators();
   int* getPhones();
   int getNumOperators();
   int getCallLimit();
   void recieveCalls(std::string name);
   std::string takeCall(int op, int calls);
   std::string callBack(int op, int calls);
};
//uses data structures. The quee and stack

#endif