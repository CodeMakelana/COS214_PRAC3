#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include  "Iterator.h"
#include <string>

class CtrlCat : public ChatRoom {
    public :
    CtrlCat();
    ~CtrlCat();
    void registerUser (Users& user);
    void sendMessage (std::string message, Users& fromUser) override;
    void saveMessage (std::string message, Users& fromUser) override;
    void removeUser (Users& user) override;

    Iterator<Users*>* createUsersIterator() override;
    Iterator<std::string*>* createChatHistoryIterator() override;

};

#endif //CTRLCAT_H
