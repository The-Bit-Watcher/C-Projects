#include <iostream>
#include "Users.h"
#include "ChatRoom.h"

/**
 * @brief Test 1: Basic messaging without notifications
 */
void testBasicMessaging() {
    std::cout << "\n=== TEST 1: Basic Messaging (No Notifications) ===" << std::endl;
    
    ChatRoom* room = new ChatRoom("General");
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    std::cout << "Sending messages..." << std::endl;
    alice->send("Hello Bob!", room);
    bob->send("Hi Alice!", room);
    
    room->displayChatHistory();
    
    delete alice;
    delete bob;
    delete room;
}

/**
 * @brief Test 2: Notifications with one user
 */
void testSingleUserNotifications() {
    std::cout << "\n=== TEST 2: Single User Notifications ===" << std::endl;
    
    ChatRoom* room = new ChatRoom("Notifications Test");
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    std::cout << "Enabling notifications for Bob only..." << std::endl;
    bob->enableNotifications();
    
    std::cout << "Alice sends message (Bob should get notification)..." << std::endl;
    alice->send("Testing notifications", room);
    
    delete alice;
    delete bob;
    delete room;
}

/**
 * @brief Test 3: Multiple users with notifications
 */
void testMultipleUserNotifications() {
    std::cout << "\n=== TEST 3: Multiple User Notifications ===" << std::endl;
    
    ChatRoom* room = new ChatRoom("Multi-User Test");
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    std::cout << "Enabling notifications for Bob and Charlie..." << std::endl;
    bob->enableNotifications();
    charlie->enableNotifications();
    
    std::cout << "Alice sends message..." << std::endl;
    alice->send("Hello everyone!", room);
    
    std::cout << "Bob sends message..." << std::endl;
    bob->send("Hi there!", room);
    
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

/**
 * @brief Test 5: Disabling notifications
 */
void testDisableNotifications() {
    std::cout << "\n=== TEST 5: Disabling Notifications ===" << std::endl;
    
    ChatRoom* room = new ChatRoom("Disable Test");
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    bob->enableNotifications();
    
    std::cout << "With notifications enabled:" << std::endl;
    alice->send("Message 1 - Bob should get notification", room);
    
    std::cout << "Disabling notifications..." << std::endl;
    bob->disableNotifications();
    
    std::cout << "With notifications disabled:" << std::endl;
    alice->send("Message 2 - Bob should NOT get notification", room);
    
    delete alice;
    delete bob;
    delete room;
}

void testMultipleRooms() {
    std::cout << "\n=== TEST 4: Multiple Rooms (Fixed) ===" << std::endl;
    
    ChatRoom* general = new ChatRoom("General");
    ChatRoom* games = new ChatRoom("Games");
    
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    std::cout << "Step 1: Enabling notifications..." << std::endl;
    alice->enableNotifications();
    bob->enableNotifications();
    
    std::cout << "Step 2: Joining rooms..." << std::endl;
    alice->joinRoom(general);
    std::cout << "Alice joined General" << std::endl;
    
    bob->joinRoom(general);
    std::cout << "Bob joined General" << std::endl;
    
    alice->joinRoom(games);
    std::cout << "Alice joined Games" << std::endl;
    
    bob->joinRoom(games);
    std::cout << "Bob joined Games" << std::endl;
    
    std::cout << "Step 3: Sending to specific rooms..." << std::endl;
    alice->sendToRoom("Hello in General!", general);
    alice->sendToRoom("Hello in Games!", games);
    
    std::cout << "Step 4: Testing broadcast..." << std::endl;
    bob->sendToAllRooms("Broadcast message!");
    
    std::cout << "Step 5: Cleanup..." << std::endl;
    alice->leaveAllRooms();
    bob->leaveAllRooms();
    
    delete alice;
    delete bob;
    delete general;
    delete games;
    
    std::cout << "TEST 4 COMPLETED SUCCESSFULLY!" << std::endl;
}

int main() {
    std::cout << "🚀 FOCUSED TEST - Multiple Rooms Only" << std::endl;
    
    testBasicMessaging();
    testSingleUserNotifications(); 
    testMultipleUserNotifications();
    testMultipleRooms();
    testDisableNotifications();
    
    std::cout << "\n🎉 MULTIPLE ROOMS TEST PASSED!" << std::endl;
    return 0;
}