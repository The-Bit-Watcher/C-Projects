#ifndef DOUBLYLIST_CPP
#define DOUBLYLIST_CPP

#include "DoublyList.h"

//do insert next: 10/24/2024
template <class T>//should work
DoublyList<T>::DoublyList(){
   head = NULL;
   tail = NULL;
}

template <class T>
DoublyList<T>::DoublyList(const DoublyList<T>& other){
   if (other.head == NULL){
    head = NULL;
    tail = NULL;
    return;
   } 
    
   DoublyNode<T>* nodePtr = other.head;
    
    head = NULL;
    tail = NULL;
   int count = 1;
   
   while (nodePtr){
      insert(nodePtr->getData(),count);
      nodePtr = nodePtr->next;       
      count++;
   }

}

template <class T>//should work
DoublyList<T>::~DoublyList(){
    if (head == NULL){return;}

    DoublyNode<T>* nodePtr = head;

    while (nodePtr != NULL){
        DoublyNode<T> *temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
  }
}


template <class T>//should work
std::string DoublyList<T>::toString(){
    if (head == NULL){return "";}
    std::stringstream ss;


    DoublyNode<T>* nodePtr = head;

    while (nodePtr != NULL){
        ss << nodePtr->getData();

        if (nodePtr->next != NULL)
        { ss << "->";}
     

        nodePtr = nodePtr->next;
    }
    return ss.str();
}

template <class T>
void DoublyList<T>::insert(T data, int position){
   DoublyNode<T>* node = new DoublyNode<T>(data);
   DoublyNode<T>* nodePtr;
   int count;

    if (position == 0){return;}

    if (head == NULL){
        head = node;
        tail = node;
        return;
    }

    if (position > 0){
       count = 1;
       nodePtr = head;

       while (nodePtr->next != NULL and count < position){
           nodePtr = nodePtr->next;
           count++;
       }

       if (count == position){
        node->next = nodePtr;
        node->prev = nodePtr->prev;
        if (nodePtr->prev){
            nodePtr->prev->next = node;
        }else {head = node;}
        nodePtr->prev = node;
       }else{ tail->next = node;
         node->prev = tail;
         tail = node;
       }
    }


      if (position < 0){
        count = -1;
        nodePtr = tail;

        while (nodePtr->prev != NULL and count > position){
            nodePtr = nodePtr->prev;
            count--;
        }

        if (count == position){
            node->prev = nodePtr;
            node->next = nodePtr->next;
            if (nodePtr->next){
                nodePtr->next->prev = node;
            }else tail = node;
            nodePtr->next = node;
        }else{
            head->prev = node;
            node->next = head;
            head = node;
        }

      }
}

template <class T>
int DoublyList<T>::remove(T data){
    if (head == NULL){return 0;}
   // if (data == NULL){return 0;} 


    DoublyNode<T>* nodePtr = head;
    DoublyNode<T>* temp = NULL;

    int count = 0;

    while (nodePtr){
        if (nodePtr->getData() == data){
              temp = nodePtr;

              if (nodePtr == head){
                head = head->next;
                if (head){
                    head->prev = NULL;
                }
                else{ tail = NULL;}
              }else if (nodePtr == tail){
                tail = tail->prev;
                if (tail){
                    tail->next = NULL;
                }
              }else{
                nodePtr->prev->next = nodePtr->next;
                nodePtr->next->prev = nodePtr->prev;
              }

              nodePtr = nodePtr->next;
              delete temp;
              count = count + 1;
        }else{
            nodePtr = nodePtr->next;
        }
    }
    return count;
}

template <class T>//should work
int DoublyList<T>::contains(T data){
    if (head == NULL){return 0;}
   // if (data == NULL){return 0;}

    int count = 0;
    DoublyNode<T>* nodePtr = head;

    while (nodePtr != NULL){
       if (nodePtr->getData() == data)
       {
        ++count;
       }
       nodePtr = nodePtr->next;
    }
    return count;
}


#endif
