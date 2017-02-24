function game_out=get_next_move(game)

game_out=game;
chosen_square_is_taken=true;

if game.player(game.active_player).is_human
    while chosen_square_is_taken
        s = input('Please, enter next move\n(E.g.: 1 2 means row 1, column 2):\n','s');
        chosen_move=str2num(s);
        if ~isequal(size(chosen_move),[1 2])
            fprintf('Wrong format, please type yourmove again:\n')
        else
            chosen_square_is_taken=game_out.current_board(chosen_move(1),chosen_move(2))~=0;
            if chosen_square_is_taken
                fprintf('The chosen square is taken, pick a new one.\n')
            else
                game_out.current_board(chosen_move(1),chosen_move(2))=game.active_player;
            end
        end
    end
else
    error('AI not implemented')
end
