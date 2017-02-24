function display_winner(game)

if ~any([game.player.won])
    fprintf('Funny, I would have sweared someone had won, but no!\n')
elseif all([game.player.won])
    fprintf('Well, it was a draw, good for you both.\n')
else
    fprintf('Congratulations, player %s, you won!\n',num2str(find([game.player.won])))
end