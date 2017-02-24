function game_out=evaluate_winners(game)

game_out=game;

test_matrix=game.current_board==game.active_player;
player_wins=ismember(3,[sum(test_matrix,1) sum(test_matrix,2)' trace(test_matrix) ...
    sum(test_matrix(size(test_matrix,1):size(test_matrix,1)-1:end-1))]);
game_out.player(game.active_player).won=player_wins;

if ~player_wins & all(~~game.current_board) %Board full, but not winner
    game_out.player(1).won=true;
    game_out.player(2).won=true;
end