#include "Dogorithm.h"

Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {
    //initialize the users and chatHistory lists
    users = std::list<Users*>();
    chatHistory = std::list<std::string>();
}

Dogorithm::~Dogorithm() {
    //clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

void Dogorithm::registerUser(Users& user) {
    this->users.push_back(&user);
}

void Dogorithm::sendMessage(std::string mess, Users& fromUser) {
    for (Users* u : this->users) {
        if (u != &fromUser) {
            u->receive(mess, &fromUser, this);
        }
    }
}

void Dogorithm::saveMessage(std::string mess, Users& fromUser) {
    this->chatHistory.push_back(fromUser.getName() + ": " + mess);
}

void Dogorithm::removeUser(Users& user) {
    this->users.remove(&user);
}

Iterator<Users*>* Dogorithm::createUsersIterator() {
    return new UsersIterator<Users>(users);  // Pass the class type, not pointer type
}

Iterator<std::string*>* Dogorithm::createChatHistoryIterator() {
    return new ChatHistoryIterator(chatHistory);  // FIXED: No template syntax
}