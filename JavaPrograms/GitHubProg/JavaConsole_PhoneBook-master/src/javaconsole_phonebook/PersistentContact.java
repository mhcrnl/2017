/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaconsole_phonebook;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author mhcrnl
 */
public class PersistentContact {
    
    public void saveToFile(String file, Contact con) throws FileNotFoundException{
        PrintWriter pw = new PrintWriter(new FileOutputStream(file, true));
        //Scrie contactel linie cu linie mai usor la citire
        pw.println(con.toString());
        pw.close();
    }
    
    public void readFromFile(String file) throws FileNotFoundException, IOException{
        InputStream fis = new FileInputStream(file);
        Scanner scan = new Scanner(fis);
        while(scan.hasNextLine()){
            String contacte = scan.nextLine();
            System.out.println("Contact: " + contacte );
            //return contacte;
        }
        fis.close();
        //return null;
    }
    
    public void readFile(String file) throws FileNotFoundException, IOException {
        InputStream fis = new FileInputStream(file);
        //BufferedReader br = new BufferedReader(new InputStreamReader(fis));
        Scanner br = new Scanner(fis);
        String line = null;
        while((line= br.nextLine()) != null){
            System.out.println(line);
        }
        br.close();
    }
    
    public void readFile2(String file) throws FileNotFoundException, IOException{
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while((line = br.readLine()) != null){
                System.out.println(line);
            }
        }
    }
    
    public void readLine3(String file) throws FileNotFoundException, IOException{
        FileInputStream fis = new FileInputStream(file);
        try (BufferedReader br = new BufferedReader(new InputStreamReader(fis))) {
            String line;
            while((line = br.readLine()) != null){
                System.out.println(line);
            }
        }
    }
    
    public static void main(String[] args) throws IOException {
        String file = "Contact.txt";
        PersistentContact ps = new PersistentContact();
        ps.readFile2(file);
    }
}
