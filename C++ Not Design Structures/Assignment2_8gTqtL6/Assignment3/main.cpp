
#include <iostream>
#include "manager.h"



int main() {
    std::string fileName = "tasks.txt"; // Replace with the actual file name if different


    TaskManager<std::string> manager(fileName);

  
    std::cout << "Initial Todo List:" << std::endl;
     std::cout << manager.getTodo();

   
    manager.setWeeklyTasks();
    std::cout << "\nWeekly Tasks (from repeat flag):" << std::endl;
     manager.getWeekly();


    manager.setPriority();
    std::cout << "\nPriority Tasks (non-repeat):" << std::endl;
   std::cout << manager.getPriority();

   
    std::cout << "\nWeekly Tasks Done for 2 Cycles:" << std::endl;
    std::cout << manager.doWeekly(2) << std::endl;

    
    std::cout << "\nExecuting 3 Priority Tasks:" << std::endl;
    std::cout << manager.doPriority(3) << std::endl;


    std::cout << "\nUndo Last Task Done:" << std::endl;
    std::cout << manager.undoTasks(false) << std::endl;

    std::cout << "\nUndo All Tasks Done:" << std::endl;
    std::cout << manager.undoTasks(true) << std::endl;


    return 0;
}