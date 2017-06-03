#!/usr/bin/ruby -w

class Fibonacci
    def fibo(n)
        if n <= 1
            return n
        else
            valoare = fibo(n-1) + fibo(n-2)
            return valoare
       end
    end
end

fib = Fibonacci.new

(1...40).each do |numar|
    puts "fib.fibo(#{numar})= #{fib.fibo(numar)}"
end
