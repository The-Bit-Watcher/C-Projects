#include "userIterator.h"
#include <iostream>

userIterator::userIterator(const std::list<Users*>& usersList) 
    : userList(usersList) {
    reset();
}

Users* userIterator::first() {
    reset();
    return currentItem();
}

Users* userIterator::next() {
    if (!isDone()) {
        ++current;
        return currentItem();
    }
    return nullptr;
}

bool userIterator::isDone() const {
    return current == end;
}

Users* userIterator::currentItem() const { 
    if (!isDone()) {
        return *current;
    }
    return nullptr;
}

void userIterator::reset() {
    current = userList.begin();
    end = userList.end();
}