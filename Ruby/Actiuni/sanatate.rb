#!/usr/bin/ruby -w

class Sanatate
	@@inregistrare = 0
	# attr_accessor - citeste si scrie variabilele din classa
	attr_accessor :nume, :prenume, :data, :greutate 
	#...........................................Constructor
	def initialize(nume, prenume, data, greutate)
		@nume = nume
		@prenume = prenume
		@data = data
		@greutate = greutate
	end
	#.............................................to_s
	def to_s
		puts @nume+" "+@prenume+" "+@data+" "+@greutate.to_s
	end
end

mhcrnl = Sanatate.new("Mihai", "Cornel", "01Iunie2017", 96.70)
puts "Introduceti numele: "
mhcrnl.nume = gets
puts "Introduceti prenumele: "
mhcrnl.prenume = gets
puts "Introduceti data (01Iunie2017): "
mhcrnl.data = gets
puts "Introduceti greutatea: "
mhcrnl.greutate = gets
mhcrnl.to_s

afile = File.new("persoana.txt", "r+")
if afile
	afile.syswrite("mhcrnl.to_s")
else
	puts "Fila nu a fost deschisa"
end
afile.close
