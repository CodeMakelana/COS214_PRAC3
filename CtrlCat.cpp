/**
 * @file CtrlCat.cpp
 * @brief Implementation file for CtrlCat chat room class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "CtrlCat.h"

/**
 * @brief Constructs a new CtrlCat chat room
 */
CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {
    // Initialize the users and chatHistory lists
    users = std::list<Users*>();
    chatHistory = std::list<std::string>();
}

/**
 * @brief Destroys the CtrlCat chat room and clears lists
 */
CtrlCat::~CtrlCat() {
    // Clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

/**
 * @brief Registers a user with the CtrlCat chat room
 * @param user Reference to the user to register
 */
void CtrlCat::registerUser(Users& user) {
    this->users.push_back(&user);
}

/**
 * @brief Sends a message to all users except the sender
 * @param mess The message content to send
 * @param fromUser Reference to the user sending the message
 */
void CtrlCat::sendMessage(std::string mess, Users& fromUser) {
    for (Users* u : this->users) {
        if (u != &fromUser) {
            u->receive(mess, &fromUser, this);
        }
    }
}

/**
 * @brief Saves a message to the chat history with username prefix
 * @param mess The message content to save
 * @param fromUser Reference to the user who sent the message
 */
void CtrlCat::saveMessage(std::string mess, Users& fromUser) {
    this->chatHistory.push_back(fromUser.getName() + ": " + mess);
}

/**
 * @brief Removes a user from the CtrlCat chat room
 * @param user Reference to the user to remove
 */
void CtrlCat::removeUser(Users& user) {
    this->users.remove(&user);
}

/**
 * @brief Creates an iterator for traversing users list
 * @return Iterator<Users*>* Pointer to new UsersIterator
 */
Iterator<Users*>* CtrlCat::createUsersIterator() {
    return new UsersIterator<Users>(users);
}

/**
 * @brief Creates an iterator for traversing chat history
 * @return Iterator<std::string*>* Pointer to new ChatHistoryIterator
 */
Iterator<std::string*>* CtrlCat::createChatHistoryIterator() {
    return new ChatHistoryIterator(chatHistory);
}