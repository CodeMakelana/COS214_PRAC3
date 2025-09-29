/**
 * @file Ezio.h
 * @brief 
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef EZIO_H
#define EZIO_H

#include "Users.h"
#include "ChatRoom.h"

class Ezio : public Users {
    public:
    Ezio(ChatRoom* chatroom, std::string name);
    ~Ezio();
};

#endif //EZIO_H