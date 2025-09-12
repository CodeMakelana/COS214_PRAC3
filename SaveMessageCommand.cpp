#include "SaveMessageCommand.h"

SaveMessageCommand::SaveMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message) {
    this->room = room;
    this->fromUser = fromUser;
    this->message = message;
}

void SaveMessageCommand::execute() {
    //Uses chatRoom to save the messages
    room->saveMessage(message, fromUser);
}