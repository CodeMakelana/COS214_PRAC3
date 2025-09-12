#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "ChatRoom.h"
#include "Users.h"

class Command {
protected:
    ChatRoom* room;
    Users* fromUser;
    std::string message;
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

#endif //COMMAND_H