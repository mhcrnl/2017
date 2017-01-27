/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package agendatelefonica;
import java.util.ArrayList;
/**
 *
 * @author mhcrnl
 */
public class Agenda {
    public static ArrayList contacte = new ArrayList();
    public static void adauga(String nume, String prenume, String nrTel){
        Contact contact = new Contact(nume, prenume, nrTel);
        contacte.add(contact);
        //ordonare();
    }
    public static void ordonare(){
        int arraySize = contacte.size();
        if(arraySize > 1){
            for(int i=0; i<arraySize -1; i++){
                for(int a=0; a<arraySize-1-i; a++){
                    Contact con1 = (Contact) contacte.get(a);
                    Contact con2 = (Contact) contacte.get(a+1);
                    if(con1._nume > con2._nume){
                        contacte.set(a, con2);
                        contacte.set(a+1, con1);
                    }
                }
            }
        }
    }
    public static void sterge(int index){
        contacte.remove(index);
    }
    public static void afiseaza(){
        for(int i=0; i<contacte.size(); i++){
            Contact con = (Contact) contacte.get(i);
            System.out.println(i+" "+con._nume+" "+con._prenume+" "+con._nrTel);
        }
    } 
}
