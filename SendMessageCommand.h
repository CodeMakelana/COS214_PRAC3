#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
#include "ChatRoom.h"
using namespace std;

class SendMessageCommand : public Command {
public:
    SendMessageCommand(ChatRoom* room, Users* fromUser, const string& message);
    void execute() override;
};

#endif //SENDMESSAGECOMMAND_H