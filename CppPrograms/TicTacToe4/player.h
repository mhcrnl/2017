#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

const unsigned short int NUMBER_PLAYERS =2;
class Player{
public:
    unsigned short int player_id;
    Player();
    unsigned short int changePlayer();
    char getPlayerMarker() const;
};

#endif // PLAYER_H_INCLUDED
