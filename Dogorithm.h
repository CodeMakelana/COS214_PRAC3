#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "Users.h"
#include "Iterator.h"
#include <string>

class Dogorithm : public ChatRoom {
    public:
    Dogorithm();
    ~Dogorithm();
    void registerUser (Users& user);
    void sendMessage (std::string message, Users& fromUser) override;
    void saveMessage (std::string message, Users& fromUser) override;
    void removeUser (Users& user) override;

    Iterator<Users*>* createUsersIterator() override;
    Iterator<std::string*>* createChatHistoryIterator() override;
};

#endif //DOGORITHM_H