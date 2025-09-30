/**
 * @file Cindy.h
 * @brief Header file for Cindy user class
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef CINDY_H
#define CINDY_H

#include "Users.h"
#include "CtrlCat.h"
#include "Dogorithm.h"

/**
 * @class Cindy
 * @brief Concrete user class representing a specific user in the PetSpace chat system
 * @note Cindy is a user who can join multiple chat rooms and participate in conversations.
 * @note This class demonstrates user specialization and multi-chatroom participation.
 */
class Cindy : public Users{
    public:
    /**
     * @brief Constructor for Cindy user
     * @param chatroom Pointer to the initial chat room to join
     * @param name The name of the user
     */
    Cindy(ChatRoom* chatroom, std::string name);

    /**
     * @brief Destructor for Cindy user
     */
    ~Cindy();

};



#endif //CINDY_H
