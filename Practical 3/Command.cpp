#include "Command.h"

    Command::Command(const std::string& message, ChatRoom* room, Users* users){  
        this->room = room;   
        this->message = message;
        this->fromUser = users;
    }