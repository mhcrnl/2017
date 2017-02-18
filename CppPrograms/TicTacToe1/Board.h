#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <stdio.h>

enum figures {
	nothing = '-',
	cross = 'x',
	circle = 'o'
};

class Board
{
private:
	enum figures grid[9][9];
	int currentSubgrid;

public:
	Board();
	void show();
	bool play(int space, enum figures figure);
};


#endif // BOARD_H_INCLUDED
