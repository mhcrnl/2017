#!/usr/bin/ruby -w
=begin
    author:     Mihai Cornel email: mhcrnl@gmail.com
    file:       persoana.rb
    created:    28.05.2017
    class:      Persoana
    methods:    1. initialize(nume, prenume)
                2. dispaly_details()
                3. numarulTotalDePersoane
                4. to_s()
                5. citesteFila(filename, mode)
=end

class Persoana
    #Variabile de clasa
    @@instantePersoana = 0
    #................................................
	# 1. Metoda Constructor
    def initialize(nume, prenume)
        #Variabile de instanta
        @nume = nume
        @prenume = prenume
    end
	#..........................................................
    #2. Metoda display_details() - afiseaza numele si prenumele
    def display_details()
        puts "Numele persoanei: #@nume"
        puts "Prenumele persoanei: #@prenume"
    end
	#...............................................................
    #3. Metoda numarulTotalDePersoane() - instantele clasei Persoana
    def numarulTotalDePersoane()
        @@instantePersoana += 1
        puts "Numarul total de persoane: #@@instantePersoana"
    end
	#.................................................................
    #4. Metoda to_s() - toString
    def to_s()
        puts "Nume: "+@nume+" Prenume: "+@prenume
    end
	#..................................................................
    #5. citesteFila(filename, mode) - citeste si afiseaza fila de text
    def citesteFila(filename, mode)
        aFile = File.new(filename, mode)
        if aFile
            content = aFile.sysread(20000)
            puts content
        else
            puts "Fila nu a fost deschisa."
        end
    end
	#..................................................................
    def scrieFila(filename, mode, persoana)
       aFile = File.new(filename, mode)
       #nume = persoana.to_s()
       if aFile
           aFile.syswrite(persoana)
       else
           puts "Fila nu a fost deschisa."
       end 
    end
end

pers = Persoana.new("Mihai", "Cornel")
pers.to_s()
pers.display_details()
pers.numarulTotalDePersoane()
pers.citesteFila("persoana.rb", "r")
pers.scrieFila("persoana.txt", "w", pers)
