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
