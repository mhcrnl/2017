function [a, s] = myRand(min, max)
% Genereaza numere aleatorii intre min si max.
    a = min+rand(3,4)*(max-min);
    vector = a(:);
    s =sum(vector);
end