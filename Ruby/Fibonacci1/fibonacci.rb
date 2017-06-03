#!/usr/bin/ruby -w

class Fibonacci
	#...........................................
	# Initialize the memoization array.
	#.............................................
	#@scratchpad = []
	#@max_fibo_size = 50
	#(1..@max_fibo_size).each do |i|
	#	@scratchpad[i] = :notcalculated
	#end
	
	def fibo(n)
		if n <= 1
			return n
		else 
			valoare = fibo(n-1) + fibo(n-2)
			return valoare
		end
	end
	def fiboMem(n)
	
		@scratchpad = []
		@max_fibo_size = 50
		(1..@max_fibo_size).each do |i|
			@scratchpad[i] = :notcalculated
		end
		
		if n > @max_fibo_size
			return "n must be #{@max_fibo_size} or less."
		elsif n <= 1
			return n
		elsif @scratchpad[n] != :notcalculated
			return @scratchpad[n]
		else
			@scratchpad[n] = fibo(n-1)+ fibo(n-2)
			return @scratchpad[n]
		end
	end
end

fib = Fibonacci.new

(1..40).each do |numar|
	puts "fib.fibo(#{numar}) = #{fib.fibo(numar)}"
end

(1..40).each do |numar|
	puts "fib.fiboMem(#{numar}) = #{fib.fiboMem(numar)}"
end