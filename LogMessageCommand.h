#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"

class LogMessageCommand : public Command {
public:
    LogMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);
    void execute() override;
};

#endif //LOGMESSAGECOMMAND_H