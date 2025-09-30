/**
 * @file Command.h
 * @brief Header file for Command pattern class
 * @author Tshepiso Makelana
 * @author Arran Lamond  
 * @date 2025-09-29
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "ChatRoom.h"
#include "Users.h"

/**
 * @class Command
 * @brief Abstract base class for commands in the Command pattern
 * Provides the interface for executing commands that can be queued and executed
 * by users. Encapsulates actions as objects for flexibility and extensibility.
 */
class Command {

    protected:
    ChatRoom* room;         ///< The chat room where the command will be executed
    Users* fromUser;        ///< The user who initiated the command
    std::string message;    ///< The message content for the command

    public:
    virtual ~Command() {}
    /**
     * @brief Executes the command
     * @return void
     * @note Pure virtual method that is implemented by send and save commands
     */
    virtual void execute() = 0;
};

#endif //COMMAND_H