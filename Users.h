/**
 * @file Users.h
 * @brief Header file for User class representing participants in the chat system
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */

#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "ChatRoom.h"
#include "Command.h"  
#include "Strategy.h"   

class Command;

/**
 * @class Users
 * @brief Base class representing users in the PetSpace chat system
 * Users can join multiple chat rooms, send/receive messages, and execute commands.
 * Implements Strategy pattern for message formatting and Command pattern for action execution.
 */
class Users {
    protected: 
    /**
     * @brief Name of the user
     */
    std::string name;
    /**
     * @brief List of chat rooms user has joined
     */
    std::vector<ChatRoom*> chatrooms;
    /**
     * @brief Queue of commands to be executed
     */
    std::vector<Command*> commands;
    /**
     * @brief Strategy for formatting messages
     */
    MessageFormattingStrategy* messageStrategy;

    public:
    /**
     * @brief Constructor for Users
     * @param chatroom Initial chat room to join
     * @param name Name of the user
     */
    Users(ChatRoom* chatroom, std::string name);
    /**
     * @brief Destructor for Users
     */
    virtual ~Users();
    /**
     * @brief Sends a message to a specific chat room
     * @param message The message content to send
     * @param chatroom Pointer to the target chat room
     */
    void send(std::string message, ChatRoom* chatroom);
    /**
     * @brief Receives a message from another user
     * @param message The received message content
     * @param fromUser Pointer to the user who sent the message
     * @param chatroom Pointer to the chat room where message was sent
     */
    void receive(std::string message, Users* fromUser, ChatRoom* chatroom);
    /**
     * @brief Gets the user's name
     * @return std::string The name of the user
     */
    std::string getName() const { return name; }
    /**
     * @brief Adds a command to the execution queue
     * @param command Pointer to the command to add
     */
    void addCommand(Command* command);
    /**
     * @brief Executes all queued commands
     */
    void executeAll();
    /**
     * @brief Sets the message formatting strategy
     * @param strategy Pointer to the new formatting strategy
     */
    void setMessageStrategy(MessageFormattingStrategy* strategy);
    /**
     * @brief Gets the current message formatting strategy
     * @return MessageFormattingStrategy* Pointer to current strategy
     */
    MessageFormattingStrategy* getMessageStrategy();
    /**
     * @brief Allows user to join additional chat rooms
     * @param chatroom Pointer to the chat room to join
     * @note Enables participation in multiple chat rooms simultaneously
     */
    void joinChatRoom(ChatRoom* chatroom);
};

#endif //USERS_H