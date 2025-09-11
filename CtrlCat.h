#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include <string>

class CtrlCat : public ChatRoom {
    public :
    CtrlCat();
    ~CtrlCat();
     void registerUser (Users& user);
     void sendMessage (std::string message, Users& fromUser);
     void saveMessage (std::string message, Users& fromUser);
     void removeUser (Users& user);

};



#endif //CTRLCAT_H
