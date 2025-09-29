/**
 * @file Cole.cpp
 * @brief 
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Cole.h"

Cole::Cole(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

Cole::~Cole() {
    // Destructor logic if needed
}
