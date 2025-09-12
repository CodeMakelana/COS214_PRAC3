#include "Users.h"

Users::Users(ChatRoom* chatroom, std::string name) {
    this->name = name;
    std::cout << "User " << name << " is waiting to join a chatroom." << std::endl;
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

void Users::send(std::string message, ChatRoom* chatroom) {
    chatroom->sendMessage(message, *this);
}

void Users::receive(std::string message, Users* fromUser, ChatRoom* chatroom) {
    std::cout << this->name<< " in chatroom "<< chatroom->getName() << " received a message from " << fromUser->name << " in chatroom " << chatroom->getName() << ": " << message << std::endl;
    chatroom->saveMessage(message, *fromUser);
}
