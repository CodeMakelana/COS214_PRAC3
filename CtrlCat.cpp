#include "CtrlCat.h"

CtrlCat::CtrlCat() {
    //initialize the users and chatHistory lists
    users = std::list<Users*>();
    chatHistory = std::list<std::string>();
}

CtrlCat::~CtrlCat() {
    //clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

void CtrlCat::registerUser(User user) {
    this.users.add(user);
}

void CtrlCat::sendMessage(std::string mess, User fromUser) {
    for (User u : this.users) {
        if (u != fromUser) {
            u.receiveMessage(mess, fromUser, this);
        }
    }
}

void CtrlCat::saveMessage(std::string mess, User fromUser) {
    this.chatHistory.add(fromUser.getName() + ": " + mess);
}

void CtrlCat::removeUser(User user) {
    this.users.remove(user);
}