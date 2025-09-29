#include "Dogorithm.h"

Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {
    //initialize the users and chatHistory lists
    users = list<Users*>();
    chatHistory = list<string>();
}

Dogorithm::~Dogorithm() {
    //clear the users and chatHistory lists
    users.clear();
    chatHistory.clear();
}

void Dogorithm::registerUser(Users& user) {
    this->users.push_back(&user);
}

void Dogorithm::sendMessage(string mess, Users& fromUser) {
    for (Users* u : this->users) {
        if (u != &fromUser) {
            u->receive(mess, &fromUser, this);
        }
    }
}

void Dogorithm::saveMessage(string mess, Users& fromUser) {
    this->chatHistory.push_back(fromUser.getName() + ": " + mess);
}

void Dogorithm::removeUser(Users& user) {
    this->users.remove(&user);
}

Iterator<Users*>* Dogorithm::usersListIterator() {
    return new UsersIterator<Users>(users);  // Pass the class type, not pointer type
}

Iterator<std::string*>* Dogorithm::chatHistoryListIterator() {
    return new ChatHistoryIterator(chatHistory);
}
