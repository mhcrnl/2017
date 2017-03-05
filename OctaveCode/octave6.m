#! /usr/bin/octave -qf

x = linspace(0, 2*pi, 100);
y = sin(x);

x1= [ 2 3 4 5 6 78];
suma =0;
for var= x
	suma = suma + var;
endfor
disp('Media este')
disp(suma / length(x1))

plot(x,y);
% figure;
pause;
