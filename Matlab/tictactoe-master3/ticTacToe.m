function ticTacToe()

clear all;close all;clc;

% Initialize everything
makeGrid();
user = 0;
totalClicks = 0;
userWinner = inf;
box = struct('boxNumber',[1 2 3 4 5 6 7 8 9],'xMin',[0 0 0 3 3 3 6 6 6],...
    'xMax',[3 3 3 6 6 6 9 9 9],'yMin',[6 3 0 6 3 0 6 3 0],'yMax',[9 6 3 9 6 3 9 6 3],...
    'user',[inf inf inf inf inf inf inf inf inf]);

% Begin game
while(totalClicks < 9)
    
    [x,y,button] = ginput(1);
    if button==1
        boxNum = findBox(x,y,box);
        if user == 0
            [user,box,totalClicks] = drawCirc(boxNum,box,user,totalClicks);
        else
            [user,box,totalClicks] = drawX(boxNum,box,user,totalClicks);
        end
    end
    
    userWinner = checkWinner(box,userWinner);
    if userWinner ~= inf
        msg = msgbox('Winner!');
        break;
    end
    
    if totalClicks == 9
        msg = msgbox('Tie!');
        break;
    end
    
end

pause(2);
close all;
delete(msg);

end