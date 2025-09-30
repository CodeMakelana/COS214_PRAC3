/**
 * @file CtrlCat.h
 * @brief Header file for CtrlCat(concreteMediator) for cat chat room
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include "Iterator.h"
#include <string>

/**
 * @class CtrlCat
 * @brief Concrete chat room class for cat-themed conversations
 * Implements the Mediator pattern to handle communication between users
 * in the cat-themed chat room. Provides iterator creation for users and chat history.
 */
class CtrlCat : public ChatRoom {
public:
    /**
     * @brief Constructor for CtrlCat chat room
     */
    CtrlCat();
    /**
     * @brief Destructor for CtrlCat chat room
     */
    ~CtrlCat();
    /**
     * @brief Registers a user with the chat room
     * @param user Reference to the user to register
     */
    void registerUser(Users& user);
    /**
     * @brief Sends a message to all users in the chat room
     * @param message The message content to send
     * @param fromUser Reference to the user sending the message
     */
    void sendMessage(std::string message, Users& fromUser) override;
    /**
     * @brief Saves a message to the chat history
     * @param message The message content to save
     * @param fromUser Reference to the user who sent the message
     */
    void saveMessage(std::string message, Users& fromUser) override;
    /**
     * @brief Removes a user from the chat room
     * @param user Reference to the user to remove
     */
    void removeUser(Users& user) override;
    /**
     * @brief Creates an iterator for traversing users
     * @return Iterator<Users*>* Pointer to new users iterator
     */
    Iterator<Users*>* createUsersIterator() override;   
    /**
     * @brief Creates an iterator for traversing chat history
     * @return Iterator<std::string*>* Pointer to new chat history iterator
     */
    Iterator<std::string*>* createChatHistoryIterator() override;
};

#endif //CTRLCAT_H