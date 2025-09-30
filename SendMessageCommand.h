/**
 * @file SendMessageCommand.h
 * @brief Header file for SendMessageCommand
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending messages to all users in a chat room
 * Implements the Command pattern to encapsulate the action of delivering
 * messages to all registered users in a chat room except the sender.
 */
class SendMessageCommand : public Command {
public:
    /**
     * @brief Constructor for SendMessageCommand
     * @param room Pointer to the chat room where message will be sent
     * @param fromUser Pointer to the user who sent the message
     * @param message The message content to send
     */
    SendMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message);
    
    /**
     * @brief Executes the send message command
     */
    void execute() override;
};

#endif //SENDMESSAGECOMMAND_H