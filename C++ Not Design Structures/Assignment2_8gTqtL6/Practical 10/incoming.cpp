#include "incoming.h"//queue implementation
#include "exceptions.h"

Incoming::Incoming(int capacity) : CallHandler(capacity){
    tail = NULL;
}

Incoming::~Incoming(){

  /* if (isEmpty() || head == NULL){
      return;
   }*/
    Call* temp;
    Call* nodePtr = head;
   while (nodePtr != NULL){
      temp = nodePtr;
      nodePtr = nodePtr->next;
      delete temp;
   }
    tail = NULL;
    head = NULL;
}

bool Incoming::addCall(std::string id){
   if (isFull()){
      throw IncomingCallsFull();
   }
   
   Call* newNode = new Call(id);

  /* if (isEmpty()){
      head = tail = newNode;
   }else{
      Call* nodePtr = head;
      while (nodePtr != NULL){
         if (nodePtr->getId() == id){
            throw CallTaken();
         }
         nodePtr = nodePtr->next;
      }

      Call* newNode = new Call(id);  
      tail->next = newNode;
      tail = newNode;
   }
   size++;
   return true;*/


   
   if (tail == NULL){
      head = newNode;
      tail = newNode;
   }else{
      Call* nodePtr = head;
      while (nodePtr != NULL){
         if (nodePtr->getId() == id){
            delete newNode;
            throw CallTaken();
         }else{
            nodePtr = nodePtr->next;
         }
      }
      tail->next = newNode;
      tail = newNode;
   }
   
   size++;
   return true;
}

Call* Incoming::removeCall(){
   if (isEmpty()){
      throw IncomingCallsEmpty();
   }
     
     Call* temp = head;
     head = head->next;
    //Call* newNode = new Call(temp->getId());
   
   if (head == NULL){
      tail = NULL;
   }

   //delete temp;
   size--;
   
   temp->setResolved();
   return temp;
}

bool Incoming::contains(std::string id){

   Call* nodePtr = head;

   while (nodePtr != NULL){
      if (nodePtr->getId() == id){
         return true;
      }
      nodePtr = nodePtr->next;
   }
   return false;
}