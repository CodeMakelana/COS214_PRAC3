#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"
#include "Users.h"
#include "Iterator.h"
#include <string>
using namespace std;

class Dogorithm : public ChatRoom {
    public:
    Dogorithm();
    ~Dogorithm();
    void registerUser (Users& user);
    void sendMessage (string message, Users& fromUser);
    void saveMessage (string message, Users& fromUser);
    void removeUser (Users& user);
    Iterator<Users*>* usersListIterator() override;
    Iterator<string*>* chatHistoryListIterator() override;
};

#endif //DOGORITHM_H
