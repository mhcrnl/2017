function [a, s] = myRand2(siruri, coloane, min, max)
% Genereaza numere aleatorii intre min si max.
    a = min+rand(siruri,coloane)*(max-min);
    vector = a(:);
    s =sum(vector);
end