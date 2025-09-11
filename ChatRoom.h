#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
// #include "Users.h"
#include <string>
#include <iostream>

class Users;

class ChatRoom {
protected:
    std::string name;
    std::list<std::string> chatHistory;
    std::list<Users*> users;

public:
    ChatRoom(const std::string& name) : name(name) {}
    virtual ~ChatRoom() {}
    std::string getName() const { return name; }

    virtual void registerUser(Users& user) = 0;
    virtual void sendMessage(std::string message, Users& fromUser) = 0;
    virtual void saveMessage(std::string message, Users& fromUser) = 0;
    virtual void removeUser(Users& user) = 0;
};

#endif //CHATROOM_H
