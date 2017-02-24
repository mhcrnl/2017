function resultaat = fmlsqAB(x,y,w)
% Kleinste kwadraten berekening volgens y = Ax + B. Geen grafiek, alleen
% output als array
% Versie september 2007; Jelle van der Meulen

% Check errors in data input
if nargin<2
    error('Not enough input arguments: supply two arrays x and y with experimental data as input.');
end

if nargin==2
    disp('(No weigths supplied. All points get same weigth.)');
    w=ones(1,length(x));
end

n=length(x);
if n<3
    error ('Not enough data! Series should have at least 3 data.');
end

if length(y)~=n | length(w)~=n
    error ('Arrays have unequal length!')
end

% Change arrays to rows.
x=x(:).';y=y(:).';w=w(:).';

% Calculation least squares fit y=Ax+B
% Building weight matrix
W=zeros(n,n);
for nw=1:n
    W(nw,nw)=w(nw);
end

% Building model matrix two dimensions
for ng=1:n
     G(ng,1)=1;
     G(ng,2)=x(ng);
end


% Calculating parameter array: inverse method
m=(G.'*W*G)^-1*G.'*W*y.';

% Calculating residuals
ycalc=G*m;
res=y.'-ycalc;
E2=res.'*W*res;

% Calculating statistical error matrix
covm=(E2/(n-2))*(G.'*W*G)^-1;

% Output results A, sA, B, sB
resultaat=[m(2) sqrt(covm(2,2)) m(1) sqrt(covm(1,1))];
    