function [user,box,totalClicks] = drawCirc(boxNum,box,user,totalClicks)

if box.user(boxNum) ~= inf
   msg = msgbox('Click an empty box!');
   pause(1);
   delete(msg);
   return;
end

S = 2500;
scatter(box.xMin(boxNum)+1.5,box.yMin(boxNum)+1.5,S,'o','b');
box.user(boxNum) = user;
totalClicks = totalClicks + 1;

if user == 1
    user = 0;
else
    user = 1;
end

end