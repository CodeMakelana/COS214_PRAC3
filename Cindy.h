/**
 * @file Cindy.h
 * @brief 
 * @author Tshepiso Makelana
 * @author Arran Lamond
 * @date 2025-09-29
 */
#ifndef CINDY_H
#define CINDY_H

#include "Users.h"
#include "CtrlCat.h"
#include "Dogorithm.h"


class Cindy : public Users{
    public :
    Cindy(ChatRoom* chatroom, std::string name);
    ~Cindy();

    //for more than 1 chatrooms
    void joinChatRoom(ChatRoom* chatroom);

};



#endif //CINDY_H
