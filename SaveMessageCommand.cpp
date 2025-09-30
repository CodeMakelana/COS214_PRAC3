/**
 * @file SaveMessageCommand.cpp
 * @brief Implementation file for SaveMessageCommand class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "SaveMessageCommand.h"

/**
 * @brief Constructs a new SaveMessageCommand object
 * @param room Pointer to the chat room where message will be saved
 * @param fromUser Pointer to the user who sent the message
 * @param message The message content to save
 */
SaveMessageCommand::SaveMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message) {
    this->room = room;
    this->fromUser = fromUser;
    this->message = message;
}

/**
 * @brief Executes the save message command
 * Calls the chat rooms saveMessage method to add the message to the chat history for later retrieval.
 */
void SaveMessageCommand::execute() {
    // Uses chatRoom to save the messages
    room->saveMessage(message, *fromUser);
}