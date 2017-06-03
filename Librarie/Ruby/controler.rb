#!/usr/bin/ruby -w

class Controler
    #....................................................
    # Metoda meniu - afiseaza meniul aplicatiei 
    # Returneaza string
    def meniu
        puts ">>>MENIUL APLICATIEI LIBRARIE<<<"
        puts "1. Adaugare carte."
        puts "2. Afisare studenti."
        
        puts "Introduceti un numar din meniu:"
        meniu = gets
        return meniu.chomp
    end
end

con = Controler.new
puts con.meniu
