#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "ChatRoom.h"
#include "Command.h"  
#include "Strategy.h" // Include the strategy header
using namespace std;

class Command;

class Users {
    protected: 
    string name;
    //vector of chatrooms callled chatrooms
    vector<ChatRoom*> chatrooms;
    //vector of commands called commands
    vector<Command*> commands;
    MessageFormattingStrategy* messageStrategy; // Strategy for message formatting
    public:
    Users(ChatRoom* chatroom, string name);
    virtual ~Users();
    void send(string message, ChatRoom* chatroom);
    void receive(string message, Users* fromUser, ChatRoom* chatroom);
    string getName() const { return name; }
    void addCommand(Command* command);
    void executeAll();

    // Strategy pattern methods
    void setMessageStrategy(MessageFormattingStrategy* strategy);
    MessageFormattingStrategy* getMessageStrategy();

    string getName() { return name; }
};

class Ezio : public Users {
    public:
    Ezio(ChatRoom* chatroom, string name);
    ~Ezio();
};

class Cole : public Users {
    public:
    Cole(ChatRoom* chatroom, string name);
    ~Cole();
};

class Cindy : public Users{
    public :
    Cindy(ChatRoom* chatroom, std::string name);
    ~Cindy();
    void joinRoom(ChatRoom* chatroom);

};


#endif //USERS_H