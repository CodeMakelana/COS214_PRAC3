#include <iostream>


int main() {
    //Testing the mediator pattern.

    //create the chatrooms

    ChatRoom* Catroom = new CtrlCat();
    ChatRoom* DogRoom = new Dogorithm();

    //Create users
    Cindy* cindy = new Cindy(Catroom, "Cindy");
    cindy->joinChatRoom(Dogroom); //since Cindy is aprt of 2 chatrooms

    //users in single rooms
    Ezio* ezio = new Ezio(DogRoom, "Ezio");
    Cole* cole = new Cindy(Catroom, "Cole");

    //egister the users (join them in the chatrooms)
    Catroom->registerUser(cindy);
    Catroom->registerUser(cole);
    DogRoom->registerUser(ezio);

    ezio->sendMessage("Hello", DogRoom);
    return 0;
    
}