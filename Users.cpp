/**
 * @file Users.cpp
 * @brief Implementation file of Users class methods
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#include "Users.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"

/**
 * @brief Constructs a new Users object
 * @param chatroom Initial chat room to join
 * @param name Name of the user
 */
Users::Users(ChatRoom* chatroom, std::string name) {
    this->name = name;
    this->messageStrategy = new PlainTextStrategy(); // Assign default strategy
    std::cout << "User " << name << " is waiting to join a chatroom." << std::endl;
    this->chatrooms.push_back(chatroom);
    for (ChatRoom* cr : chatrooms) {
        cr->registerUser(*this);
    }
}

/**
 * @brief Destroys the Users object and cleans up resources
 */
Users::~Users() {
    for (ChatRoom* cr : chatrooms) {
        cr->removeUser(*this);
    }

    // Clean up strategy
    if (messageStrategy) {
        delete messageStrategy;
        messageStrategy = nullptr;
    }
}

/**
 * @brief Sends a message to a chat room using Command pattern
 * @param message The message content to send
 * @param chatroom Pointer to the target chat room
 */
void Users::send(std::string message, ChatRoom* chatroom) {
    if (!messageStrategy) {
        return; // Handle no strategy case
    }
    
    std::string formattedMessage = messageStrategy->formatMessage(message, *this);

    // Create the commands
    Command* sendComms = new SendMessageCommand(chatroom, this, formattedMessage);
    Command* saveComms = new SaveMessageCommand(chatroom, this, formattedMessage);

    addCommand(sendComms);
    addCommand(saveComms);

    executeAll();
}

/**
 * @brief Receives a message from another user
 * @param message The received message content
 * @param fromUser Pointer to the user who sent the message
 * @param chatroom Pointer to the chat room where message was sent
 */
void Users::receive(std::string message, Users* fromUser, ChatRoom* chatroom) {
    std::cout << this->name<< " in chatroom "<< chatroom->getName() << " received a message from " << fromUser->name << " in chatroom " << chatroom->getName() << ": " << message << std::endl;
    chatroom->saveMessage(message, *fromUser);
}

/**
 * @brief Adds a command to the execution queue
 * @param command Pointer to the command to add
 */
void Users::addCommand(Command* command) {
    this->commands.push_back(command);
}

/**
 * @brief Executes all queued commands and cleans up
 */
void Users::executeAll() {
    for (Command* cmd : commands) {
        cmd->execute();
        delete cmd;
    }
    commands.clear();
}

/**
 * @brief Sets the message formatting strategy
 * @param strategy Pointer to the new formatting strategy
 */
void Users::setMessageStrategy(MessageFormattingStrategy* strategy) {
    if (messageStrategy) {
        delete messageStrategy;
    }
    messageStrategy = strategy;
}

/**
 * @brief Gets the current message formatting strategy
 * @return MessageFormattingStrategy* Pointer to current strategy
 */
MessageFormattingStrategy* Users::getMessageStrategy() {
    return messageStrategy;
}