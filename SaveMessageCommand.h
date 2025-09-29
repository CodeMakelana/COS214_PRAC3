/**
 * @file SaveMessageCommand.h
 * @brief 
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "Command.h"

class SaveMessageCommand : public Command {
public:
    SaveMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);
    void execute() override;
};

#endif //SAVEMESSAGECOMMAND_H