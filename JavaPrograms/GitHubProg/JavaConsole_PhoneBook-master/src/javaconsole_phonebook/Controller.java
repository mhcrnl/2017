/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaconsole_phonebook;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mhcrnl
 */
public class Controller {
    
    String file = "/home/mhcrnl/NetBeansProjects/JavaConsole_PhoneBook/Contact.txt";
    String nume, prenume, telefon, email;
    PersistentContact pc= new PersistentContact();
    Contact contact;
    Scanner in;
    
    public void adaugaContact(){
        
        in = new Scanner(System.in);
        System.out.println("Introduce-ti numele contactului: ");
        nume = in.next();
        System.out.println("Introduce-ti prenumele contactului: ");
        prenume = in.next();
        System.out.println("Introduce-ti numarul de telefon: ");
        telefon = in.next();
        System.out.println("Introduce-ti adresa de email: ");
        email = in.next();
        
        contact = new Contact(nume, prenume, telefon, email);
        
        
        try {
            pc.saveToFile(file, contact);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Controller.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
        
    }
    
    public void afiseazaContact(){
        
        try {
            pc.readFile2("Contact.txt");
        } catch (IOException ex) {
            Logger.getLogger(Controller.class.getName()).log(Level.SEVERE, "nu afost", ex);
        }
        
    }
    
}
