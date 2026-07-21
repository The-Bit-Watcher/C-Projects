#ifndef TODO_CPP
#define TODO_CPP
#include "todo.h"

//Your code here

#include <sstream>

template <class T>
Todo<T>::Todo():List<T>(){
    tail = NULL;
}

template <class T>
Todo<T>::~Todo(){
//have this->getHead() and tail
  Task<T>* nodePtr = this->getHead();
  Task<T>* temp;
  while (nodePtr != NULL){
    temp = nodePtr;
    nodePtr = nodePtr->getNext();
    delete temp;
  }
 //this->getHead() = NULL;
  tail = NULL;
}

template <class T>
Task<T>* Todo<T>::getTail(){
    return tail;
}

template <class T>
bool Todo<T>::addTask(const Task<T>* toAdd){
    if (toAdd == NULL){
        return false;
    }

     Task<T>* newNode = const_cast<Task<T>*>(toAdd);

    if (this->getHead() == NULL){
        tail = newNode;
        this->getHead()->setNext(NULL);
        tail->setPrev(NULL);
    }
     if (this->getHead() == tail){
        this->getHead()->setNext(tail);
        newNode->setPrev(this->getHead());
        newNode->setNext(NULL);
        tail = newNode;
        /*this->getHead()->next = toAdd;
        toAdd.prev = this->getHead();
        toAdd.next = NULL;
        tail = toAdd*/
     }else{
        /*tail->next = addNode;
        addNode->prev = tail;
        addNode->next = NULL;
        tail = addNode;*/
        
        tail->setNext(newNode);
        newNode->setPrev(tail);
        newNode->setNext(NULL);
        tail = newNode;
     }

     return true;
}

template <class T>
bool Todo<T>::removeTask(Task<T>* toRemove){
   if (this->getHead() == NULL || toRemove == NULL){
     return false;
   }

   if (this->getHead() == toRemove){
        if (this->getHead()->getNext() != NULL){
            /*this->getHead() = this->getHead()->next;
             this->getHead()->prev = NULL;*/
             this->getHead()->setNext(this->getHead()->getNext());
             this->getHead()->setPrev(NULL);
        }else{//only this->getHead()
           tail = NULL;
        }
        return true;    
   }

   if (tail == toRemove){
     if (tail->getPrev() != NULL){//if not only tail
        /*tail = tail->prev
        tail->next = NULL;*/
        tail = tail->getPrev();
        tail->setNext(NULL);
     }else{//only tail
        tail =  NULL;
     }
     return true;
   }

    Task<T>* nodePtr = this->getHead();
    //traversing threw list

    while(nodePtr){
       if (nodePtr == toRemove){

           //remove if in middle/in between 2 nodes
         /*nodePtr->prev->next = nodePtr->next;
         nodePtr->next->prev = nodePtr->prev;*/
           nodePtr->getPrev()->setNext(nodePtr->getNext());
           nodePtr->getNext()->setPrev(nodePtr->getPrev());
            return true;
       }
       nodePtr = nodePtr->getNext();
    }
delete toRemove;
return false;
}

template <class T>
Task<T>* Todo<T>::findTask(int priority){
  Task<T>* nodePtr = this->getHead();

  while (nodePtr){
    if (nodePtr->getPriority() == priority){
        return nodePtr;
    }
    nodePtr = nodePtr->getNext();
  }

  return false;
}

template <class T>
Task<T>* Todo<T>::findTask(std::string description){
  Task<T>* nodePtr = this->getHead();

  while (nodePtr){
    if (nodePtr->getDescription() == description){
        return nodePtr;
    }
    nodePtr = nodePtr->getNext();
  }

  return false;
}

template <class T>
std::string Todo<T>::doTasks(){
    Task<T>* nodePtr = this->getHead();
    std::stringstream oss;

    while (nodePtr){
       oss << nodePtr->getDescription() <<"\n";
       nodePtr = nodePtr->getNext();
    }
    return oss.str();
}

#endif
//doubly linked list