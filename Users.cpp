#include "Users.h"

Users::Users(ChatRoom* chatroom, std::string name) {
    this->name = name;
    this->chatrooms.push_back(chatroom);
    for (ChatRoom* cr : chatrooms) {
        cr->registerUser(*this);
    }
}

Users::~Users() {
    for (ChatRoom* cr : chatrooms) {
        cr->removeUser(*this);
    }
}

void Users::sendMessage(std::string message, ChatRoom* chatroom) {
    chatroom->sendMessage(message, *this);
}

void Users::receiveMessage(std::string message, Users* fromUser, ChatRoom* chatroom) {
    std::cout << this->name<< " in chatroo" << " received a message from " << fromUser->name << " in chatroom: " << message << std::endl;
    chatroom->saveMessage(message, *fromUser);
}
