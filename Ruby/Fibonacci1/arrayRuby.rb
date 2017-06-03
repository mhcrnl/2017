#!/usr/bin/ruby -w

#................................................
# Array index begin at 0

class Persoana
	#......................Constructor
	def initialize(nume)
		@nume = nume
	end
	#................................................
	def set_nume(nume)
		@nume = nume
	end
	#.............................................
	def get_nume
		return @nume
	end
end

pers = Persoana.new("Cornel")
ary = Array.new

ary.push(1)
ary.push(pers.get_nume)
puts ary[0]
puts ary[1]