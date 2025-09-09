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
    Users(std::vector<ChatRoom*>& chatrooms, std::string name);
    void sendMessage(std::string message, ChatRoom* chatroom);
    void receiveMessage(std::string message, Users* fromUser, ChatRoom* chatroom);
};



#endif //USERS_H
