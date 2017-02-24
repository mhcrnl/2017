function resultaat = fmlsqB(x,y,helling,w)
% Kleinste kwadraten fit volgens y = Ax + B met vaste helling.
% Versie september 2007; Jelle van der Meulen

% Check errors in data input
if nargin<3
    error('Not enough input arguments: supply arrays x and y + value of slope');
end

if nargin==3
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

% Calculation least squares fit y=Ax+B; A is fixed
% Building weigth array
W=zeros(n,n);
for nw=1:n
    W(nw,nw)=w(nw);
end

% Building model matrix one dimension
G=ones(n,1);

y=y-helling*x;
% Calculating parameter array: inverse method
m=(G.'*W*G)^-1*G.'*W*y.';

% Calculating residuals
ycalc=G*m;
res=y.'-ycalc;
E2=res.'*W*res;

% Calculating statistical error matrix
covm=(E2/(n-1))*(G.'*W*G)^-1;

% Output results A, sA, B, sB
resultaat=[helling 0 m sqrt(covm)];
