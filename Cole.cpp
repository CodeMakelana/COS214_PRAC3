/**
 * @file Cole.cpp
 * @brief Implementation file for Cole user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Cole.h"

/**
 * @brief Constructs a new Cole user object
 * @param chatroom Pointer to the initial chat room to join
 * @param name The name of the user
 */
Cole::Cole(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

/**
 * @brief Destroys the Cole user object
 */
Cole::~Cole() {
    // Destructor logic if needed
}