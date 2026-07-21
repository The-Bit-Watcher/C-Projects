#include "call_handler.h"

CallHandler::CallHandler(int capacity){
    this->capacity = capacity;
    size = 0;
    head = NULL;
}

CallHandler::~CallHandler(){

}

int CallHandler::getCapacity(){
    return this->capacity;
}

 int CallHandler::getSize() {
    return this->size;
}

Call* CallHandler::getHead(){
    return this->head;
}

void CallHandler::updateCapacity(int adjustment){
    capacity += adjustment;

    if (capacity <= 0){
        capacity = 1;
    }
}

bool CallHandler::isEmpty(){
    if (size == 0){
        return true;
    }
    return false;
}

bool CallHandler::isFull(){
    if (size == capacity){
        return true;
    }
    return false;
}

std::string CallHandler::callLog(){
    std::string result;
    Call* nodePtr = head;

    for (int s =0; s < this->size; s++){
        result += nodePtr->displayDetails() + '\n';
        nodePtr = nodePtr->next;
    }
    return result;
}
