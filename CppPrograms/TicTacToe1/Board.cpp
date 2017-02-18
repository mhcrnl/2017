#include "Board.h"

Board::Board()
{
	for (int i=0; i<(9*9); i++)
		grid[i/9][i%9] = nothing;

	currentSubgrid = 0;
}

void Board::show()
{
	int a = -1, b = 9;
	for (int i=0 ; i<81 ; i++, b++)
	{
		if (!( i % 3))	{ printf(" ");	a++;	b-=3; }
		if (!( i % 9))	{ printf("\n"); a-=3;	b+=3; }
		if (!( i % 27)) { printf("\n"); a+=3;	b-=9; }

		printf("%c", grid[a][b]);
	}
}

bool Board::play(int space, enum figures figure)
{
	printf("ruch %i:%i:%c\n", currentSubgrid,space,figure);
	if ( currentSubgrid >= 0 && grid[currentSubgrid][space] == nothing )
	{
		grid[currentSubgrid][space] = figure;
		for (int i = 0; i<9; i++)
			if( grid[space][i] == nothing )
			{
				currentSubgrid = space;
				return true;
			}
		return true;
	}
	else return false;
}
