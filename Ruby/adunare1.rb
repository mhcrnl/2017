#!/usr/bin/ruby -w

#puts "Salut din Ruby!";

class Calcul
    def adunare(nr1, nr2)
        puts nr1+nr2
        return nr1 + nr2
    end
    def adunare1(*nrVariabilDeElemente)
        total = 0
        puts "Numarul de parametrii #{nrVariabilDeElemente}"
        for i in 0...nrVariabilDeElemente.length
            puts "Parametrii metodei sunt: #{nrVariabilDeElemente[i]}"
        end
        for i in 0...nrVariabilDeElemente.length
            total += nrVariabilDeElemente[i]
        end
        return total 
    end
end
BEGIN{
    puts "Acesta este codul de inceput"
}

END{
    puts "Programul a fost conceput de mhcrnl"
}
clasa1 = Calcul. new
nr3 = clasa1.adunare(5,5)
puts nr3
nr4 = clasa1.adunare1(23, 45,56)
puts nr4

