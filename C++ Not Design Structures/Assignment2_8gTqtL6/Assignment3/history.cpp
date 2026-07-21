#ifndef HISTORY_CPP
#define HISTORY_CPP
#include "history.h"
//stack implementation
//Your code here
template <class T>
History<T>::History(): List<T>(){
    numTasks = 0;   
}

template <class T>
History<T>::~History(){
    Task<T>* nodePtr = this->getHead();

    while (nodePtr != NULL){       
        Task<T>* temp = nodePtr;
        nodePtr = nodePtr->getNext();
        delete temp;     
    }
   // this->getHead() = NULL;
}

template <class T>
int History<T>::getNumTasks(){
    return numTasks;
}

template <class T>//do 2024-11-06
bool History<T>::addTask(const Task<T>* toAdd){

}

template <class T>//do 2024-11-06
Task<T>* History<T>::removeTask(){

}

template <class T>
std::string History<T>::undoLatest(){
   Task<T>* returnNode = removeTask();

   std::stringstream oss;
   oss << "Task: " << returnNode->getDescription();
   oss << " Priority: " << returnNode->getPriority();
   oss << " Data: " << returnNode->getData();
   oss << " UNDID\n";
   return oss.str();
}

template <class T>
std::string History<T>::doTasks(){
   Task<T>* nodePtr = this->getHead();
   std::stringstream oss;

   while (nodePtr){
     oss << "Task: " << nodePtr->getDescription();
   oss << " Priority: " << nodePtr->getPriority();
   oss << " Data: " << nodePtr->getData();
   oss << " UNDID\n";
   nodePtr = nodePtr->getNext();
   }
   return oss.str();
}


#endif