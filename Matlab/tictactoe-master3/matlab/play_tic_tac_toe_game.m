function play_tic_tac_toe_game(with_AI)

% play_tic_tac_toe_game : play a game of tic-tac-toe in command line
% 
% INPUTs: with_AI: 0 for 2 human player game, 1 for player 1 as AI, 2 for player 2 as AI

if with_AI
    error('AI not implemented')
else game.player(1).is_human=1;
     game.player(1).won=0;
     game.player(2).is_human=1;
     game.player(2).won=0;
end

game.active_player=0;
game.current_board=zeros(3);

while ~any([game.player.won])
    game.active_player=mod(game.active_player,2)+1;
    show_board(game);
    game=get_next_move(game);
    game=evaluate_winners(game);
    show_board(game);
end

display_winner(game)