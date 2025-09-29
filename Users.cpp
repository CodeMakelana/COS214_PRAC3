#include "Users.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
// #include "Strategy.h"

Users::Users(ChatRoom* chatroom, std::string name) {
    this->name = name;
    this->messageStrategy = new PlainTextStrategy(); // Assign default strategy
    std::cout << "User " << name << " is waiting to join a chatroom." << std::endl;
    this->chatrooms.push_back(chatroom);
    for (ChatRoom* cr : chatrooms) {
        cr->registerUser(*this);
    }
}

Users::~Users() {
    for (ChatRoom* cr : chatrooms) {
        cr->removeUser(*this);
    }

    //clean up strategy
    if (messageStrategy) {
        delete messageStrategy;
        messageStrategy = nullptr;
    }
}

void Users::send(std::string message, ChatRoom* chatroom) {

    if (!messageStrategy) {
        // Handle no strategy case or assign default
        return; // or set default strategy
    }
    
    std::string formattedMessage = messageStrategy->formatMessage(message, *this);

    //Create the commands
    Command* sendComms = new SendMessageCommand(chatroom, this, formattedMessage);
    Command* saveComms = new SaveMessageCommand(chatroom, this, formattedMessage);

    addCommand(sendComms);
    addCommand(saveComms);

    executeAll();
    
}

void Users::receive(std::string message, Users* fromUser, ChatRoom* chatroom) {
    std::cout << this->name<< " in chatroom "<< chatroom->getName() << " received a message from " << fromUser->name << " in chatroom " << chatroom->getName() << ": " << message << std::endl;
    chatroom->saveMessage(message, *fromUser);
}

void Users::addCommand(Command* command) {
    this->commands.push_back(command);
}

void Users::executeAll() {
    for (Command* cmd : commands) {
        cmd->execute();
        delete cmd;
    }
    commands.clear();
}

void Users::setMessageStrategy(MessageFormattingStrategy* strategy) {
    if (messageStrategy) {
        delete messageStrategy;
    }
    messageStrategy = strategy;
}

MessageFormattingStrategy* Users::getMessageStrategy() {
    return messageStrategy;
}