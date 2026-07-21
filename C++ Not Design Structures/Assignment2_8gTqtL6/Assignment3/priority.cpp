#ifndef PRIORITY_CPP
#define PRIORITY_CPP
#include "priority.h"

//Your code here

template <class T>
PriorityList<T>::PriorityList(): List<T>(){
    tail = NULL;
    numTasks = 0;
}

template <class T>
PriorityList<T>::~PriorityList(){
    Task<T>* temp;
    Task<T>* nodePtr = this->getHead();
   while (nodePtr != NULL){
      temp = nodePtr;
      nodePtr = nodePtr->getNext();
      delete temp;
   }
    tail = NULL;
   // this->getHead() = NULL;
}

template <class T>
Task<T>* PriorityList<T>::getTail(){
   return tail;
}

template <class T>
int PriorityList<T>::getNumTasks(){
    return numTasks;
}

template <class T>
bool PriorityList<T>::addTask(const Task<T>* toAdd){
    if (toAdd == NULL){
        return false;
    }

    Task<T>* nodePtr = this->getHead();
    Task<T>* newNode = const_cast<Task<T>*>(toAdd);

    if (nodePtr == NULL){
         tail = newNode;
        return true;
    }

    if (nodePtr->getNext() == NULL){
        //only this->getHead();
        newNode->setNext(nodePtr);
        nodePtr->setPrev(newNode);
        newNode->setPrev(nodePtr);
        nodePtr->setNext(newNode);
        return true;
    }else{
        //add to this->getHead() if not only this->getHead()
        tail->setNext(newNode);
        newNode->setPrev(tail);
        newNode->setNext(this->getHead());
        this->getHead()->setPrev(newNode);
        tail->setNext(newNode);
        newNode->setNext(this->getHead());
    }
}

template <class T>
bool PriorityList<T>::removeTask(){
   if (this->getHead() == NULL){
    return false;
   }

   if (tail == NULL){
    return false;
   }

   Task<T>* prevTail = tail->getPrev();
   Task<T>* toRemove = tail;

   if (prevTail == NULL){
    return false;
   }

   if (prevTail != NULL){
     if (tail->getPrev() == this->getHead()){
        this->head = tail;
     }//if only this->getHead() and tail
     else if (tail == this->getHead()){
         tail = NULL;
     }//only one Node
     else{
        prevTail->setNext(this->getHead());
        this->getHead()->setPrev(prevTail);
     }//more than 2 Nodes: 3 plus nodes
     return true;
     delete toRemove;
   }
   
}

template <class T>
std::string PriorityList<T>::doNTasks(int numTasks){
    Task<T>* nodePtr = this->getHead();
    Task<T>* temp;
    if (this->getHead() == NULL){
        return "0";
    }
    std::stringstream oss;

    for (int s = 0; s < numTasks; s++){
       
        if (nodePtr){
            oss << "Task: " << nodePtr->getDescription()<< "Priority: " << nodePtr->getPriority();
            oss << "Data: " << nodePtr->getData();
            oss <<" COMPLETED"<<'\n';
            temp = nodePtr;
            nodePtr = nodePtr->getNext();
            this->removeTask(temp);
        }else{
            return oss.str();
        }

        nodePtr = nodePtr->getNext();
    }
    return oss.str();
}

template <class T>
std::string PriorityList<T>::doTasks(){
    std::stringstream oss;
    Task<T>* nodePtr = this->getHead();
    Task<T>* temp;

    while(nodePtr->getNext() != this->getHead()){
         oss << "Task: " << nodePtr->getDescription()<< "Priority: " << nodePtr->getPriority();
            oss << "Data: " << nodePtr->getData();
            oss <<" COMPLETED"<<'\n';
            temp = nodePtr;
            nodePtr = nodePtr->getNext();
            removeTask();
    }
    return oss.str();  
}

#endif