%% Test xml_read by using weather data from weather channel
node = xml_read('Riverside_Weather_06_25_2015.xml');
clc;
observation = node.history.observations.observation;
% read time stamp and temperature information from node struct
for i = 1:1:length(observation)
    temp(1,i) = str2num(observation{i}.tempi.CONTENT);
    disp([char(observation{i}.date.pretty.CONTENT),blanks(5),observation{i}.tempi.CONTENT]);
end
% plot temperature curve on 06/25/2015
figure; grid on; grid minor; hold on;
plot(temp);
axis([0 length(temp) 50 100]);
