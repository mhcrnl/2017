/**
    TicTacToe4 - game -https://github.com/mattkirwan/cli-ttt
    @author Mihai Cornel
    @date 18.02.2017
    @mail mhcrnl@gmail.com
*/
#include <iostream>
#include "tictactoe.h"
#include "player.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    TicTacToe Game;
	Player CurrentPlayer;

	Game.drawBoard();

	do
	{
		Game.makeMove(CurrentPlayer);
		Game.drawBoard();
		Game.nextTurn(CurrentPlayer);
	} while( !Game.isTie() );
    return 0;
}
