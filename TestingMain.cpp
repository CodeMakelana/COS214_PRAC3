#include <iostream>

#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Cindy.h"
#include "Ezio.h"
#include "Cole.h"
#include "ChatRoom.h"
#include "Users.h"

int main() {
    //Testing the mediator pattern.

    //create the chatrooms

    ChatRoom* Catroom = new CtrlCat();
    ChatRoom* DogRoom = new Dogorithm();

    //Create users
    Cindy* cindy = new Cindy(Catroom, "Cindy");
    cindy->joinChatRoom(DogRoom); //since Cindy is aprt of 2 chatrooms

    //users in single rooms
    Ezio* ezio = new Ezio(DogRoom, "Ezio");
    Cole* cole = new Cole(Catroom, "Cole");

    //egister the users (join them in the chatrooms)
    // Catroom->registerUser(*cindy);
    // Catroom->registerUser(*cole);
    // DogRoom->registerUser(*ezio);

    ezio->sendMessage("Hello", DogRoom);
    cole->sendMessage("My cat is the best", Catroom);
    cindy->sendMessage("I love dogs", DogRoom);
    cindy->sendMessage("I love cats", Catroom);
    return 0;
    
}