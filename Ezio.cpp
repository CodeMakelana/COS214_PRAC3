/**
 * @file Ezio.cpp
 * @brief Implementation file for Ezio user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Ezio.h"

/**
 * @brief Constructs a new Ezio user object
 * @param chatroom Pointer to the initial chat room to join
 * @param name The name of the user
 */
Ezio::Ezio(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}
/**
 * @brief Destroys the Ezio user object
 */
Ezio::~Ezio() {
    // Destructor logic if needed
}