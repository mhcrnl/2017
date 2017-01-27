/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test.PersoanaArray;

import com.sun.istack.internal.logging.Logger;
import java.io.BufferedOutputStream;
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
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;

/**
 *
 * @author mhcrnl
 */
public class PersoanaArray {
    
    //private static final Logger fLogger = 
       //     Logger.getLogger(PersoanaArray.class.getPackage().getName());
    String file = "arrayPersoane.txt";
    int select;
    //Persoana persoana;
    public Persoana[] arrayPersoane;
    Scanner scan;
    
    public PersoanaArray(){
        this.arrayPersoane = new Persoana[3];
        scan = new Scanner(System.in);
        //arrayPersoane = readArray(file);
    }
    
    public void controller(){
        do {
            menu();
            select = scan.nextInt();
            scan.nextLine();
            switch(select){
                case 1:
                    String numepers = creazaPersoana();
                    arrayPersoane = addPersoanaV01(numepers);
                    break;
                case 2:
                    //arrayPersoane = readArray(file);
                    afiseazaPersoane(arrayPersoane);
                    
                    break;
                case 3:
                    saveArrayV01(file, arrayPersoane);
                    break;
                case 4:
                    readArray(file);
                    break;
                case 5:
                    sorteaza(arrayPersoane);
                    break;
                case 6:
                    searchFor(arrayPersoane);
                    break;
                case 7:
                    stergeElement(arrayPersoane);
                    break;
            }
        } while(select != 10);
        
    }
    
    public void searchFor(Persoana[] array){
        System.out.println("Introduce-ti numele persoanei cautate: ");
        String numeCautat = scan.nextLine();
        Persoana pers = new Persoana(numeCautat);
        Arrays.sort(array);
        int index = Arrays.binarySearch(array, pers);
        System.out.println("Persoana cautata este la indexul: " + index);
    }
          
    public void addPersoana(String nume){
        
        
        for(int i=0; i<arrayPersoane.length; i++ ){
            if(arrayPersoane[i] == null){      
                arrayPersoane[i] = new Persoana(nume);
                System.out.println("Persoana adaugata: "+ Arrays.toString(arrayPersoane));
            }
        }
    }
    
    public Persoana[] addPersoanaV01(String nume){
        System.out.println("Introduceti indexul 0,1 ,2....");
        int index = scan.nextInt();
        arrayPersoane[index] = new Persoana(nume);
        index++;
        System.out.println("Array" + Arrays.toString(arrayPersoane));
        return arrayPersoane;
    }
    
    public void menu() {
        System.out.println("==========================Meniu==================");
        System.out.println("1. ADAUGA UN NOU  ELEMENT IN Array===============");
        System.out.println("2. AFISEAZA TOATE ELEMENTELE DIN ARRAY===========");
        System.out.println("3. SALVEAZA PERSOANELE IN FILA===================");
        System.out.println("4. CITESTE PERSOANELE DIN FILA===================");
        System.out.println("5. SORTEAZA ARRAYS===============================");
        System.out.println("6. BINARYSEARCH()================================");
        
        System.out.println("10. INCHIDE APLICATIA=============================");
        System.out.print("Introduce-ti o varianta 1, 2, 3, 4 sau 5: ");
    }
    
    public void saveArray(String file, Persoana[] arrayPersoane) {
        try {
            OutputStream fos = new FileOutputStream(file);
            ObjectOutput oos = new ObjectOutputStream(fos);
                
            oos.writeObject(arrayPersoane);
            oos.close();
                
            System.out.println("Persoane salvate in: "+file+ arrayPersoane);
            
        } catch (IOException e) {
            System.out.println("Fila nu a fost scrisa!");
        } 
    }
    
    public void saveArrayV01(String file, Persoana[] arrayPersoane){
        Persoana[] array ;
        try {
            OutputStream fos = new FileOutputStream(file);
            OutputStream bos = new BufferedOutputStream(fos);
            ObjectOutput oos = new ObjectOutputStream(bos);
            
            for(Persoana pers: arrayPersoane){
                oos.writeObject(pers);
                System.out.println(""+pers);
            }
            
            oos.close();
            
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
            try {
                System.out.println("" +(Persoana) ois.readObject());
                array = (Persoana[]) ois.readObject();
                System.out.println("ARRAYS: "+array);
            } catch (ClassNotFoundException ex) {
                java.util.logging.Logger.getLogger(PersoanaArray.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        } catch (IOException e) {
            System.out.println("Fila nu a fost scrisa!2");
        }
    }
    
    public String creazaPersoana(){
        System.out.println("Introduce-ti numele Persoanei: ");
        String nume = scan.nextLine();
        System.out.println("A-ti introdus numele: "+ nume);
        return nume;
    }
    
    public void afiseazaPersoane(Persoana[] arrayPersoane){
        for(Persoana pers: arrayPersoane){
            System.out.println("Persoane: "+pers.toString());
        }
    }
    
    public void readArray(String file) {
        Persoana[] arrays = new Persoana[10];
        try {
            InputStream fis = new FileInputStream(file);
            ObjectInput ois = new ObjectInputStream(fis);
            arrays = (Persoana[])ois.readObject();
            for(Persoana pers: arrays){
                System.out.println("Persoana: " +pers.toString());
            }
            ois.close();
            
        } catch (ClassNotFoundException ex){
            System.out.println("Fila nua ");
        }
        
        catch (IOException e) {
            System.out.println("Fila nu a fost gasita.");
        }
        
    }

    private void sorteaza(Persoana[] arrayPersoane) {
        Arrays.sort(arrayPersoane);
        for(int i=0; i < arrayPersoane.length; i++){
            System.out.println(arrayPersoane[i]);
        }
    }

    private void stergeElement(Persoana[] arrayPersoane) {
        System.out.println("Introduce-ti indexul elementului pt. a fi sters: ");
        int element = scan.nextInt();
        //Persoana[] array = Arrays.Utils.removeElement(arrayPersoane, element);
        //System.out.println(array);
    }
}
