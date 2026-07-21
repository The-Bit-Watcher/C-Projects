/**
 * @file SendMessageCommand.h
 * @brief Concrete command for delivering messages to chat room users
 * @author Shaun Marx
 * @date 27-09-2025
 */

#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

/**
 * @brief Command for delivering messages to all users in a chat room
 * 
 * This command handles the distribution of messages to all participants
 * in the chat room except the sender.
 */
class SendMessageCommand : public Command {
public:
/**
     * @brief Construct a new SendMessageCommand object
     * @param room Pointer to the target chat room
     * @param user Pointer to the user who sent the message
     * @param msg The message content to deliver
     */
    SendMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);  // Fix parameter type
   
   /**
     * @brief Execute the message delivery command
     * 
     * Calls the chat room's sendMessage method to distribute the message
     * to all connected users in the room except the sender.
     */
    void execute() override;
};

#endif