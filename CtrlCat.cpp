#include "CtrlCat.h"

CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {
    //initialize the users and chatHistory lists
    users = std::list<Users*>();
    chatHistory = std::list<std::string>();
}

CtrlCat::~CtrlCat() {
    //clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

void CtrlCat::registerUser(Users& user) {
    this->users.push_back(&user);
}

void CtrlCat::sendMessage(std::string mess, Users& fromUser) {
    for (Users* u : this->users) {
        if (u != &fromUser) {
            u->receiveMessage(mess, &fromUser, this);
        }
    }
}

void CtrlCat::saveMessage(std::string mess, Users& fromUser) {
    this->chatHistory.push_back(fromUser.getName() + ": " + mess);
}

void CtrlCat::removeUser(Users& user) {
    this->users.remove(&user);
}