/**
 * @file Cindy.cpp
 * @brief Implementation file for Cindy user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Cindy.h"
/**
 * @brief Constructor for Cindy user
 * @param chatroom Pointer to the initial chat room to join
 * @param name The name of the user
 */
Cindy::Cindy(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

/**
 * @brief Destructor for Cindy user
 */
Cindy::~Cindy() {
    // Destructor logic if needed
}

/**
 * @brief Allows Cindy to join additional chat rooms
 * @param chatroom Pointer to the chat room to join
 * @note Adds the chatroom to Cindy's list and registers her in that chatroom
 */
void Cindy::joinChatRoom(ChatRoom* chatroom) {
    // Add the chatroom to Cindy's list and register her in that chatroom
    this->chatrooms.push_back(chatroom);
    chatroom->registerUser(*this);
}
