#include <iostream>
#include "player.h"
Player::Player(){
    player_id =1;
}
unsigned short int Player::changePlayer(){
    if(++player_id>NUMBER_PLAYERS){
        player_id=1;
    }
    return player_id;
}
char Player::getPlayerMarker() const{
    if(player_id==1)
    {
        return 'X';
    }
    return 'O';
}
