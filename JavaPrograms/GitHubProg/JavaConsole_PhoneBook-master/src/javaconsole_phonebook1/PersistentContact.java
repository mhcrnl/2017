/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaconsole_phonebook1;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author mhcrnl
 */
public class PersistentContact {
    
    public void saveContact(String file, Contact contact){
        try {
            OutputStream fos = new FileOutputStream(file, true);
            ObjectOutput oos = new ObjectOutputStream(fos);
            oos.writeObject(contact);
            System.out.println("Contactul a fost salvat!");
            oos.close();
        } catch (IOException e) {
            System.out.println(e);
        } 
    }
   
    public Contact[] readContacts(String file){
        Contact contact[] = null;
        try {
            InputStream fis = new FileInputStream(file);
            try (ObjectInput oos = new ObjectInputStream(fis)) {
                contact = (Contact[])oos.readObject();
            }
            System.out.println("Contact: "+Arrays.toString(contact));
            //return contact;
        } catch(ClassNotFoundException ex){
            System.out.println("Class not found");
        }
        catch (IOException e) {
        }
    return contact;
    }
    
    public List<Contact> readContacts1(String file) throws IOException {
        List<Contact> listaContacte = new ArrayList<Contact>();
        Contact contact = null;
        ObjectInput ois = null;
        try {
            InputStream fis = new FileInputStream(file);
            ois = new ObjectInputStream(fis);
            do {
               contact = (Contact)ois.readObject();
               if(contact != null){
                    listaContacte.add(contact);
               }
            } while(contact != null); 
            int i=0;
            System.out.println(listaContacte.get(i));
            return listaContacte;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(ois != null){
                ois.close();
            } 
                    
                    
        }
        return null;
    }
}
