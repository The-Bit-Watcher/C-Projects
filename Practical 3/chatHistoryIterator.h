#ifndef CHATHISTORYITERATOR_H
#define CHATHISTORYITERATOR_H

#include "ChatRoom.h"
#include <iostream>

class chatHistoryIterator{
    private:
    size_t position;
    ChatRoom* room;

    chatHistoryIterator(ChatRoom* room): room(room), position(0){};

    std::string first();
    std::string next();
    bool isDone();
    std::string currentItem();
    void reset();
};

#endif