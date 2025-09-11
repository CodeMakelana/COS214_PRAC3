#ifndef EZIO_H
#define EZIO_H

#include "Users.h"
#include "Dogorithm.h"

class Ezio : public Users {
    public:
    Ezio(ChatRoom* chatroom, std::string name);
    ~Ezio();
};



#endif //EZIO_H
