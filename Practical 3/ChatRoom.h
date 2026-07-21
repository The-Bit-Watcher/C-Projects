/**
 * @file ChatRoom.h
 * @brief Chat room class managing users, messages, and history
 * @author Shaun Marx
 * @date 2025-09-27
 *  */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Users.h"
#include "userIterator.h"
#include "NotificationSystem.h"

/**
 * @brief Represents a chat room that manages users and message history
 * 
 * This class acts as the Receiver in the Command Pattern. It provides
 * methods for message distribution, history management, user administration,
 * and supports iteration over users.
 */
class ChatRoom {
public:
    ChatRoom();
     /**
     * @brief Construct a new Chat Room object with a name
     * @param roomName The name of the chat room
     */
    ChatRoom(const std::string& roomName);
    std::string getName() const;
    ~ChatRoom();
    
      /**
     * @brief Register a new user to the chat room
     * @param user_ Pointer to the user to be registered
     * 
     * Adds the user to the room's user list, allowing them to send
     * and receive messages in this room.
     */
    void registerUser(Users* user_);

     /**
     * @brief Send a message to all users in the room
     * @param message The message content to deliver
     * @param fromUser Pointer to the user who sent the message
     * 
     * Iterates through all registered users and calls their receive() method
     * to deliver the message. Skips the sender to avoid echo.
     */
    void sendMessage(const std::string message, Users* fromUser);
    
     /**
     * @brief Save a message to the chat room's history
     * @param message The message content to save
     * @param fromUser Pointer to the user who sent the message
     * 
     * Formats the message with timestamp and user information, then
     * appends it to the chat history for persistent storage.
     */
    void saveMessage(const std::string message, Users* fromUser);
    void removeUser(Users* user_);
    
    std::string getCurrentTime();

    /**
     * @brief Display the chat history
     * 
     * Prints all messages in the chat history with their timestamps
     * and sender information.
     */
    void displayChatHistory();
    
    /**
     * @brief Check if a user is registered in this room
     * @param user_ Pointer to the user to check
     * @return true if user is in the room, false otherwise
     */
    bool hasUser(Users* user_) const;

    /**
     * @brief Create an iterator for users in this room
     * @return userIterator Iterator object for user traversal
     */
    userIterator createIterator();

    /**
     * @brief Get the first user in the room
     * @return Users* Pointer to the first user, or nullptr if empty
     */
    Users* getFirstUser();

    /**
     * @brief Get the next user after the current one
     * @param currentUser Pointer to the current user
     * @return Users* Pointer to the next user, or nullptr if at end
     */
    Users* getNextUser(Users* currentUser);
    

    Users* getUserAt();

    /**
     * @brief Display all users in the room
     * 
     * Prints a list of all users currently registered in this chat room.
     */
    void all();

     /**
     * @brief Get the number of users in the room
     * @return int Count of registered users
     */
    int userCount();

     
    /**
     * @brief Get the number of messages in chat history
     * @return int Count of messages in history
     */
    std::string getMessageAt(int position);
    int getMessageCount();

private:
    std::list<Users*> user; ///< List of users currently in this chat room
    std::vector<std::string> chatHistory; ///< Storage for all messages sent in the room
    std::string name;
};

#endif // CHATROOM_H