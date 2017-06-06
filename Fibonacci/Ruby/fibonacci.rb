#!/usr/bin/ruby -w
#............................................................
# file: fibonacci.rb
#............................................................
class Fibonacci
	#...........................................CONSTRUCTOR
	def initialize
		@scratchpad = []
		@max_fibo_size = 50
		(1..@max_fibo_size).each do |i|
			@scratchpad[i] = :notcalculated
		end
	end
	#........................................................
	#Calculul numarului Fibonacci
	#........................................................
	def fibo(n)
		if n <= 1
			return n
		else 
			valoare = fibo(n-1) + fibo(n-2)
			return valoare
		end
	end
	#...............................................................
	#Calcul Fibonacci cu stocarea valorilor
	def fiboM(n)
		if n>@max_fibo_size
			return "n trebuie sa fie mai mic decat #{@max_fibo_size} ."
		elsif n <= 1
			return n
		elsif @scratchpad[n] != :notcalculated
			return @scratchpad[n]
		else
			@scratchpad[n] = fiboM(n-1) + fiboM(n-2)
			return @scratchpad[n]
		end
	end
	def citeste_fila(filename, mode)
		cFile = File.new(filename, mode)
		if cFile
			continut = cFile.sysread(2000)
			puts continut
		else
			"Fila nu a fost deschisa."
		end
	end
	
	def scrie_fila(filename, mode)
		sFile = File.new(filename, mode)
		if sFile
			sFile.syswrite(@scratchpad.to_s)
		else 
			puts "Fila nu a fost deschisa!"
		end
	end
end
