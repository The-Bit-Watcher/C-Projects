#ifndef TASK_CPP
#define TASK_CPP
#include "task.h"

//Your code here
template <class T>
Task<T>::Task(int priority, std::string description, bool repeat, T data){
   next = NULL;
   prev = NULL;
   this->priority = priority;
   this->description = description;
   this->repeat = repeat;
   this->data = data;
}

template <class T>
Task<T>::Task(const Task<T>& toCopy){
   this->next = NULL;
   this->prev = NULL;

   this->data = toCopy.data;
   this->description = toCopy.description;
   this->priority = toCopy.priority;
   this->repeat = toCopy.repeat;
}

template <class T>
Task<T>::~Task(){

}

template <class T>
int Task<T>::getPriority(){
    return priority;
}

template <class T>
std::string Task<T>::getDescription(){
    return description;;
}

template <class T>
bool Task<T>::getRepeat(){
    return repeat;
}

template <class T>
T Task<T>::getData(){
    return data;
}

template <class T>
Task<T>* Task<T>::getNext(){
    return next;
}

template <class T>
Task<T>* Task<T>::getPrev(){
    return prev;
}

template <class T>
bool Task<T>::setNext(Task<T>* nextTask){
    this->next = nextTask;
    return true;
}

template <class T>
bool Task<T>::setPrev(Task<T>* prevTask){
    this->prev = prevTask;
    return true;
}

template <class T>
bool Task<T>::operator==(const Task<T>& other){
    if (priority == other.priority && description == other.description &&
     repeat == other.repeat && data == other.data){
        return true;
     }

    return false;
}




#endif
//doubly linked list