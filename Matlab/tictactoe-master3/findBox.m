function num = findBox(x,y,box)

for i = box.boxNumber
    if (x>box.xMin(i) && x<box.xMax(i) && y>box.yMin(i) && y<box.yMax(i))
        num = i;
        return;
    end
end

end