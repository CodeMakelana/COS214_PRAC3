#include "CtrlCat.h"

CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {
    //initialize the users and chatHistory lists
    users = list<Users*>();
    chatHistory = list<string>();
}

CtrlCat::~CtrlCat() {
    //clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

void CtrlCat::registerUser(Users& user) {
    this->users.push_back(&user);
}

void CtrlCat::sendMessage(string mess, Users& fromUser) {
    for (Users* u : this->users) {
        if (u != &fromUser) {
            u->receive(mess, &fromUser, this);
        }
    }
}

void CtrlCat::saveMessage(string mess, Users& fromUser) {
    this->chatHistory.push_back(fromUser.getName() + ": " + mess);
}

void CtrlCat::removeUser(Users& user) {
    this->users.remove(&user);
}

Iterator<Users*>* CtrlCat::usersListIterator() {
    return new UsersIterator<Users>(users);
}

Iterator<std::string*>* CtrlCat::chatHistoryListIterator() {
    return new ChatHistoryIterator(chatHistory);
}

