#include "ChatRoom.h"
#include <iostream>

ChatRoom::ChatRoom(const std::string& roomName) : name(roomName) {}

ChatRoom::ChatRoom() : name("Default Room") {}

std::string ChatRoom::getName() const {
    return name;
}

ChatRoom::~ChatRoom() {}


void ChatRoom::saveMessage(const std::string message, Users* fromUser){
    std::string formatedMessage = "[" + getCurrentTime() + "] " + fromUser->getName() + ": " + message; 
    chatHistory.push_back(formatedMessage);
}

std::string ChatRoom::getCurrentTime(){
    static int time2 = 1;
    if (time2 > 24){
        time2 = 1;
    }
    return std::to_string(time2++);
}

void ChatRoom::sendMessage(const std::string message, Users* fromUser) {
    if (!fromUser) return;  // Safety check
    
    // First deliver messages to users
    for (Users* userPtr : user) {
        if (userPtr && userPtr != fromUser) {
            userPtr->receive(message, *fromUser, *this);
        }
    }
    // Then notify observers
    ChatNotificationSystem::getInstance()->notifyObservers(
        "New message",
        name, 
        fromUser->getName()
    );
}

Users* ChatRoom::getUserAt(){
    if (!user.empty()) {
        return user.front();
    }
    return nullptr;
}

int ChatRoom::userCount(){
    return user.size();
}

std::string ChatRoom::getMessageAt(int position){
    if (position >= 0 && position < static_cast<int>(chatHistory.size())) {
        return chatHistory[position];
    }
    return "";
}

int ChatRoom::getMessageCount(){
    return chatHistory.size();
}

void ChatRoom::displayChatHistory(){
    std::cout << "Chat History:" << std::endl;
    for (int i = 0; i < getMessageCount(); ++i) {
        std::cout << "  Message " << i + 1 << ": " << getMessageAt(i) << std::endl;
    }
}

userIterator ChatRoom::createIterator() {
    return userIterator(user);
}

Users* ChatRoom::getFirstUser() {
    if (!user.empty()) {
        return user.front();
    }
    return nullptr;
}

Users* ChatRoom::getNextUser(Users* currentUser) {
    if (!currentUser) return nullptr;
    
    bool found = false;
    for (auto it = user.begin(); it != user.end(); ++it) {
        if (found) {
            return *it;
        }
        if (*it == currentUser) {
            found = true;
        }
    }
    return nullptr;
}

void ChatRoom::all() {
    std::cout << "Amount of users in room: " << std::to_string(userCount()) << '\n';
    
    userIterator iter = createIterator();
    for (Users* u = iter.first(); !iter.isDone(); u = iter.next()) {
        if (u) {
            std::cout << u->getName() << '\n';
        }
    }
}

void ChatRoom::registerUser(Users* user_) {
    if (user_ && !hasUser(user_)) {
        user.push_back(user_);
        std::cout << user_->getName() << " registered in " << name << std::endl;
    }
}

void ChatRoom::removeUser(Users* user_) {
    if (!user_) return;
    
    for (auto it = user.begin(); it != user.end(); ++it) {
        if (*it == user_) {
            user.erase(it);
            std::cout << user_->getName() << " removed from " << name << std::endl;
            return;
        }
    }
}

bool ChatRoom::hasUser(Users* user_) const {
    if (!user_) return false;
    
    for (Users* u : user) {
        if (u == user_) {
            return true;
        }
    }
    return false;
}