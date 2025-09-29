#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"
#include "Users.h"
#include "Iterator.h"
#include <string>
using namespace std;

class CtrlCat : public ChatRoom {
    public :
    CtrlCat();
    ~CtrlCat();
    void registerUser (Users& user);
    void sendMessage (string message, Users& fromUser);
    void saveMessage (string message, Users& fromUser);
    void removeUser (Users& user);
    Iterator<Users*>* usersListIterator() override;
    Iterator<string*>* chatHistoryListIterator() override;

};

#endif //CTRLCAT_H
