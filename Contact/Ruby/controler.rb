#!/usr/bin/ruby -w

require "./ruby"

class Controler
    
    def initialize
        @pers_array = Array.new
    end
    
    def meniu
        puts ">>>MENIUL APLICATIEI<<<"
        puts "1. adauga"
        puts "2. salveaza"
        puts "3. sterge"
        puts "4. Iesire din aplicatie."
        puts "introduceti o optiune: "
        optiune = gets
        puts optiune.chomp
        return optiune.chomp
    end
    def control
        begin
           optiune = meniu
            if optiune === "1"
                puts ">>>>>>>>>>>>>>>>>Adauga.<<<<<<<<<<<<<<<<<<<"
                puts "Introduceti numele persoanei: "
                @nume = gets
                puts "Introduceti prenumele persoanei: "
                @prenume = gets
                pers = Persoana.new(@nume.chomp, @prenume.chomp)
                puts pers.to_s
                
                @pers_array<<(pers.to_s)
                puts "#{@pers_array}"
            elsif optiune ==="2"
                puts "Salveaza"
            elsif optiune === "3"
                puts "Sterge"
                
            else
                puts "Exit."
            end
        end while optiune < "4"
    end
end

con = Controler.new
con.control
