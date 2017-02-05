#!/usr/bin/python

class Contact(object):
    'Clasa contact -Python Object Oriented object este clasa din care deriva Contact'
    """
        Adaugarea :
        1. functii get/set pt introducerea de catre utilizator a contactelor
        2. Salvarea contactelor in file
        3. Citirea contactelor din fila
        4. Adaugarea de contacte in list
        5. in python nu sunt necesari get/set-ari campurile fiind publice
        6. ascunderea datelor __nume acesta nu este vizibil in afara clasei
        7. Metodele getter/setter sunt pattern-uri pt masini gen java dar nu pt python
        8. http://2ndscale.com/rtomayko/2005/getters-setters-fuxors -java/python
        9.
    """
    nrContacte = 0
    nume = ''
        
    def __init__(self, nume=None, prenume=None, nrTel=None, email=None):
        """
        Supraincarcarea constructorului nu este permisa in python
        1. Este o metoda care este apelata la crearea unui obiect.
        2. self este chiar instanta clasei
        """
        self.nume = nume
        self.prenume = prenume
        self.nrTel = nrTel
        self.email = email
        Contact.nrContacte+=1

    def __str__(self):
        """
        Afisarea contactelor cu metoda str.
        Functie speciala definita in toate clasele Python.
        """
        return ' %d Contact: %s %s, %s, %s' %(self.nrContacte, self.nume, self.prenume, self.nrTel, self.email)

    def setNume(self):
        print 'Introduceti numele contactului: '
        self.nume = raw_input()
        return self.nume

    def getNume(self):
        return self.nume

    def setPrenume(self):
        print 'Introduceti prenumele contactului: '
        self.prenume = raw_input();
        return self.prenume

    def getPrenume(self):
        return self.prenume

    def setNrTel(self):
        print 'Introduceti numarul de telefon: '
        self.nrTel = raw_input()
        return self.nrTel

    def getNrTel(self):
        return self.nrTel

    def setEmail(self, value):
        if '@' not in value:
            raise Exception("Nu este o adresa valida!")
        self._email = value

    def getEmail(self):
        return self._email
    """
        When the email attribute is set, the set_email method is called.
        When the email attribute is "got", the get_email method is called.
    """
    email = property(getEmail, setEmail)
    
class Agenda(Contact):
    contactList =[]

    def __init__(self, nume=None, prenume=None, nrTel=None, email=None,contactList=[]):
        """ apelul constructorului clasei parinte"""
        Contact.__init__(self, nume, prenume, nrTel, email)
        contact2 = Contact(nume, prenume, nrTel)
        contactList.append(contact2)

    def __str__(self):
        return "%d : %s %s : %s : %s" %(self.nrContacte,self.nume, self.prenume,self.nrTel,self.email)  
            

class Controler(object):

    def __init__(self):
        pass
    
    def controlerMeniu(self):
        meniu = ['A - adauga contact', 'S - Sterge contact', 'P - Print contacte']
        print "Ce doriti sa faceti?"
        for i in meniu:
            print i
        userInput = raw_input()
        if userInput =="a" or userInput=="s" or userInput=="p":
            if userInput=="a":
                'print "a"'
                adaugaContact(self)
            elif userInput=="s":
                print "Sterge"
            else:
                print "afiseaza"
        else:
            print "Alegera dvs nu este valida"

    def adaugaContact(self):
        con = Contact()
        con.setNume()
        
    

controler = Controler()
controler.controlerMeniu()
contactList = []

    
'agenda=Agenda("MIhai", "Vasile", "0789654234", "mhcrnl@gmail.com", contactList)'
contact = Contact("Mihai", "Cornel", "0722270796", "mhcrnl@gmail.com")
contact.nume = contact.setNume()
contact.email = "@raduc.com"
prenume = contact.setPrenume()
print contact
print contact.getNume()
contact1 = Contact("Radu", "Vasile", "0765456789", "yahoo@gmail.com")
print contact1
contactList.append(contact)
contactList.append(contact1)
print contactList[0]
for Con in contactList:
    print Con
