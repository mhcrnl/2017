#!/usr/bin/ruby -w

class Carte
	#....................................................
	# Metoda de introducere a datelor 
	def creaza_carte
		#Variabile de instanta
		puts ">>>INTRODUCETI O NOUA CARTE<<<"
		puts "Introduceti numarul ISBN: "
		@isbn = gets
		puts "Introduceti autorul: "
		@autor = gets
		puts "Introduceti titlul cartii: "
		@titlu = gets
		puts "Introduceti editura cartii: "
		@editura = gets
	end
	#......................................................
	# Metoda de afisare a datelor
	def to_s
		puts @isbn+" "+@autor+" "+@titlu+" "+@editura
	end
	#......................................................
	# Metoda de modificare a cartii
	def modificare_carte
		
	end
end