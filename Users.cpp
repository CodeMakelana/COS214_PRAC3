#include "Users.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"

Users::Users(ChatRoom* chatroom, string name) {
    this->name = name;
    this->messageStrategy = new PlainTextStrategy(); // Assign default strategy
    cout << "User " << name << " is waiting to join a chatroom." << endl;
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

void Users::send(string message, ChatRoom* chatroom) {
    // Use strategy to format message before sending

    if (!messageStrategy) {
        // Handle no strategy case or assign default
        return; // or set default strategy
    }
    
    string formattedMessage = messageStrategy->formatMessage(message, *this);

    //Create the commands
    Command* sendComms = new SendMessageCommand(chatroom, this, formattedMessage);
    Command* saveComms = new SaveMessageCommand(chatroom, this, formattedMessage);

    addCommand(sendComms);
    addCommand(saveComms);

    executeAll();
    
}

void Users::receive(string message, Users* fromUser, ChatRoom* chatroom) {
    cout << this->name<< " in chatroom "<< chatroom->getName() << " received a message from " << fromUser->name << " in chatroom " << chatroom->getName() << ": " << message << endl;
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

Ezio::Ezio(ChatRoom* chatroom, string name) 
        : Users(chatroom, name) {}

Ezio::~Ezio() {
    // Destructor logic if needed
}

Cole::Cole(ChatRoom* chatroom, string name) 
        : Users(chatroom, name) {}

Cole::~Cole() {
    // Destructor logic if needed
}

Cindy::Cindy(ChatRoom* chatroom, string name) 
        : Users(chatroom, name) {}

Cindy::~Cindy() {
    // Destructor logic if needed
}

void Cindy::joinRoom(ChatRoom* chatroom) {
    // Add the chatroom to Cindy's list and register her in that chatroom
    this->chatrooms.push_back(chatroom);
    chatroom->registerUser(*this);
}