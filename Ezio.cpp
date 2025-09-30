/**
 * @file Ezio.cpp
 * @brief Implementation file for Ezio user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Ezio.h"

Ezio::Ezio(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

Ezio::~Ezio() {
    // Destructor logic if needed
}
