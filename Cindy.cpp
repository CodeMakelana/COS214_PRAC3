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

