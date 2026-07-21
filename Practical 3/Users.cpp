#include "Users.h"
#include <vector>
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "NotificationSystem.h"

Users::Users(std::string name_) {
    name = name_;
}

Users::~Users() {
    // Empty destructor
}

std::string Users::getName() const {
    return this->name;
}

    void Users::send(const std::string& message, ChatRoom* room){
        Command*  sendCmd = new SendMessageCommand(room,this, message); 
        Command* saveCmd = new LogMessageCommand(room,this, message);

        commandQueue.push_back(sendCmd);
        commandQueue.push_back(saveCmd);

        executeAll();

        delete saveCmd;
        delete sendCmd;
    }

   void Users::receive(const std::string& message, Users& fromUser, ChatRoom& room) {
    std::cout << name << " received from " << fromUser.getName() << ": " << message << std::endl;
    // Mark room as unused to avoid warning
    (void)room;
}

void Users::handleNotification(const std::string& message, 
                              const std::string& roomName, 
                              const std::string& userName) {
    // Only show notifications for activities not involving this user
    // AND only for rooms we're actually in
    if (userName != name) {
        // Check if this notification is for a room we're in
        bool isInThisRoom = false;
        for (ChatRoom* room : chatRooms) {
            if (room->getName() == roomName) {
                isInThisRoom = true;
                break;
            }
        }
        
        if (isInThisRoom) {
            std::cout << "🔔 " << name << " received NOTIFICATION: " << message 
                      << " (Room: " << roomName << ", User: " << userName << ")" << std::endl;
        }
    }
}

    void Users::addCommand(Command* command){
        commandQueue.push_back(command);
    }

   void Users::executeAll(){
        Command* queue = nullptr;
        while(!commandQueue.empty()){
            queue = commandQueue.back();
            commandQueue.pop_back();
            queue->execute();
        }
        commandQueue.clear();
   }

int Users::getRoomCount() const {
    return chatRooms.size();
}

void Users::enableNotifications() {
    if (!notificationsEnabled) {
        notificationsEnabled = true;
        notificationObserver = new UserNotificationObserver(this);
        ChatNotificationSystem::getInstance()->registerObserver(notificationObserver);
        std::cout << name << ": Notifications ENABLED" << std::endl;
    }
}

void Users::disableNotifications() {
    if (notificationsEnabled) {
        notificationsEnabled = false;
        if (notificationObserver) {
            ChatNotificationSystem::getInstance()->removeObserver(notificationObserver);
            delete notificationObserver;
            notificationObserver = nullptr;
        }
        std::cout << name << ": Notifications DISABLED" << std::endl;
    }
}

bool Users::areNotificationsEnabled() const {
    return notificationsEnabled;
}


void Users::joinRoom(ChatRoom* room) {
    if (room && !isInRoom(room)) {
        chatRooms.push_back(room);
        room->registerUser(this);  // This registers the user with the room
        
        std::cout << name << " joined room: " << room->getName() << std::endl;
    }
}

void Users::leaveRoom(ChatRoom* room) {
    if (!room) return;
    
    // Manual search and remove
    for (auto it = chatRooms.begin(); it != chatRooms.end(); ++it) {
        if (*it == room) {
            chatRooms.erase(it);
            room->removeUser(this);
            std::cout << name << " left room: " << room->getName() << std::endl;
            return;
        }
    }
}

void Users::leaveAllRooms() {
    // Create a copy of chatRooms to avoid modification during iteration
    std::vector<ChatRoom*> roomsToLeave = chatRooms;
    
    for (ChatRoom* room : roomsToLeave) {
        leaveRoom(room);
    }
    
    chatRooms.clear();
    std::cout << name << " left all rooms." << std::endl;
}

bool Users::isInRoom(ChatRoom* room) const {
    if (!room) return false;
    
    for (ChatRoom* r : chatRooms) {
        if (r == room) {
            return true;
        }
    }
    return false;
}

void Users::sendToRoom(const std::string& message, ChatRoom* room) {
    if (isInRoom(room)) {
        std::cout << name << " sending to room " << room->getName() << ": " << message << std::endl;
        
        Command* sendCmd = new SendMessageCommand(room, this, message); 
        Command* saveCmd = new LogMessageCommand(room, this, message);
        
        commandQueue.push_back(sendCmd);
        commandQueue.push_back(saveCmd);
        executeAll();
        
        delete saveCmd;
        delete sendCmd;
    } else {
        std::cout << name << " cannot send to room - not a member!" << std::endl;
    }
}

void Users::sendToAllRooms(const std::string& message) {
    std::cout << name << " broadcasting to " << chatRooms.size() << " rooms" << std::endl;
    
    // Create a copy to avoid issues if rooms change during iteration
    std::vector<ChatRoom*> roomsCopy = chatRooms;
    
    for (ChatRoom* room : roomsCopy) {
        if (room && isInRoom(room)) {
            sendToRoom(message, room);
        }
    }
}