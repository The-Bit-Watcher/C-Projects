/**
 * @file userIterator.h
 * @brief Iterator for traversing users in a chat room
 * @author shaun Marx
 * @date 2025-09-28
 */

#ifndef USERITERATOR_H
#define USERITERATOR_H

#include "Users.h"
#include <list>

/**
 * @brief Iterator for traversing users in a ChatRoom using std::list
 * 
 * Implements the Iterator Pattern to provide a uniform interface for
 * traversing the collection of users in a chat room without exposing
 * the underlying list implementation.
 */
class userIterator{
private:
    std::list<Users*>::iterator current;///< Current position in the iteration
    std::list<Users*>::iterator end;      ///< End marker for the iteration
    std::list<Users*> userList;           ///< Copy of the user list for iteration

public:
     /**
     * @brief Construct a new userIterator object
     * @param usersList Reference to the list of users from ChatRoom
     */
    userIterator(const std::list<Users*>& usersList);
    
    /**
     * @brief Get the first user in the collection
     * @return Users* Pointer to the first user, or nullptr if empty
     */
    Users* first();
    
    /**
     * @brief Get the next user in the collection
     * @return Users* Pointer to the next user, or nullptr if at end
     */
    Users* next();
    
    /**
     * @brief Check if iteration is complete
     * @return true if all users have been iterated, false otherwise
     */
    bool isDone() const;
    
    /**
     * @brief Get the current user in iteration
     * @return Users* Pointer to current user, or nullptr if iteration is done
     */
    Users* currentItem() const;
    
    /**
     * @brief Reset iterator to beginning
     */
    void reset();
};

#endif