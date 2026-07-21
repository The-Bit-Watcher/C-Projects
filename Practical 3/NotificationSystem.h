/**
 * @file NotificationSystem.h
 * @brief Observer pattern implementation for real-time chat notifications
 * @author Your Name
 * @date 2024
 * 
 * Implements the Observer pattern to provide real-time notifications
 * for chat system activities. Users can register as observers to receive
 * notifications about messages, user joins/leaves, and other chat events.
 */

#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include <vector>
#include <string>

// Forward declaration
class Users;

/**
 * @brief Observer interface for notification recipients
 * 
 * Defines the contract for objects that want to receive notifications
 * from the chat system. Concrete observers must implement the update method.
 */
class NotificationObserver {
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~NotificationObserver() = default;
    
    /**
     * @brief Receive notification about chat activity
     * @param message The notification message content
     * @param roomName The name of the chat room where activity occurred
     * @param userName The name of the user who triggered the notification
     */
    virtual void update(const std::string& message, 
                       const std::string& roomName, 
                       const std::string& userName) = 0;
};

/**
 * @brief Subject interface for notification management
 * 
 * Defines the contract for objects that manage observers and distribute
 * notifications. Follows the Subject interface in Observer pattern.
 */
class NotificationSubject {
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~NotificationSubject() = default;
    
    /**
     * @brief Register an observer to receive notifications
     * @param observer Pointer to the observer to register
     */
    virtual void registerObserver(NotificationObserver* observer) = 0;
    
    /**
     * @brief Remove an observer from notification list
     * @param observer Pointer to the observer to remove
     */
    virtual void removeObserver(NotificationObserver* observer) = 0;
    
    /**
     * @brief Notify all registered observers
     * @param message The notification message content
     * @param roomName The chat room where activity occurred
     * @param userName The user who triggered the notification
     */
    virtual void notifyObservers(const std::string& message,
                                const std::string& roomName,
                                const std::string& userName) = 0;
};

/**
 * @brief Concrete subject for chat system notifications
 * 
 * Singleton class that manages notification observers and distributes
 * notifications about chat activities. Implements the Subject role
 * in the Observer pattern.
 */
class ChatNotificationSystem : public NotificationSubject {
private:
    std::vector<NotificationObserver*> observers;  ///< List of registered observers
    static ChatNotificationSystem* instance;       ///< Singleton instance
    bool isNotifying = false;                      ///< Flag to prevent re-entrancy

public:
    /**
     * @brief Get the singleton instance of notification system
     * @return ChatNotificationSystem* Pointer to the singleton instance
     * 
     * Implements Singleton pattern to ensure only one instance exists
     * throughout the application.
     */
    static ChatNotificationSystem* getInstance();
    
    /**
     * @brief Register an observer to receive notifications
     * @param observer Pointer to the observer to register
     */
    void registerObserver(NotificationObserver* observer) override;
    
    /**
     * @brief Remove an observer from notification list
     * @param observer Pointer to the observer to remove
     */
    void removeObserver(NotificationObserver* observer) override;
    
    /**
     * @brief Notify all registered observers about chat activity
     * @param message The notification message content
     * @param roomName The chat room where activity occurred
     * @param userName The user who triggered the notification
     * 
     * Prevents re-entrancy to avoid infinite notification loops.
     */
    void notifyObservers(const std::string& message,
                        const std::string& roomName,
                        const std::string& userName) override;
    
private:
    /**
     * @brief Private constructor for Singleton pattern
     */
    ChatNotificationSystem() = default;
};

/**
 * @brief Concrete observer for user notifications
 * 
 * Observes chat system activities and notifies specific users
 * about relevant events. Implements the Observer role in the
 * Observer pattern.
 */
class UserNotificationObserver : public NotificationObserver {
private:
    Users* user;  ///< The user to notify

public:
    /**
     * @brief Construct a new User Notification Observer object
     * @param user_ Pointer to the user who will receive notifications
     */
    UserNotificationObserver(Users* user_);
    
    /**
     * @brief Receive and process notification
     * @param message The notification message content
     * @param roomName The chat room where activity occurred
     * @param userName The user who triggered the notification
     * 
     * Forwards the notification to the associated user for handling.
     */
    void update(const std::string& message,
                const std::string& roomName,
                const std::string& userName) override;
};

#endif