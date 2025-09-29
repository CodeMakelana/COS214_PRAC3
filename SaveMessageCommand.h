#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "Command.h"
#include "ChatRoom.h"
using namespace std;

class SaveMessageCommand : public Command {
public:
    SaveMessageCommand(ChatRoom* room, Users* fromUser, const string& message);
    void execute() override;
};

#endif //SAVEMESSAGECOMMAND_H