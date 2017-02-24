function figures(varargin)

%This is a function to define the (outer)position of your figures in the
%screen. The function will determine the number of figures and divide them
%over 4 location on the screen.
%Below all figures the function Figures can be called. Figures needs no
%input arguments but a couple can be used to change the appeareance this is
%done by the following flags.
% Menubar   -   The menubar is included by default, exclude using 'None'.
% Toolbar   -   The toolbar has by default the 'Auto' setting, meaning it
%               will be included when the Menubar is and vice versa. But it
%               can be controlled seperately by using 'None' or 'Figure'.
                


p = inputParser;
p.CaseSensitive = false;        % Fuck capitals
defaultMenu = 'figure';
defaultToolbar='auto';
addOptional(p, 'Menubar', defaultMenu);
addOptional(p, 'Toolbar', defaultToolbar);
parse(p, varargin{:})

fig=flipud(findall(0,'type','figure'));
number=length(fig);

set(0,'Units','pixels'); 
scnsize = get(0,'ScreenSize');

fig=flipud(findall(0,'type','figure'));
number=length(fig);
n=35;


pos(:,1) = [0,(scnsize(4)+n)/2,scnsize(3)/2,(scnsize(4)-n)/2];
pos(:,2) = [scnsize(3)/2,(scnsize(4)+n)/2,scnsize(3)/2,(scnsize(4)-n)/2];
pos(:,3) = [0,n,scnsize(3)/2,(scnsize(4)-n)/2];
pos(:,4) = [scnsize(3)/2,n,scnsize(3)/2,(scnsize(4)-n)/2];

for i=1:number;
    b=mod(i-1,4)+1;
    set(fig(i),'OuterPosition',pos(:,b),'Menubar',p.Results.Menubar,'Toolbar',p.Results.Toolbar);
end

end
