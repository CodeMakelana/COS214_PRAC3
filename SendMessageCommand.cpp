/**
 * @file SendMessageCommand.cpp
 * @brief Implementation file for SendMessageCommand class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "SendMessageCommand.h"

/**
 * @brief Constructs a new SendMessageCommand object
 * @param room Pointer to the chat room where message will be sent
 * @param fromUser Pointer to the user who sent the message
 * @param message The message content to send
 */
SendMessageCommand::SendMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message) {
    this->room = room;
    this->fromUser = fromUser;
    this->message = message;
}

/**
 * @brief Executes the send message command
 * Calls the chat room's sendMessage method to deliver the message to all registered users in the room except the sender.
 */
void SendMessageCommand::execute() {
    // Uses the chatRoom to deliver messages
    room->sendMessage(message, *fromUser);
}