#ifndef COMMAND_H
#define COMMAND_H

#include <string>
// #include "ChatRoom.h"
// #include "Users.h"
using namespace std;
class ChatRoom;
class Users;

class Command {
protected:
    ChatRoom* room;
    Users* fromUser;
    string message;
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

#endif //COMMAND_H