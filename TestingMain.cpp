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

    ezio->send("Hello", DogRoom);
    cole->send("My cat is the best", Catroom);
    cindy->send("I love dogs", DogRoom);
    cindy->send("I love cats", Catroom);
    return 0;
    
}