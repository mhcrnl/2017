#!/usr/bin/octave -qf
% --------------------------------------------------------------------------------------------------------------
% The trade balance of energy products is calculated, for each Member State, as the difference between exports to    % and imports from the rest of the world (intra-EU and extra-EU trade) of goods included in the SITC section 3 
% Mineral fuels, lubricants and related materials.The MIP indicator is expressed as percentage of GDP (accordi       % ESA2010 transmission programme)
% http://ec.europa.eu/eurostat/tgm/table.do?tab=table&init=1&language=en&pcode=tipsen10&plugin=1
%-------------------------------------------------------------------------------------------------------------

global filename = 'tipsen10.tsv';

% a = fileread(filename);
% a;
% Se citeste intreaga fila in variabila A 
A = dlmread(filename, '\t');
% Se extrage coloana 1
A2004 = A(:,2);
A2004
A2005 = A(:,3);
A2005

RO2004_2015 = A(25, 2:13);
RO2004_2015

plot(A(:,2), A(:,3));
pause;

a2014 = dlmread(filename,'\t', 2,  11);
a2014;
a2014(:,1);
plot(a2014(:,2), a2014(:,1))
%figure;
 pause;
