#!/usr/bin python
"""Aplicatia de Persoane care pastreaza persoanele intr-o lista, in care elementele pot fi accesate dupa index"""
class Persoana(object):
    #Constructor in Python
    def __init__(self, nume=None, prenume=None):
        self.nume = nume;
        self.prenume = prenume
    #Afiseaza variabilele clasei in format string
    def __str__(self):
        return self.nume+" "+self.prenume
    # Afiseaza persoanele din list in format string
    def __repr__(self):
        return str(self)
"""Valorile din meniu implementate cu o lista"""
meniu = [
         '1. Adauga contact',
         '2. Sterge contact',
         '3. Afiseaza contacte',
         '4. Numarul de contacte',
         '5. Adauga fila README.md',
         '6. Iesire aplicatie'
         ]
"""Lista de contacte in care vor fi stocate persoanele"""
listaContacte = []
"""Functia care parcurge lista meniu si o afiseaza"""
def afiseazamMeniu(list):
    print "Ce doriti sa faceti?"
    for i in meniu:
        print i
"""Controler functia care are rolul de control al aplicatiei"""
def controler():
    alegere = True
    while alegere:
        afiseazamMeniu(meniu)
        alegere = raw_input("Introduceti alegerea dvs: ")
        if alegere =="1":
            print "Adauga contact"
            adauga()
        elif alegere == "2":
            print "Sterge contact"
        elif alegere == "3":
            print "Afiseaza Contacte"
            afiseazaPersoane()
        elif alegere == "4":
            print "Numarul de contacte"
            numarulDeContacte()
        elif alegere == "5":
            print "Fila README.md a fost adaugata. "
            adaugaReadme()
        elif alegere == "6":
            print "Iesire aplicatie"
            alegere = None
#Afisarea persoanelor din lista
def afiseazaPersoane():
    print "Contactele din agenda sunt: "
    #print "".join([str(x) for x in listaContacte])

    for p in listaContacte:
        print str(p)
#Adaugarea persoanelor in lista
def adauga():
    print "Introduceti numele persoanei: "
    nume = raw_input()
    print "Introduceti prenumele persoanei:"
    prenume = raw_input()
    pers = Persoana(nume, prenume)
    listaContacte.append(pers)
    print listaContacte
#Afisarea numarului de contacte din lista
def numarulDeContacte():
    """Afiseaza numarul de contacte din lista de contacte listaContacte"""
    print listaContacte.__len__()
"""Crearea unei pagini README.md pt github. Scrierea si citirea de file in Python este asemanatoare cu cea din C/C++
Java, Perl """
def adaugaReadme():
    """Adauga fila README.md la proiect. Accesarea acestei functii va rescrie fila README.md daca exista."""
    scrie = open("README.md","w")
    scrie.write("Synopsis \n\n"+
"At the top of the file there should be a short introduction and/ or overview that explains what the project is." +
"This description should match descriptions added for package managers (Gemspec, package.json, etc.)\n" +
"\n\nCode Example\n\n" +
"Show what the library does as concisely as possible, developers should be able to figure out how your project solves "+
"their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise."+
"\n\nMotivation\n\n" +
"A short description of the motivation behind the creation and maintenance of the project. This should explain why the project exists."+
"\n\nInstallation\n\n" +
"Provide code examples and explanations of how to get the project." +
"\n\nAPI Reference\n\n"+
"Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README."+
" For medium size to larger projects it is important to at least provide a link to where the API reference docs live."+
"\n\nTests\n\n"
"Describe and show how to run the tests with code examples."+
"\n\nContributors\n\n"+
"Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable."+
"\n\nLicense\n\n"
"A short snippet describing the license (MIT, Apache, etc.)")
    scrie.close()
#Modulul de test cu __name__
if __name__ == "__main__":
    x = Persoana("Marvin", "Radu")
    print x
    controler()


