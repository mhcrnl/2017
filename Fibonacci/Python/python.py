#!/usr/bin/python

def fibo(n):
    if n <=1:
        return n
    else:
        return(fibo(n-1)+fibo(n-2))

ntermeni = 10
if ntermeni <=0:
    print("Introduceti un numar pozitiv")
else:
    print ("Numerele Fibonacci:")
    for i in range(ntermeni):
        print(fibo(i))
    
