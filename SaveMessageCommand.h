/**
 * @file SaveMessageCommand.h
 * @brief Header file for SaveMessageCommand
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class SaveMessageCommand
 * @brief Concrete command for saving messages to chat history
 * Implements the Command pattern to encapsulate the action of saving
 * messages to a chat room's history for later retrieval.
 */
class SaveMessageCommand : public Command {
public:
    /**
     * @brief Constructor for SaveMessageCommand
     * @param room Pointer to the chat room where message will be saved
     * @param fromUser Pointer to the user who sent the message
     * @param message The message content to save
     */
    SaveMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);
    /**
     * @brief Executes the save message command
     */
    void execute() override;
};

#endif //SAVEMESSAGECOMMAND_H