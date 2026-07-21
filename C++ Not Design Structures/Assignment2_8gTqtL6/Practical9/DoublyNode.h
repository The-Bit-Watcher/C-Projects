#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

#include <sstream>
#include <string>//only allowed to use this

template <class T>
class DoublyNode {
   private:
    T data;

   public:
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
    DoublyNode(T data);
    ~DoublyNode();

    T getData();//returns value

    std::string toString();//string representation of next and prev as well as its val
};

#include "DoublyNode.cpp"

#endif