#ifndef WEEKLY_CPP
#define WEEKLY_CPP
#include "weekly.h"

//Your code here
template <class T>
WeeklyTasks<T>::WeeklyTasks() : List<T>() {
    tail = NULL;
    numTasks = 0;
}

template <class T>
WeeklyTasks<T>::~WeeklyTasks(){
    if (this->getHead() != NULL){
        Task<T> *temp, *nodePtr;
        nodePtr = this->getHead()->getNext();

        while (nodePtr != this->getHead()){
            temp = nodePtr->getNext();
            delete nodePtr;
            nodePtr = temp;
        }

        delete this->getHead();
        //this->getHead() =NULL;
        tail = NULL;
    }
}

template <class T>
Task<T>* WeeklyTasks<T>::getTail(){
    return tail;
}

template <class T>
int WeeklyTasks<T>::getNumTasks(){
    return numTasks;
}

template <class T>//do 2024-11-06
bool WeeklyTasks<T>::addTask(const Task<T>* toAdd){
    if (toAdd == NULL){
        return NULL;
    }

    const Task<T>* newNode = toAdd;

    Task<T>* nodePtr = this->getHead();

    //sort first the add the node

    




    numTasks++;
}

template <class T>//do 2024-11-06. Might need to be redone due to logic
bool WeeklyTasks<T>::removeTask(Task<T>* toRemove){
    if (toRemove == NULL || this->getHead() == NULL){
        return false;
    }

    Task<T>* nodePtr = this->getHead();
    Task<T>* prev = NULL;
    Task<T>* newNode = toRemove;


    

if (nodePtr == newNode){//if this->getHead()
    if (nodePtr->getNext() == nodePtr)//only one node
    { tail = NULL;
        return true;
    }else{
        if (nodePtr == this->getHead() && nodePtr->getNext() != NULL){//not only this->getHead()
            if (nodePtr == newNode){//if remove this->getHead()
                this->getHead() = this->getHead()->getNext();
                this->getHead()->setPrev(tail);
                tail->setNext(this->getHead());
                }else{
                    if (newNode == tail){//if equal to tail
                        tail = tail->getPrev();
                         tail->setNext(this->getHead());
                        this->getHead()->setPrev(tail);
                    }else{//if not this->getHead() or tail
                        while (nodePtr->getNext() != this->getHead()){
                            if (nodePtr == newNode){
                              /*nodePtr->prev->next = nodePtr->next;
                               nodePtr->next->prev = nodePtr->prev;
                                         */
                                nodePtr->getPrev()->setNext(nodePtr->getNext());
                                nodePtr->getNext->setPrev(nodePtr->prev);
                                return true;
                                }
                                    nodePtr = nodePtr->getNext();
                            }
                                }         
                           }
                           
                }
            }
        } 
        return false;
    }

template <class T>   
std::string WeeklyTasks<T>::doTasks(){
    std::stringstream oss;

    Task<T>* nodePtr = this->getHead();

    while (nodePtr->getNext() != this->getHead()){
        oss << "Task" << nodePtr->getDescription() << " Data: " << nodePtr->getData() <<" COMPLETED" << "\n";   
       nodePtr = nodePtr->getNext();   
    }
    return oss.str();
}

template <class T>   
std::string WeeklyTasks<T>::doTasks(int repetitions){
    Task<T>* nodePtr = this->getHead();
    std::stringstream oss;

    for (int s=0; s < repetitions; s++){
       oss << "Task" << nodePtr->getDescription() << " Data: " << nodePtr->getData() <<" COMPLETED" << "\n";   
       nodePtr = nodePtr->getNext();
    }


    return oss.str();

}


#endif
//circular double linked list