/**
 * @file ChatRoom.h
 * @brief Header for ChatRoom abstract base class (Mediator pattern)
 * @author Tshepiso Makelana
 * @author Arran Lamond  
 * @date 2025-09-29
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
#include <iostream>

class Users;
template<typename T> class Iterator;

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

    // Iterator factory methods
    virtual Iterator<Users*>* createUsersIterator() = 0;
    virtual Iterator<std::string*>* createChatHistoryIterator() = 0;
};

#endif //CHATROOM_H
