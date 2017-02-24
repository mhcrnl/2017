function z = Process(varargin)
% Process() is a function designed to make consistent image processing
% easy and nice. It should be used by calling it after plotting an image.
% Required additions as labels, legenda etc should be added before calling
% this function. When ready Process can be called. The function creates
% two images. A .fig file as backup when the layout of images is not
% fullfilling and a .pdf file which can be used in reports. A folder
% "figures" is created in which the pdf-files are stored. It contains a
% subfolder fig which contains the fig-files.
%
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%%                             Usage                                %%%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Process needs no input arguments although it is probably neccesary to add
% some. There are various chaging parameters which can be changed using the
% flags:
% title     -   The filename under which the images are stored
% height    -   The image height
% widht     -   The image widht
% fontsize  -   The fontsize of labels, legenda entries etc.
% autocut   -   Autocutting the image leaving 10% margin on all sides.

% Example:
% Process('title', 'Excellent plot', 'height', 100, 'width', 161)


p = inputParser;
p.CaseSensitive = false;        % Fuck capitals
defaultHeight = 10;            % Default image height
defaultWidth = 16.1;             % Default image width (based on phi)
defaultFontSize = 15;           % Used fontsize (labels)
defaultFontSizeLegend=13;
defaultFontSizeTitle=18;
defaultAutoCut = false;
defaultFileName = 'Awesome plot by Jaap';
defaultTitle = '';
defaultGrid = 'off';
addOptional(p, 'width',  defaultWidth, @isnumeric);
addOptional(p, 'height', defaultHeight, @isnumeric);
addOptional(p, 'fontsize', defaultFontSize, @isnumeric);
addOptional(p, 'fontsizelegend', defaultFontSizeLegend, @isnumeric);
addOptional(p, 'fontsizetitle', defaultFontSizeTitle, @isnumeric);
addOptional(p, 'filename', defaultFileName);
addOptional(p, 'autoCut', defaultAutoCut); %add boolean check
addOptional(p, 'title', defaultTitle);
addOptional(p, 'grid', defaultGrid);
parse(p, varargin{:})

%% creating save structure and backup file
if exist('figures/fig', 'dir') ~= 7   %checks if apropriate folder exists
    mkdir(strcat('figures', filesep, 'fig'));
end
    saveas(gcf, fullfile('figures', filesep,...
    'fig',filesep, p.Results.filename), 'fig'); %saving backup fig


%% Initializing defaults
GraphLineWidth = 3;         % The linewidth of the graph lines
MarkerSize = 10;            % The size of the markers
margin = 0.1;               % Margin around the info
FontName = 'Helvetica';     % Fonttype, chosen semi freely (only a couple are supported)
FontWeight = 'Bold';        % [light normal, demi, bold]
fontColor = 0.0*ones(1,3);  % 0 is black 1 is white
axisColor = 0.0*ones(1,3);  % 0 is black 1 is white

%% Setting title
if ~isempty(p.Results.title)
    title(p.Results.title)
end

%% Changing figure borders and grid
set(gca,'Xgrid',p.Results.grid,'Ygrid',p.Results.grid)     % Turns the grid off (prefered by most editors)
box on                  % Turns box on
GridLineStyle = '--';   % [-, --, :, -., none] not in use when grid is off
LineWidth = 1;          % Thickness of the axis and grid.

%% autocutting image
h_line = findobj(gcf, 'type', 'line');

if p.Results.autoCut && ~isempty(h_line)
    xmin = min([h_line.XData]);
    ymin = min([h_line.YData]);
    zmin = min([h_line.ZData]);
    xmax = max([h_line.XData]);
    ymax = max([h_line.YData]);
    zmax = max([h_line.ZData]);
    cutoffX = [xmin-margin*(xmax-xmin), xmax + margin*(xmax-xmin)];
    cutoffY = [ymin-margin*(ymax-ymin), ymax + margin*(ymax-ymin)];
    cutoffZ = [zmin-margin*(zmax-zmin), zmax + margin*(zmax-zmin)];
    
    axis([cutoffX, cutoffY cutoffZ]);

end

%% Adjusting canvas
set(gcf,...
    'PaperUnits', 'centimeters',...
    'PaperPosition', [0, 0, p.Results.width, p.Results.height]',...
    'PaperSize', [p.Results.width, p.Results.height],...
    'KeyPressFcn', 'close');

%% Lines and Marker makeup
set(h_line,...
    'LineWidth', GraphLineWidth,...
    'MarkerSize', MarkerSize)

set(gca,...
    'LineWidth', LineWidth,...
    'GridLineStyle', GridLineStyle,...
    'FontSize', floor(p.Results.fontsize/1.5+1),...
    'fontWeight', FontWeight,...
    'FontName', FontName,...
    'XColor', axisColor,...
    'YColor', axisColor);

%% Label makeup
labels = {'XLabel', 'YLabel', 'ZLabel', 'Title'};
h_labels = get(gca, labels);
set([h_labels{:}],...
    'FontSize', p.Results.fontsize,...
    'FontWeight', FontWeight,...
    'FontName', FontName,...
    'Color', fontColor);
set(h_labels{4},'FontSize', p.Results.fontsizetitle);

figure = get(gca, 'Parent');
children = get(figure, 'Children');
legend = findobj(children, 'Type', 'Legend');

if ~isempty(legend)
%     legend.Position(1) = 0.90; 
% Nico: This places the legend out of scope. I do not know what the
% original purpose was, but would recommend using Location instead of
% Position.
    set(legend,'FontSize',p.Results.fontsizelegend)
end

saveas(gcf, fullfile('figures', p.Results.filename), 'pdf') %Saves the image as pdf in the figures folder

end