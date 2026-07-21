#ifndef MANAGER_CPP
#define MANAGER_CPP
#include "manager.h"

//Your code here
template <class T>
TaskManager<T>::TaskManager(std::string fileName){
    std::ifstream file(fileName.c_str());
    if (!file){
        return;
    }

    weekly = NULL; priority = NULL; history = NULL;
    todo = new Todo<T>();

    std::string sline;
    std::string spriority, sdata, sdescription;
    std::string srepeat;
    bool brepeat;
    while (std::getline(file,sline)){
        std::stringstream stream(sline);
            
        std::getline(stream, spriority,'#');
          std::stringstream ss(spriority);
          int ipriority;
          ss >> ipriority;
           
        std::getline(stream, sdescription,'#');
        
        std::getline(stream, srepeat,'#');
            if (srepeat == "True"){
                brepeat = true;
            }else{brepeat = false;}
        std::getline(stream, sdata,'#');
        Task<T>* newTask = new Task<T>(ipriority, sdescription, brepeat, sdata);

        todo->addTask(newTask);
    }

}

template <class T>
TaskManager<T>::~TaskManager(){
    delete todo;
    delete weekly;
    delete priority;
    delete history;
}

template <class T>
Todo<T>* TaskManager<T>::getTodo(){
    return todo;
}

template <class T>
WeeklyTasks<T>* TaskManager<T>::getWeekly(){
    return weekly;
}

template <class T>
PriorityList<T>* TaskManager<T>::getPriority(){
    return priority;
}

template <class T>
History<T>* TaskManager<T>::getHistory(){
    return history;
}

template <class T>
bool TaskManager<T>::newTask(const Task<T>* newTask){

}

template <class T>
void TaskManager<T>::setWeeklyTasks(){
    weekly = new WeeklyTasks<T>();

        Task<T> *nodePtr;
        nodePtr = todo->getHead()->getNext();

        if (todo->getHead()->getRepeat() == true){
              weekly->addTask(todo->getHead());
                todo->removeTask(todo->getHead());
        }

        while (nodePtr != todo->getHead()){
           if (nodePtr->getRepeat() == true){
                weekly->addTask(nodePtr);
                todo->removeTask(nodePtr);
           }
           nodePtr = nodePtr->getNext();
        }
}

template <class T>
void TaskManager<T>::setPriority(){

}

template <class T>
std::string TaskManager<T>::doPriority(int numTasks){

}

template <class T>
std::string TaskManager<T>::undoTasks(bool all){

}

#endif