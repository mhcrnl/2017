#!/usr/bin/env python
''' Tic-tac-toe game.
Usage: In a terminal, write:
python play_tictactoe.py [AI_player]
The optional argument AI_player (default value: 0) is the player number of the
AI. AI is is currently unsupported.
When playing, just follow the screen instructions.'''

import numpy as np
#import sys


def init_game(with_AI):
    game = dict()
    game['player'] = {}
    game['player']['is_human'] = np.ones(2).astype('bool')
    game['player']['won'] = np.zeros(2).astype('bool')
    game['active_player'] = -1  # none so far
    game['current_board'] = np.zeros((3, 3)).astype('int')
    if with_AI != 0:
        game['player']['is_human'][with_AI-1] = False
    return game


def show_board(game):
    symbols = np.array([' ', 'X', 'O'])
    brd = game['current_board']
    board_str = '{} | {} | {}\n----------\n'
#    print(chr(27) + "[2J") # clear python console
#    os.system('clear')
    np.sys.stdout.write("\x1b[2J\x1b[H")  # ANSI escape sequence
    np.sys.stdout.write('Tic-tac-toe\n')
    np.sys.stdout.write('Active player: {}\n\n'.format(game['active_player']+1))
    for idx in range(brd.shape[0]):
        np.sys.stdout.write(board_str.format(*symbols[brd[idx, :]]))
#        sys.stdout.write(board_str.format(*brd[idx, :]))


def get_next_move(game):
    chosen_square_is_taken = True
    if game['player']['is_human'][game['active_player']]:
        while chosen_square_is_taken:
            np.sys.stdout.write(
             'Please, enter next move, zero-based \n(E.g.: 1 2 means second row, third column):\n')
            user_input = np.sys.stdin.readline()
            chosen_move = np.array(user_input.split(' ')).astype('int')
            if chosen_move.shape != (2,) or -(np.all(chosen_move >= 0) &
               np.all(chosen_move < 3)):
                np.sys.stdout.write(
                 'Your move was in the wrong format, pick a new one.\n')
            else:
                chosen_square_is_taken = game['current_board'][chosen_move[0], chosen_move[1]] != 0
                if chosen_square_is_taken:
                     np.sys.stdout.write('The chosen square is taken, pick a new one.\n')
                else:
                    game['current_board'][chosen_move[0], chosen_move[1]] = game['active_player'] + 1
    else:
        empty_squares = zip(*np.where(game['current_board']==0))
        chosen_move = empty_squares[np.random.randint(0,len(empty_squares)+1)]
        game['current_board'][chosen_move] = game['active_player'] + 1
#        raise UserWarning('AI not implemented')


def evaluate_winners(game):
    a = game['current_board'] == (game['active_player']+1)
    anti_diag = a[0, 2].astype(int) + a[1, 1].astype(int) + a[2, 0].astype(int)
    player_wins = np.in1d(3, np.hstack((
     a.sum(axis=0), a.sum(axis=1), a.trace(), anti_diag)))
    game['player']['won'][game['active_player']] = player_wins
    if -player_wins and np.all(game['current_board']):
        game['player']['won'] = np.ones(2).astype('bool')


def display_winner(game):
    if -np.any(game['player']['won']):
        np.sys.stdout.write(
         'Funny, I would have sweared someone had won, but nope\n')
    elif np.all(game['player']['won']):
        np.sys.stdout.write('Well, it was a draw, good for you both.\n')
    else:
        np.sys.stdout.write('Congratulations, player {}, you won!\n'.format(
         np.nonzero(game['player']['won'])[0][0]+1))


if len(np.sys.argv) > 2:
    raise UserWarning('Too many input arguments')
elif len(np.sys.argv) == 2:
    if int(np.sys.argv[1]) == 1 or int(np.sys.argv[1]) == 2:
        with_AI = int(np.sys.argv[1])
    else:
        with_AI = 0
else:
    with_AI = 0


# if with_AI:
#     raise UserWarning('AI not implemented')
# else:
#     game = init_game(with_AI)
game = init_game(with_AI)

while -np.any(game['player']['won']):
    game['active_player'] = np.mod(game['active_player'] + 1, 2)
    show_board(game)
    get_next_move(game)
    evaluate_winners(game)

show_board(game)
display_winner(game)
