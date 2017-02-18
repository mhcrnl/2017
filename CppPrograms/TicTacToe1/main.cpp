#include <iostream>

#include <time.h>
#include <stdlib.h>
#include "Board.h"

int main(int argc, const char * argv[])
{
	srand((unsigned int)time(NULL));

	Board board;

	for (int i = 0; i < 2; i++)
	{
		while(!board.play(rand() % 9, i % 2 ? cross : circle));
		board.show();
		printf("\n\n");
	}

    return 0;
}
