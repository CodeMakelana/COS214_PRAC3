#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Users;
template<typename T> class Iterator;

class ChatRoom {
protected:
    string name;
    list<string> chatHistory;
    list<Users*> users;

public:
    ChatRoom(const string& name) : name(name) {}
    virtual ~ChatRoom() {}
    string getName() const { return name; }

    virtual void registerUser(Users& user) = 0;
    virtual void sendMessage(string message, Users& fromUser) = 0;
    virtual void saveMessage(string message, Users& fromUser) = 0;
    virtual void removeUser(Users& user) = 0;
    //we make use of iterator here to go through the users list and the chatHistory list
    virtual Iterator<Users*>* usersListIterator() = 0;
    virtual Iterator<string*>* chatHistoryListIterator() = 0;
};

#endif //CHATROOM_H
