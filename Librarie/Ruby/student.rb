#!/usr/bin/ruby -w

class Student
    # Variabila de clasa
    @@numarStudenti = 0
    #.............................................................
    # Constructor
    def initialize(nume, matricol)
        @@numarStudenti +=1
        @nume = nume
        @matricol = matricol
    end
    #..............................................................
    def creare_student
        @@numarStudenti += 1
        puts ">>>CREARE STUDENT<<<"
        puts "Introduceti numarul studentului: "
        @nrStudent = gets
        puts "Introduceti numele studentului: "
        @numeStudent = gets
        @token = 0
        puts ">>>STUDENTUL A FOST INREGISTRAT<<<"
    end
    #................................................................
    def to_s
        return "#{@@numarStudenti}--#{@nume}--#{@matricol}"
    end
end
