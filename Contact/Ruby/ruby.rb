#!/usr/bin/ruby -w
=begin
    author:     Mihai Cornel email: mhcrnl@gmail.com
    file:       persoana.rb
    created:    28.05.2017
    class:      Persoana
    methods:    1. initialize(nume, prenume)
                2. dispaly_details()
                3. to_s()
=end

class Persoana
    #Variabile de clasa
    @@instantePersoana = 0
    #1. Metoda Constructor
    def initialize(nume, prenume)
        #Variabile de instanta
        @nume = nume
        @prenume = prenume
    end
    #2. Metoda display_details() - afiseaza numele si prenumele
    def display_details()
        puts "Numele persoanei: #@nume"
        puts "Prenumele persoanei: #@prenume"
    end
    def numarulTotalDePersoane()
        @@instantePersoana += 1
        puts "Numarul total de persoane: #@@instantePersoana"
    end
    def to_s()
        return "#{@nume} #{@prenume}"
    end
end

pers = Persoana.new("Mihai", "Cornel")
pers.to_s()
pers.display_details()
pers.numarulTotalDePersoane()
