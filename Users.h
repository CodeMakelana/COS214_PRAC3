#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include <iostream>
#include "ChatRoom.h"
#include "Command.h"                                                                                                                        

class Users {
    protected : 
    std::string name;
    //vector of chatrooms callled chatrooms
    std::vector<ChatRoom*> chatrooms;
    //vector of commands called commands
    std::vector<Command*> commands;

    public :
    Users(ChatRoom* chatroom, std::string name);
    virtual ~Users();
    void send(std::string message, ChatRoom* chatroom);
    void receive(std::string message, Users* fromUser, ChatRoom* chatroom);
    std::string getName() const { return name; }
    void addCommand(Command* command);
    void execuiteAll();
};



#endif //USERS_H
