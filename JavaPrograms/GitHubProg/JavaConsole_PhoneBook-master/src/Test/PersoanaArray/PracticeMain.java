/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test.PersoanaArray;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mhcrnl
 */
public class PracticeMain {
    
    static String file = "PracticeMain.txt";
    
    Persoana p1 = new Persoana("Mihai");
    Persoana p2 = new Persoana("Cornel");
    Persoana p3 = new Persoana("Irina");
    Persoana p4 = new Persoana("Vasile");
    
    Persoana[] persoane;
    
    public PracticeMain(){
        persoane = new Persoana[4];
        persoane[0] = p1;
        persoane[1] = p2;
        persoane[2] = p3;
        persoane[3] = p4;
        System.out.println("PERSOANE : "+persoane);
    }
    
    public void writeArray(String file, Persoana[] persoane) throws IOException{
        OutputStream fos = null;
        ObjectOutput oos = null;
        try {
            fos = new FileOutputStream(file);
            oos = new ObjectOutputStream(fos);
            oos.writeObject(persoane);
            System.out.println("ARRAY: "+persoane);
            for(Persoana pers: persoane){
                System.out.println("PERSOANE: "+pers.toString());
            }
            
        } finally {
            if(fos != null){
                fos.close();
            }
            if(oos != null){
                oos.close();
            }
        }
        
    }
    
    public void readArray(String file) throws IOException, ClassNotFoundException{
        Persoana[] arrays ;
        InputStream fis = null;
        ObjectInput ois = null;
        try {
            fis = new FileInputStream(file);
            ois = new ObjectInputStream(fis);
            
            arrays =(Persoana[]) ois.readObject();
            System.out.println("Array from File: "+ arrays);
            for(Persoana pers: arrays){
                System.out.println("Persoane from file: "+ pers.toString());
            }
        } finally {
            if(fis != null){
                fis.close();
            }
            if(ois != null){
                ois.close();
            }
        }
    }
    
    public void controler() throws IOException, ClassNotFoundException{
        try {
            writeArray(file, persoane);
        } catch (IOException ex) {
            Logger.getLogger(PracticeMain.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        readArray(file);
    }
    
    
    public static void main(String[] args) {
        PracticeMain pm = new PracticeMain();
        try {
            pm.controler();
        } catch (IOException ex) {
            Logger.getLogger(PracticeMain.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(PracticeMain.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
