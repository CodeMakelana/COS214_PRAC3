/**
 * @file Cole.h
 * @brief Header file for Cole user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef COLE_H
#define COLE_H

#include "Users.h"
#include "ChatRoom.h"

/**
 * @class Cole
 * @brief Concrete user class representing Cole in the PetSpace chat system
 * Cole is a specific user who inherits all functionality from the base Users class
 * and can participate in chat rooms with specialized behavior if needed.
 */
class Cole : public Users {
    public:
    /**
     * @brief Constructor for Cole user
     * @param chatroom Pointer to the initial chat room to join
     * @param name The name of the user
     */
    Cole(ChatRoom* chatroom, std::string name);
    /**
     * @brief Destructor for Cole user
     */
    ~Cole();
};



#endif //COLE_H
