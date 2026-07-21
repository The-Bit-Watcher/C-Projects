#include "call.h"


/*string
– sstream
– fstream
– iostream*/
#include <sstream>

Call::Call(std::string id){
    this->id = id;
    this->resolved = false;
    this->next = NULL;
}

Call::~Call(){

}

std::string Call::getId() {
    return id;
}

void Call::setResolved(){
    if (resolved == true){
        resolved = false;
    }else{
        resolved = true;
    }
  
}

std::string Call::displayDetails() {
    std::stringstream ss;
    ss << "Caller: " << this->id << " Resolved: " << resolved;
    return ss.str();
}

