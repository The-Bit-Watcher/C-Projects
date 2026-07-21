#include "SendMessageCommand.h"


SendMessageCommand::SendMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message):Command(message, room, fromUser){};

void SendMessageCommand::execute(){
    room->sendMessage(message, fromUser);
}//send message to all users so that they can see it