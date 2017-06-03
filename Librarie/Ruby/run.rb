#!/usr/bin/ruby -w

require './carte'
require './student'
require './save'

#car = Carte.new
#std = Student.new
sav = Save.new("student.txt", "a+")
=begin
car.creaza_carte
car.to_s
car.modificare_carte
car.to_s
#=end
std.creare_student
#student = std.to_s


=end

puts "Introduceti un numar din meniu: "
meniu = gets

if meniu.chomp === "1"
    puts "Introduceti numele studentului:"
    nume = gets
    puts "Introduceti numarul matricol:"
    matricol = gets
    std = Student.new(nume, matricol)
    sav.save_to_file(std.to_s)
elsif meniu.chomp === "2"
    sav.read_from_file_1
else meniu.chomp === "3"
    exit
end
        
        
        
        
