/**
 * @file Dogorithm.cpp
 * @brief Implementation file for Dogorithm chat room class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Dogorithm.h"

/**
 * @brief Constructs a new Dogorithm chat room
 */
Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {
    // Initialize the users and chatHistory lists
    users = std::list<Users*>();
    chatHistory = std::list<std::string>();
}

/**
 * @brief Destroys the Dogorithm chat room and clears lists
 */
Dogorithm::~Dogorithm() {
    // Clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

/**
 * @brief Registers a user with the Dogorithm chat room
 * @param user Reference to the user to register
 */
void Dogorithm::registerUser(Users& user) {
    this->users.push_back(&user);
}

/**
 * @brief Sends a message to all users except the sender
 * @param mess The message content to send
 * @param fromUser Reference to the user sending the message
 */
void Dogorithm::sendMessage(std::string mess, Users& fromUser) {
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
void Dogorithm::saveMessage(std::string mess, Users& fromUser) {
    this->chatHistory.push_back(fromUser.getName() + ": " + mess);
}

/**
 * @brief Removes a user from the Dogorithm chat room
 * @param user Reference to the user to remove
 */
void Dogorithm::removeUser(Users& user) {
    this->users.remove(&user);
}

/**
 * @brief Creates an iterator for traversing users list
 * @return Iterator<Users*>* Pointer to new UsersIterator
 */
Iterator<Users*>* Dogorithm::createUsersIterator() {
    return new UsersIterator<Users>(users);
}

/**
 * @brief Creates an iterator for traversing chat history
 * @return Iterator<std::string*>* Pointer to new ChatHistoryIterator
 */
Iterator<std::string*>* Dogorithm::createChatHistoryIterator() {
    return new ChatHistoryIterator(chatHistory);
}