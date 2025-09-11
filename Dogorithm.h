#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "Users.h"
#include <string>

class Dogorithm : public ChatRoom {
    public:
    Dogorithm();
    ~Dogorithm();
    void registerUser (Users& user);
    void sendMessage (std::string message, Users& fromUser);
    void saveMessage (std::string message, Users& fromUser);
    void removeUser (Users& user);
};



#endif //DOGORITHM_H
