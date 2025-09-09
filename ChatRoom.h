#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <list>

class ChatRoom {
    protected :
    //create a list of strings to hold messages
    std::list<std::string> chatHistory;
    //create a list of Users to hold users
    std::list<Users*> users;

    public :
    virtual ~ChatRoom() {}
    virtual void registerUser (Users user) = 0;
    virtual void sendMessage (string message, Users fromUser) = 0;
    virtual void saveMessage (string message, Users fromUser) = 0;
    virtual void removeUser (Users user) = 0;
};

#endif //CHATROOM_H
