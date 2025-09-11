#include "Dogorithm.h"

Dogorithm::Dogorithm() {
    //initialize the users and chatHistory lists
    users = std::list<Users*>();
    chatHistory = std::list<std::string>();
}

Dogorithm::~Dogorithm() {
    //clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

void Dogorithm::registerUser(User user) {
    this.users.add(user);
}

void Dogorithm::sendMessage(std::string mess, User fromUser) {
    for (User u : this.users) {
        if (u != fromUser) {
            u.receiveMessage(mess, fromUser, this);
        }
    }
}

void Dogorithm::saveMessage(std::string mess, User fromUser) {
    this.chatHistory.add(fromUser.getName() + ": " + mess);
}

void Dogorithm::removeUser(User user) {
    this.users.remove(user);
}
