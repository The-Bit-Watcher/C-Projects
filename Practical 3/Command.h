/**
 * @file Command.h
 * @brief Command pattern abstract base class for chat system operations
 * @author Shaun Marx
 * @date 27-09-2025
 */

#ifndef COMMAND_H
#define COMMAND_H
#include <list>
#include "ChatRoom.h"
#include "Users.h"
class ChatRoom;
class Users;

/**
 * @brief Abstract base class for all command objects in the chat system
 * 
 * Implements the Command Pattern to encapsulate operations as objects.
 * Derived classes implement specific actions like sending or saving messages.
 */

class Command{
    protected:
    ChatRoom* room; ///< Pointer to the target chat room for the command
    Users* fromUser; ///< Pointer to the user who initiated the command
    std::string message; ///< The message content to be processed by the command

    public:
     /**
     * @brief Construct a new Command object
     * @param room Pointer to the target chat room
     * @param user Pointer to the user who sent the message
     * @param msg The message content to process
     */
    Command(const std::string& message, ChatRoom* room, Users* users);

     /**
     * @brief Pure virtual method to execute the command
     * 
     * This method must be implemented by derived classes to perform
     * specific actions like sending messages or saving to history.
     */
    virtual void execute() = 0;
    virtual ~Command() = default;
};

#endif