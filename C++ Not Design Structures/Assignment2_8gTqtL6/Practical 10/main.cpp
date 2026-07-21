#include "call.h"
#include "incoming.h"
#include "missed.h"
#include "call_handler.h"
#include "exceptions.h"
#include "call_center.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

int main(){

    std::cout << "Testing Call Class:\n";
    Call call1("123ABC");//works
    std::cout << call1.displayDetails() << std::endl;//works

    call1.setResolved();//works
    std::cout << call1.displayDetails() << std::endl;//works

    //Incoming
    std::cout << "\nTesting Incoming Class:\n";
    Incoming incomingQueue(3);//Constructor Incoming == Queue

    try {
        incomingQueue.addCall("123ABC");//works
        incomingQueue.addCall("456DEF");//works
        std::cout << "Incoming queue log:\n" << incomingQueue.callLog() << std::endl;//works
        std::cout << "Contains " << incomingQueue.contains("123ABC") << std::endl; //works
        
        Call* removedCall = incomingQueue.removeCall();//works
        std::cout << "Removed Call: " << removedCall->displayDetails() << std::endl;//works
        delete removedCall;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    //Missed
    std::cout << "\nTesting Missed Class:\n";
    Missed missedStack(2);//Constructor Missed == stack

    try {
       missedStack.addCall("789GHI");//works
        missedStack.addCall("101JKL");//works
        std::cout << "Missed stack log:\n" << missedStack.callLog() << std::endl;//works
        std::cout << "Contains" << missedStack.contains("789GHI") << std::endl;//works

        Call* missedCall = missedStack.removeCall();//works
        std::cout << "Removed Missed Call: " << missedCall->displayDetails() << std::endl;//works
        delete missedCall;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

     //CallCenter
    std::cout << "\nTesting CallCenter Class:\n";
    
    CallCenter callCenter("setup.txt");//Constructor CallCenter

    try {
        callCenter.recieveCalls("calls.txt");//works
        std::cout << "After receiving calls:\n";
        std::cout << callCenter.takeCall(0, 2) << std::endl;//works incorrectly no output given
        std::cout << callCenter.callBack(0, 2) << std::endl;//works incorrectly no output given
    } catch (const std::exception& e) {
       // std::cout << e.what() << std::endl;
    }
 


    return 0;
}