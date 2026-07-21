#include "chatHistoryIterator.h"

std::string chatHistoryIterator::first(){
    return room->getMessageAt(position);
}

std::string chatHistoryIterator::next(){
    position++;
    return room->getMessageAt(position);
}

bool chatHistoryIterator::isDone(){
    return position >= room->getMessageCount();
}

std::string chatHistoryIterator::currentItem(){
    return room->getMessageAt(position);
}

void chatHistoryIterator::reset(){
    position = 0;
}