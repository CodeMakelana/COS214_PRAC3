#include "Ezio.h"

Ezio::Ezio(ChatRoom* chatroom, std::string name) 
        : Users(chatroom, name) {}

Ezio::~Ezio() {
    // Destructor logic if needed
}
