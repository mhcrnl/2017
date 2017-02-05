#!/usr/bin/python
class Angajat:
    'Clasa angajat'
    nrAngajati=0
    def __init__(self, nume, salariu):
        self.nume = nume
        self.salariu = salariu
        Angajat.nrAngajati+=1

    def displayCount(self):
        print "Numarul total de angajati %d" % Angajat.nrAngajati

    def afisareAngajati(self):
        print "Nume: ", self.nume, ", Salariu: ", self.salariu

    def __del__(self):
        class_name = self.__class__.__name__
        print class_name, "Obiect sters"

    def Metoda(self):
        print "Metoda din clasa parinte."

    def __str__(self):
        return 'Angajat(%s, %s)' %(self.nume, self.salariu)

class Salariat(Angajat):
    def __init__(self):
        print "Apelul constructorului clasei derivate."

    def Metoda(self):
        print "Apelul metodei din clasa derivata."

angajat1 = Angajat("Mihai", 456)
angajat1.afisareAngajati();
print "Numarul total de angajati: %d" % Angajat.nrAngajati
angajat1.varsta = 34
print angajat1
print "ATRIBUT: ", hasattr(angajat1, 'varsta')
print "Varsta: ", getattr(angajat1, 'varsta')
setattr(angajat1, 'varsta', 47)
print "Varsta: ", getattr(angajat1, 'varsta')
delattr(angajat1, 'varsta')

print "Angajat.__doc__:", Angajat.__doc__
print "Angajat.__name__:", Angajat.__name__
print "Angajat.__module__:", Angajat.__module__
print "Angajat.__bases__:", Angajat.__bases__
print "Angajat.__dict__:", Angajat.__dict__

del angajat1

salariat1 = Salariat()
salariat1.Metoda()
