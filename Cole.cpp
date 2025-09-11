#include "Cole.h"

Cole::Cole(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

Cole::~Cole() {
    // Destructor logic if needed
}
