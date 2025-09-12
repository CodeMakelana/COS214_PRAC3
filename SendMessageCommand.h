#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

class SendMessageCommand : public Command {
public:
    SendMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);
    void execute() override;
};

#endif //SENDMESSAGECOMMAND_H