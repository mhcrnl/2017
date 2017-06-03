#!/usr/bin/ruby -w
#............................................................
# file: fibonacci.rb
#............................................................
class Fibonacci
	#........................................................
	#Calculul numarului Fibonacii
	#........................................................
	def fibo(n)
		if n <= 1
			return n
		else 
			valoare = fibo(n-1) + fibo(n-2)
			return valoare
		end
	end
end
