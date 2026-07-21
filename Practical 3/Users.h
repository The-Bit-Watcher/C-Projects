/**
 * @file Users.h
 * @brief User class representing chat participants with command invocation
 * @author Shaun Marx
 * @date 2025-09-27
 */

#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>

class ChatRoom;
class Command;
class SendMessageCommand;
class LogMessageCommand;
class UserNotificationObserver;


/**
 * @brief Represents a user in the chat system with command invocation capabilities
 * 
 * This class acts as the Invoker in the Command Pattern. It maintains
 * a queue of commands and executes them in sequence when requested.
 * Users can join multiple chat rooms and send messages to specific rooms.
 */
class Users {
private:
    std::string name; ///< User's display name
    std::vector<Command*> commandQueue;  ///< Queue of commands waiting to be executed
    std::vector<ChatRoom*> chatRooms;///< List of chat rooms the user has joined
    UserNotificationObserver* notificationObserver;
    bool notificationsEnabled;

public:
 /**
     * @brief Construct a new Users object
     * @param name_ The display name for the user
     */
    Users(std::string name_);
    ~Users(); 
    
     /**
     * @brief Get the user's name
     * @return std::string The user's display name
     */
    std::string getName() const;
    
   /**
     * @brief Send a message to a specific chat room
     * @param message The message content to send
     * @param room Pointer to the target chat room
     * 
     * Creates and executes SendMessageCommand and LogMessageCommand
     * for the specified room using the Command Pattern.
     */
    void send(const std::string& message, ChatRoom* room);
    
    /**
     * @brief Join a chat room
     * @param room Pointer to the chat room to join
     * 
     * Adds the user to the specified chat room and registers them
     * with the room's user list.
     */
    void joinRoom(ChatRoom* room);

     /**
     * @brief Leave a specific chat room
     * @param room Pointer to the chat room to leave
     * 
     * Removes the user from the specified chat room and updates
     * the room's user list.
     */
    void leaveRoom(ChatRoom* room);

    /**
     * @brief Leave all chat rooms
     * 
     * Removes the user from all joined chat rooms and clears
     * the internal room list.
     */
    void leaveAllRooms();
    void sendToRoom(const std::string& message, ChatRoom* room);
    void sendToAllRooms(const std::string& message);
   
   /**
     * @brief Check if user is in a specific room
     * @param room Pointer to the chat room to check
     * @return true if user is in the room, false otherwise
     */
    bool isInRoom(ChatRoom* room) const;

     /**
     * @brief Get the number of rooms the user has joined
     * @return int Count of joined chat rooms
     */
    int getRoomCount() const;
    void listRooms() const;
    
     /**
     * @brief Receive a message from another user
     * @param message The received message content
     * @param fromUser Reference to the user who sent the message
     * @param room Reference to the chat room where message was sent
     * 
     * This method is called by the ChatRoom when a message is delivered
     * to this user. It handles displaying the received message.
     */
    void receive(const std::string& message, Users& fromUser, ChatRoom& room);
    
    /**
     * @brief Add a command to the execution queue
     * @param command Pointer to the command to be added
     * 
     * @note The Users object takes ownership of the command pointer
     */
    void addCommand(Command* command);
    
     /**
     * @brief Execute all commands in the queue
     * 
     * Iterates through the command queue and calls execute() on each command.
     * Clears the queue after all commands have been executed.
     */
    void executeAll();

     /**
     * @brief Enable real-time notifications for this user
     * 
     * Registers the user as an observer with the notification system
     * to receive notifications about chat activities.
     */
    void enableNotifications();

    /**
     * @brief Disable real-time notifications for this user
     * 
     * Unregisters the user from the notification system and
     * stops receiving notifications.
     */
    void disableNotifications();
    
    /**
     * @brief Check if notifications are enabled for this user
     * @return true if notifications are enabled, false otherwise
     */
    bool areNotificationsEnabled() const;

    /**
     * @brief Handle incoming notification from the notification system
     * @param message The notification message content
     * @param roomName The chat room where activity occurred
     * @param userName The user who triggered the notification
     * 
     * This method is called by the UserNotificationObserver when
     * a notification is received. It displays the notification to the user.
     */
    void handleNotification(const std::string& message, const std::string& roomName, const std::string& userName);
};

#endif