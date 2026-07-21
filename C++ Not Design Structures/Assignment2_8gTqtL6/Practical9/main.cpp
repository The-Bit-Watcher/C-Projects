#include "DoublyList.h"
#include "DoublyNode.h"
#include <iostream>

int main(){

  DoublyList<int> newNode;

    newNode.insert(10, 1);  
    newNode.insert(20, 2);  
    newNode.insert(15, 2);  
    newNode.insert(5, -1);

    std::cout << "List after insertions: " << newNode.toString() << std::endl;

    newNode.remove(5);
    newNode.remove(10);

     std::cout << "List after removing: " << newNode.toString() << std::endl;

     newNode.insert(10, 1);  
     newNode.insert(20, 2);  
     newNode.insert(15, 2);  
     newNode.insert(5, -1);

     std::cout << "List after insertions: " << newNode.toString() << std::endl;


     newNode.remove(20);
     newNode.remove(10);

     std::cout << "List after removing: " << newNode.toString() << std::endl;
     DoublyList<int> node = newNode;
     std::cout << "Copied list: " << node.toString() << std::endl;

     std::cout <<newNode.contains(15)<<std::endl;
     std::cout <<newNode.remove(15)<<std::endl;

      std::cout << "List after removing: " << newNode.toString() << std::endl;

   
   return 0;
}
