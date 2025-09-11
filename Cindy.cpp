#include "Cindy.h"

Cindy::Cindy(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

Cindy::~Cindy() {
    // Destructor logic if needed
}

void Cindy::joinChatRoom(ChatRoom* chatroom) {
    // Add the chatroom to Cindy's list and register her in that chatroom
    this->chatrooms.push_back(chatroom);
    chatroom->registerUser(*this);
}
