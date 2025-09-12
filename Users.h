#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>

#include <iostream>
#include "ChatRoom.h"

class Users {
    protected : 
    std::string name;
    //vector of chatrooms callled chatrooms
    std::vector<ChatRoom*> chatrooms;

    public :
    Users(ChatRoom* chatroom, std::string name);
    virtual ~Users();
    void send(std::string message, ChatRoom* chatroom);
    void receive(std::string message, Users* fromUser, ChatRoom* chatroom);
    std::string getName() const { return name; }
};



#endif //USERS_H
