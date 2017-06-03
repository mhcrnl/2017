#!/usr/bin/ruby -w
#...................................................
# Fila executabila: run.rb
#...................................................
require './fibonacci'
# Afisarea secventei Fibonacci - ineficient
# Crearea obiectului clasei Fibonacci
fib = Fibonacci.new
# Generare 40 numere Fibonacci
(1..40).each do |numar|
	puts "fib.fibo(#{numar}) = #{fib.fibo(numar)}"
end