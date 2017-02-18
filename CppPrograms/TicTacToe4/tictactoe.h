#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#include "player.h"
class TicTacToe{
private:
    unsigned short int position[9];
    //char position[9];
    unsigned short int player;
    unsigned short int total_turns;
public:
    TicTacToe();
    void drawBoard() const;
    bool isTie() const;
    void makeMove(Player& current_player);
    unsigned short int nextTurn(Player& current_player);
};

#endif // TICTACTOE_H_INCLUDED
