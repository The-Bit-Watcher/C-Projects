/**
 * @file LogMessageCommand.h
 * @brief Concrete command for saving messages to chat history
 * @author Shaun Marx
 * @date 27-09-2025
 */

#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"

/**
 * @brief Command for persisting messages to chat history
 * 
 * This command handles saving messages to the chat room's history
 * for later retrieval and archival purposes.
 */
class LogMessageCommand : public Command {
public:
  /**
     * @brief Construct a new LogMessageCommand object
     * @param room Pointer to the target chat room
     * @param user Pointer to the user who sent the message
     * @param msg The message content to save
     */
    LogMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);  // Fix parameter type
    
     /**
     * @brief Execute the message saving command
     * 
     * Calls the chat room's saveMessage method to append the message
     * to the chat history storage with proper formatting.
     */
    void execute() override;
};

#endif