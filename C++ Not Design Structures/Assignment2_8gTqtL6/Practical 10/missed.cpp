#include "missed.h"
#include "exceptions.h"

Missed::Missed(int capacity) : CallHandler(capacity){
    
}

Missed::~Missed(){
    if (isEmpty() || head == NULL){
        return;
    }
   Call* nodePtr = head;
    while (nodePtr != NULL){       
        Call* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;     
    }
    head = NULL;
}

bool Missed::addCall(std::string id){

    if (isFull()){
        throw MissedCallsFull();
    }

    if (contains(id) == true){
        throw CallTaken();
    }

    Call* newNode = new Call(id);
    newNode->setResolved();
    newNode->next = head;
    head = newNode;
    size++;

    return true;

}

Call* Missed::removeCall(){
   // Call* temp;

    if (isEmpty()){
        throw MissedCallsEmpty();
    }

   Call* nodePtr = head;
   head = head->next;
   size--;
   //Call* output = new Call(nodePtr->getId());
   //output->setResolved();
   nodePtr->setResolved();

    //delete nodePtr;
    return nodePtr;
}

bool Missed::contains(std::string id){
    Call* nodePtr = head;
    
   for (int s = 0; s < 2 && nodePtr != NULL; s++){
    if (nodePtr->getId() == id){
        return true;
    }else{
        nodePtr = nodePtr->next;
    }
   }

    return false;
}