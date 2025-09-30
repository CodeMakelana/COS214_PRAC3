/**
 * @file ChatRoom.h
 * @brief Header file for ChatRoom abstract base class (Mediator pattern)
 * @author Tshepiso Makelana
 * @author Arran Lamond  
 * @date 2025-09-29
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
#include <iostream>

class Users;
template<typename T> class Iterator;

/**
 * @class ChatRoom
 * @brief Abstract base class for chat rooms mediating user communication
 * Manages user registration, message delivery, and provides iterators for users and chat history.
 * Prevents direct dependencies between user objects.
 */
class ChatRoom {
    //attribute doxygen:
    protected:
    std::string name;                       ///< Name of the chat room
    std::list<std::string> chatHistory;     ///< History of all messages
    std::list<Users*> users;                ///< Registered users in this room
    
    public:
    /**
     * @brief Constructor for ChatRoom
     * @param name The name of the chat room
     */
    ChatRoom(const std::string& name) : name(name) {}
    virtual ~ChatRoom() {}
    /**
     * @brief Gets the name of the chat room
     * @return std::string The name of the chat room
     */
    std::string getName() const { return name; }
    /**
     * @brief Registers a user with the chat room
     * @param user Reference to the User object to register
     */
    virtual void registerUser(Users& user) = 0;
    /**
     * @brief Sends a message to all users in the chat room
     * @param message The message content to send
     * @param fromUser Reference to the user sending the message
     */
    virtual void sendMessage(std::string message, Users& fromUser) = 0;
    /**
     * @brief Saves a message to the chat history
     * @param message The message content to save
     * @param fromUser Reference to the user who sent the message
     */
    virtual void saveMessage(std::string message, Users& fromUser) = 0;
    /**
     * @brief Removes a user from the chat room
     * @param user Reference to the User object to remove
     */
    virtual void removeUser(Users& user) = 0;
    // Iterator factory methods
    /**
     * @brief Creates an iterator for traversing users
     * @return Iterator<Users*>* Pointer to a new iterator for users list
     */
    virtual Iterator<Users*>* createUsersIterator() = 0;
    /**
     * @brief Creates an iterator for traversing chat history
     * @return Iterator<std::string*>* Pointer to a new iterator for chat history
     */
    virtual Iterator<std::string*>* createChatHistoryIterator() = 0;
};

#endif //CHATROOM_H
