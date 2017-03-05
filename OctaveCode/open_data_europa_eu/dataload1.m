#! /usr/bin/octave -qf

filename = uigetfile;

A = dlmread(filename, '\t');
A

RO2004_2015 = A(25, 2:13);
RO2004_2015
y = 2004:2015;
y
graphics_toolkit("fltk");
bar(y,RO2004_2015);

f = figure;
c= uicontextmenu(f);
b1 = uicontrol(f, "string", "A Button", "position", [10 10 150 40]);

set(f,'uicontextmenu', c);
pause;
