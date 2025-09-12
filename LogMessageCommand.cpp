#include "LogMessageCommand.h"

LogMessageCommand::LogMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message) {
    this->room = room;
    this->fromUser = fromUser;
    this->message = message;
}

void LogMessageCommand::execute() {
    //Uses chatRoom to save the messages
    room->saveMessage(message, fromUser);
}