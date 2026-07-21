#include "LogMessageCommand.h"

 LogMessageCommand::LogMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message): Command(message, room, fromUser){}

 void LogMessageCommand::execute(){
    room->saveMessage(message, fromUser);
 }//save message and user together