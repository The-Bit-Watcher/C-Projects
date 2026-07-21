/**
 * @file NotificationSystem.cpp
 * @brief Implementation of Observer pattern for chat notifications
 * @author Your Name
 * @date 2024
 * 
 * Contains the implementation of notification system components
 * including the singleton ChatNotificationSystem and user observers.
 */

#include "NotificationSystem.h"
#include "Users.h"
#include <iostream>

// Initialize static singleton instance
ChatNotificationSystem* ChatNotificationSystem::instance = nullptr;

/**
 * @brief Get the singleton instance of notification system
 * @return ChatNotificationSystem* Pointer to singleton instance
 * 
 * Implements lazy initialization for the singleton pattern.
 */
ChatNotificationSystem* ChatNotificationSystem::getInstance() {
    if (instance == nullptr) {
        instance = new ChatNotificationSystem();
    }
    return instance;
}

/**
 * @brief Register an observer to receive notifications
 * @param observer Pointer to the observer to register
 */
void ChatNotificationSystem::registerObserver(NotificationObserver* observer) {
    observers.push_back(observer);
}

/**
 * @brief Remove an observer from notification list
 * @param observer Pointer to the observer to remove
 */
void ChatNotificationSystem::removeObserver(NotificationObserver* observer) {
    // Manual search and removal without using algorithm library
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            return;
        }
    }
}

/**
 * @brief Notify all registered observers about chat activity
 * @param message The notification message content
 * @param roomName The chat room where activity occurred
 * @param userName The user who triggered the notification
 * 
 * Uses a re-entrancy guard to prevent infinite notification loops
 * that could occur if notifications trigger further notifications.
 */
void ChatNotificationSystem::notifyObservers(const std::string& message,
                        const std::string& roomName,
                        const std::string& userName) {
    // Re-entrancy guard to prevent infinite loops
    if (isNotifying) {
        return;
    }
    
    isNotifying = true;
    
    // Notify all registered observers
    for (NotificationObserver* observer : observers) {
        observer->update(message, roomName, userName);
    }
    
    isNotifying = false;
}

/**
 * @brief Construct a new User Notification Observer object
 * @param user_ Pointer to the user who will receive notifications
 */
UserNotificationObserver::UserNotificationObserver(Users* user_) : user(user_) {}

/**
 * @brief Receive and forward notification to user
 * @param message The notification message content
 * @param roomName The chat room where activity occurred
 * @param userName The user who triggered the notification
 * 
 * Forwards the notification to the user's handleNotification method
 * for actual processing and display.
 */
void UserNotificationObserver::update(const std::string& message,
                const std::string& roomName,
                const std::string& userName) {
    if (user) {
        user->handleNotification(message, roomName, userName);
    }
}