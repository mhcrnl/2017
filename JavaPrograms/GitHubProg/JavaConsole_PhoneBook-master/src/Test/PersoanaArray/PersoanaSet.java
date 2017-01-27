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
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mhcrnl
 */
public class PersoanaSet {
    
    String file = "setPersoane.txt";
    private Set<Persoana> setPersoane;
    
    public PersoanaSet() {
        setPersoane = new HashSet<Persoana>();
        setPersoane = readFromFile(file);
    }
    
    public void controller() {
        Scanner scan = new Scanner(System.in);
        int select;
        do{
            
            select = scan.nextInt();
            
            switch(select){
                case 1:
                    
                    break;
                case 2:
                    
                    break;
            }
            
        } while(select != 10);
    }
    
    public void removeAllPersoana(){
        setPersoane.clear();
        writeToFile(file, setPersoane);
    }
    
    public void removePersoana(Persoana pers) {
        if(setPersoane.contains(pers)){
            setPersoane.remove(pers);
            writeToFile(file, setPersoane);
        }
    }
    
    public void addPersoana(Persoana pers){
        if(!setPersoane.contains(pers)){
            setPersoane.add(pers);
            writeToFile(file, setPersoane );
        }
    }

    private Set<Persoana> readFromFile(String file) {
        
        InputStream fis = null;
        ObjectInput ois = null;
        Set<Persoana> setPers = new HashSet<Persoana>();
        
        try {
            fis = new FileInputStream(file);
            ois = new ObjectInputStream(fis);
            if(ois.readObject() != null){
                setPers = (Set<Persoana>) ois.readObject();
            }
        } catch (FileNotFoundException fe){
            System.out.println("Nu exista inregistrari in fila!" + fe);
        } catch (IOException io) {
            io.printStackTrace();
        } catch (ClassNotFoundException cn) {
            cn.printStackTrace();
        }
        finally {
            if(fis != null){
                try {
                    fis.close();
                } catch (IOException ex) {
                    Logger.getLogger(PersoanaSet.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            if(ois != null){
                try {
                    ois.close();
                } catch (IOException ex) {
                    Logger.getLogger(PersoanaSet.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
        return setPers;
    }

    /**
     * @return the setPersoane
     */
    public Set<Persoana> getSetPersoane() {
        return setPersoane;
    }

    /**
     * @param setPersoane the setPersoane to set
     */
    public void setSetPersoane(Set<Persoana> setPersoane) {
        this.setPersoane = setPersoane;
        writeToFile(file, setPersoane);
    }

    private void writeToFile(String file, Set<Persoana> setPersoane) {
        
        OutputStream fos = null;
        ObjectOutput oos = null;
        
        try {
            fos = new FileOutputStream(file);
            oos = new ObjectOutputStream(fos);
            oos.writeObject(setPersoane);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(fos != null){
                try {
                    fos.close();
                } catch (IOException ex) {
                    Logger.getLogger(PersoanaSet.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            if(oos!= null){
                try {
                    oos.close();
                } catch (IOException ex) {
                    Logger.getLogger(PersoanaSet.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
        
    }
    
}
