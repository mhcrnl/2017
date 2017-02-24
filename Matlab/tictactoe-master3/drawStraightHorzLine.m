function drawStraightHorzLine(boxBegin,boxEnd,box)

plot([box.xMin(boxBegin)+0.5 box.xMax(boxEnd)-0.5],[box.yMax(boxBegin)-1.5 box.yMax(boxEnd)-1.5],'black','LineWidth',2);

end