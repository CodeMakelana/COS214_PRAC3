/**
 * @file Cole.h
 * @brief 
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef COLE_H
#define COLE_H

#include "Users.h"
#include "ChatRoom.h"

class Cole : public Users {
    public:
    Cole(ChatRoom* chatroom, std::string name);
    ~Cole();
};



#endif //COLE_H
