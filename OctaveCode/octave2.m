#! /usr/bin/octave -qf

%A = xlsread('CF201603.xls', 'macheta raportarii', 'C5:C20');

A=[1:3; 4:6; 7:9];
save mufile.xlsx A

%B = xlsread('mufile.xls','mufile', 'A6:A8');
 load mufile.xlsx
 A
 
%status = xlswrite('test4.xls', 'arr', 'Third_sheet', 'C3:AB40');
%status;

%raw_data = xls2oct (<fileptr> [,sheet#] [,cellrange] [,options])

B = xls2oct('mufile.xlsx', 'mufile', 'A1:A8');
B

3+3
