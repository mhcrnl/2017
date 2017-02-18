#include <iostream>
#include <string>
#include "tictactoe.h"
#include "player.h"

TicTacToe::TicTacToe(){
    total_turns =0;
    for(int i=0; i<9; i++){
        position[i]='0';
    }
}
void TicTacToe::drawBoard() const
{
	std::cout << std::endl;
	std::cout << "          \n";
	std::cout << "          " << position[0] << "|" << position[1] << "|" << position[2];
	std::cout << "\n          -|-|-\n";
	std::cout << "          " << position[3] << "|" << position[4] << "|" << position[5];
	std::cout << "\n          -|-|-\n";
	std::cout << "          " << position[6] << "|" << position[7] << "|" << position[8];
	std::cout << "\n\n\n";
}
bool TicTacToe::isTie() const
{
	if(total_turns == 9)
	{
		std::cout << "Game ties! Your both losers.\n";
		return true;
	}

	return false;
}

void TicTacToe::makeMove(Player &current_player)
{
	std::cout << "Make your move player " << current_player.player_id << ":";

	int player_move;

	do
	{
		std::cin >> player_move;
		player_move--;
	}
	while(player_move < 0 || player_move > 8 || position[player_move] != 0);

	position[player_move] = current_player.getPlayerMarker();
}

unsigned short int TicTacToe::nextTurn(Player &current_player)
{
	total_turns++;

	return current_player.changePlayer();
}
