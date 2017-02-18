#include <iostream>

using namespace std;

void display_board();
bool spaceEmpty(int row, int col);
bool boardHasSpace();
bool playerHasWon();
int checkRows();
int checkColumns();
int checkDiagonals();

const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'O';

char turn;
bool draw = false;
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

int main() {

    cout << "Tic Tac Toe Game\n";
    cout << "Player 1 [X] --- Player 2 [O]\n";
    int moves = 0;
    int position;
    bool validMove = false;
    int row, col;
    while (!playerHasWon() && boardHasSpace()) {
        display_board();
        validMove = false;
        switch (moves % 2) {
            case 0:
                do {
                    cout << "Player 1 > ";
                    cin >> position;
                    row = (position - 1) / 3;
                    col = (position - 1) % 3;

                    if (spaceEmpty(row, col)) {
                        board[row][col] = PLAYER_ONE;
                        validMove = true;
                    }
                    else {
                        cout << "Cannot place piece there." << endl << endl;
                    }
                } while (!validMove);
                break;
            case 1:
                do {
                    cout << "Player 2 > ";
                    cin >> position;
                    row = (position - 1) / 3;
                    col = (position - 1) % 3;

                    if (spaceEmpty(row, col)) {
                        board[row][col] = PLAYER_TWO;
                        validMove = true;
                    }
                    else {
                        cout << "Cannot place piece there." << endl << endl;
                    }
                } while (!validMove);
                break;
        }
        cout << endl;
        moves++;
    }
    return 0;
}

bool spaceEmpty(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;
    return board[row][col] != PLAYER_ONE && board[row][col] != PLAYER_TWO;
}

bool boardHasSpace() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != PLAYER_ONE && board[i][j] != PLAYER_TWO)
                return true;
        }
    }
    return false;
}

bool playerHasWon() {
    if (checkRows() >= 0) {
        int row = checkRows();
        cout << (board[row][0] ==  PLAYER_ONE ? "Player 1 won!" : "Player 2 won!") << endl;
        return true;
    }
    if (checkColumns() >= 0) {
        int col = checkColumns();
        cout << (board[0][col] ==  PLAYER_ONE ? "Player 1 won!" : "Player 2 won!") << endl;
        return true;
    }
    if (checkDiagonals() >= 0) {
        cout << (board[1][1] ==  PLAYER_ONE ? "Player 1 won!" : "Player 2 won!") << endl;
        return true;
    }
    if (!boardHasSpace()) {
        cout << "It's a draw!" << endl;
        return true;
    }
    return false;
}

int checkRows() {
    int i, j;
    char check;
    bool matchFound;
    for (i = 0; i < 3; i++) {
        matchFound = true;
        check = board[i][0];
        if (check != PLAYER_ONE && check != PLAYER_TWO)
            return -1;
        for (j = 1; j < 3; j++) {
            matchFound = matchFound && check == board[i][j];
        }
        if (matchFound) {
            return i;
        }
    }
    return -1;
}

int checkColumns() {
    int i, j;
    char check;
    bool matchFound;
    for (i = 0; i < 3; i++) {
        matchFound = true;
        check = board[0][i];
        if (check == ' ')
            return -1;
        for (j = 1; j < 3; j++) {
            matchFound = matchFound && check == board[j][i];
        }
        if (matchFound) {
            return i;
        }
    }
    return -1;
}

int checkDiagonals() {
    char check = board[1][1];
    if (check == board[0][0] && check == board[2][2])
        return 0;
    if (check == board[0][2] && check == board[2][0])
        return 1;
    return -1;
}

void display_board() {
    cout << "---------------------" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl << endl;
}
