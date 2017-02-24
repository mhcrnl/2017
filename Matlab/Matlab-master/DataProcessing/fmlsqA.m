function resultaat = fmlsqA(x,y,w)
% Kleinste Kwadraten fit volgens y = Ax. Geen grafiek, output in array
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
if n<2
    error ('Not enough data! Series should have at least 2 data.');
end

if length(y)~=n | length(w)~=n
    error ('Arrays have unequal length!')
end

% Change to rows.
x=x(:).';y=y(:).';w=w(:).';

% Calculation least squares fit y=Ax
% Building weight matrix
W=zeros(n,n);
for wn=1:n
    W(wn,wn)=w(wn);
end

% Building model matrix one dimension
G=x.';

% Calculating parameter array: inverse method
m=(G.'*W*G)^-1*G.'*W*y.';

% Calculating residuals
ycalc=G*m;
res=y.'-ycalc;
E2=res.'*W*res;

% Calculating statistical error matrix
covm=(E2/(n-1))*(G.'*W*G)^-1

% Output results A, sA, B, sB
resultaat=[m sqrt(covm) 0 0];
