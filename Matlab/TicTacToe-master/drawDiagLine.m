function drawDiagLine(boxBegin,boxEnd,box)

plot([box.xMin(boxBegin)+0.5 box.xMax(boxEnd)-0.5],[box.yMax(boxBegin)-0.5 box.yMin(boxEnd)+0.5],'black','LineWidth',2);

end