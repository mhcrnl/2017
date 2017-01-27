/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaconsole_phonebook1;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mhcrnl
 */
public class Controller {
    
    String file = "contact1.txt";
    String nume, prenume, telefon, email;
    Scanner scan = new Scanner(System.in);
    PersistentContact ps = new PersistentContact();
    Contact contact;
    
    public void adaugaContact(){
        System.out.println("Introduce-ti numele persoanei: ");
        nume = scan.nextLine();
        System.out.println("Introduce-ti prenumele persoanei; ");
        prenume = scan.nextLine();
        System.out.println("Introduce-ti numarul de telefon: ");
        telefon = scan.nextLine();
        System.out.println("Introduce-ti adresa de email: ");
        email = scan.nextLine();
       
        contact = new Contact(nume, prenume, telefon, email);
        ps.saveContact(file, contact);
    }
    public void afiseazaContacte() {
        
        List<Contact> lista = new ArrayList<Contact>();
        Contact[] contacts ;
        contacts = ps.readContacts(file);
        System.out.println(contacts.toString());
        
        try {
            lista = ps.readContacts1(file);
        } catch (IOException ex) {
            Logger.getLogger(Controller.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println(""+lista);
        
    }
}
