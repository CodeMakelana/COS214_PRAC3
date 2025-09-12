#include "SendMessageCommand.h"

SendMessageCommand::SendMessageCommand(ChatRoom* room, Users* fromUser, const std::string& message) {
    this->room = room;
    this->fromUser = fromUser;
    this->message = message;
}

void SendMessageCommand::execute() {
    //uses the chatRoom to deliver messages
    room->sendMessage(message, *fromUser);
}