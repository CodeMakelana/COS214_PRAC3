/**
 * @file Ezio.cpp
 * @brief 
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
