#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include "DoublyNode.h"

template <class T>
class DoublyList {

    private:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;

    public:
    DoublyList();
    DoublyList(const DoublyList& other);//copy constructor
    std::string toString();
    void insert(T data, int position);
    int contains(T data);
    int remove(T data);
    ~DoublyList();
};

#include "DoublyList.cpp"
#endif 

//2 pointers. Will probably have to insert and delete