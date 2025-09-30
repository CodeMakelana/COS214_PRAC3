/**
 * @file Ezio.h
 * @brief Header file for Ezio user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef EZIO_H
#define EZIO_H

#include "Users.h"
#include "ChatRoom.h"

/**
 * @class Ezio
 * @brief Concrete user class representing Ezio in the PetSpace chat system
 * Ezio is a specific user who inherits all functionality from the base Users class
 * and can participate in chat rooms with potential specialized behavior.
 */
class Ezio : public Users {
public:
    /**
     * @brief Constructor for Ezio user
     * @param chatroom Pointer to the initial chat room to join
     * @param name The name of the user
     */
    Ezio(ChatRoom* chatroom, std::string name);
    /**
     * @brief Destructor for Ezio user
     */
    ~Ezio();
};

#endif //EZIO_H