function makeGrid

figure(1);
axis([0 9 0 9]);
set(gca,'XTick',[],'YTick',[]);
box on;
hold on;
plot([3 3],[0 9],'LineWidth',2);
plot([6 6],[0 9],'LineWidth',2);
plot([0 9],[3 3],'LineWidth',2);
plot([0 9],[6 6],'LineWidth',2);
title('TIC-TAC-TOE');

end