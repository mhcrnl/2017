#!/usr/bin/ruby -w

class Actiune
	#......................................................Constructor
	def initialize(firma, actiune, pretActiune, data)
		@firma = firma
		@actiune = actiune
		@pretActiune = pretActiune
		@data = data
	end
	#.......................................................to_s
	def to_s
		puts @firma+" "+@actiune+" "+@data+" "+@pretActiune
	end
end


act = Actiune.new("Banca Romana de Dezvoltare", "BRD", "02.06.2017", 11.7899.to_s)
act.to_s