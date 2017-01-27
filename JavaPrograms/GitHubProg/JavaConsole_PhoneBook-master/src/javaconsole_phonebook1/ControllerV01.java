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
import java.util.Scanner;

/**
 *
 * @author mhcrnl
 */
public class ControllerV01 {
    
    public Contact[] creats() {
        int n;
        Scanner scan = new Scanner(System.in);
        System.out.println("Introduce-ti numarul de contacte: ");
        n = Integer.parseInt(scan.nextLine());
        Contact[] contacte = new Contact[n];
        for (int i =0; i<n; i++) {
            System.out.println("Introduce-ti numele contactului: ");
            String nume = scan.nextLine();
            System.out.println("Introduce-ti prenumele contactului: ");
            String prenume = scan.nextLine();
            System.out.println("Introduce-ti numarul de telefon: ");
            String telefon = scan.nextLine();
            System.out.println("Introduce-ti adresa de mail: ");
            String email = scan.nextLine();
            
            contacte[i]= new Contact(nume, prenume, telefon, email); 
        }
        scan.close();
        return contacte;
    }
    
    public void write(String file, Contact[] contacte) {
        try {
            OutputStream fos = new FileOutputStream(file, true);
            ObjectOutput oos = new ObjectOutputStream(fos);
            oos.writeObject(contacte);
            oos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
                         
    }
    
    public Contact[] read(String file){
        Contact[] contacte = null;
        try {
            InputStream fis = new FileInputStream(file);
            ObjectInput ois = new ObjectInputStream(fis);
            contacte = (Contact[]) ois.readObject();
            ois.close();
        } catch(ClassNotFoundException cn){
            cn.printStackTrace();
        } catch (IOException e) {
            System.out.println("Eroare la citirea filei.");
        }
        return contacte;
    }
    
    public void show(Contact[] contacte) {
        try {
            for(int i=0; i < contacte.length; i++){
                System.out.println("Contact numarul: "+(i+1)+contacte[i].toString());
            }
        } catch (NullPointerException e) {
            System.out.println("Fila goala.");
        }
    }
}
