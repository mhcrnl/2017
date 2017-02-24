function userWinner = checkWinner(box,userWinner)

% Check 1,2,3
if box.user(1) == 0
    if box.user(2) == 0 && box.user(3) == 0
        userWinner = 0;
        drawStraightVertLine(1,3,box);
        return;
    end
elseif box.user(1) == 1
    if box.user(2) == 1 && box.user(3) == 1
        userWinner = 1;
        drawStraightVertLine(1,3,box);
        return;
    end
end

% Check 4,5,6
if box.user(4) == 0
    if box.user(5) == 0 && box.user(6) == 0
        userWinner = 0;
        drawStraightVertLine(4,6,box);
        return;
    end
elseif box.user(4) == 1
    if box.user(5) == 1 && box.user(6) == 1
        userWinner = 1;
        drawStraightVertLine(4,6,box);
        return;
    end
end

% Check 7,8,9
if box.user(7) == 0
    if box.user(8) == 0 && box.user(9) == 0
        userWinner = 0;
        drawStraightVertLine(7,9,box);
        return;
    end
elseif box.user(7) == 1
    if box.user(8) == 1 && box.user(9) == 1
        userWinner = 1;
        drawStraightVertLine(7,9,box);
        return;
    end
end

% Check 1,4,7
if box.user(1) == 0
    if box.user(4) == 0 && box.user(7) == 0
        userWinner = 0;
        drawStraightHorzLine(1,7,box);
        return;
    end
elseif box.user(1) == 1
    if box.user(4) == 1 && box.user(7) == 1
        userWinner = 1;
        drawStraightHorzLine(1,7,box);
        return;
    end
end

% Check 2,5,8
if box.user(2) == 0
    if box.user(5) == 0 && box.user(8) == 0
        userWinner = 0;
        drawStraightHorzLine(2,8,box);
        return;
    end
elseif box.user(2) == 1
    if box.user(5) == 1 && box.user(8) == 1
        userWinner = 1;
        drawStraightHorzLine(2,8,box);
        return;
    end
end

% Check 3,6,9
if box.user(3) == 0
    if box.user(6) == 0 && box.user(9) == 0
        userWinner = 0;
        drawStraightHorzLine(3,9,box);
        return;
    end
elseif box.user(3) == 1
    if box.user(6) == 1 && box.user(9) == 1
        userWinner = 1;
        drawStraightHorzLine(3,9,box);
        return;
    end
end

% Check 1,5,9
if box.user(1) == 0
    if box.user(5) == 0 && box.user(9) == 0
        userWinner = 0;
        plot([box.xMin(1)+0.5 box.xMax(9)-0.5],[box.yMax(1)-0.5 box.yMin(9)+0.5],'black','LineWidth',2);
        return;
    end
elseif box.user(1) == 1
    if box.user(5) == 1 && box.user(9) == 1
        userWinner = 1;
        plot([box.xMin(1)+0.5 box.xMax(9)-0.5],[box.yMax(1)-0.5 box.yMin(9)+0.5],'black','LineWidth',2);
        return;
    end
end

% Check 3,5,7
if box.user(3) == 0
    if box.user(5) == 0 && box.user(7) == 0
        userWinner = 0;
        plot([box.xMin(3)+0.5 box.xMax(7)-0.5],[box.yMin(3)+0.5 box.yMax(7)-0.5],'black','LineWidth',2);
        return;
    end
elseif box.user(3) == 1
    if box.user(5) == 1 && box.user(7) == 1
        userWinner = 1;
        drawDiagLine(3,7,box);
        plot([box.xMin(3)+0.5 box.xMax(7)-0.5],[box.yMin(3)+0.5 box.yMax(7)-0.5],'black','LineWidth',2);
        return;
    end
end

end