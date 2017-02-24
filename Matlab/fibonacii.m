function f = fibonacci(n)
 if (n==1)
     f= 1;
 elseif (n == 2)
     f = 2;
 else
     f = fibonacci(n-1) + fibonacci(n-2);   
end