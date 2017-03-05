#! /usr/bin/octave -qf

% Incarca datele din fila ex1data1.txt

data = load("ex1data1.txt");
x = data(:, 1);
y = data(:, 2);
m = length(y)
plot(x,y, "rx", "MarkerSize", 10);
% figure;
pause;


