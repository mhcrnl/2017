/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test.PersoanaArray;

import java.io.Serializable;
import java.util.Comparator;

/**
 *
 * @author mhcrnl
 */
public class Persoana implements Serializable, Comparable<Persoana> {
    
    private String nume;
    
    public Persoana(String nume){
        this.nume = nume;
    }
    
    @Override
    public boolean equals(Object obj){
        if(obj instanceof Persoana){
            Persoana persoana = (Persoana) obj;
            return(nume.equals(persoana.getNume()));
        }
        return false;
    }
    
    @Override
    public int hashCode(){
        return nume.length();
    }
    
    @Override
    public String toString(){
        return nume;
    }

    /**
     * @return the nume
     */
    public String getNume() {
        return nume;
    }

    /**
     * @param nume the nume to set
     */
    public void setNume(String nume) {
        this.nume = nume;
    }

    @Override
    public int compareTo(Persoana o) {
        return toString().compareTo(o.toString());
            
        
    }
    
}

class PersoanaNumeComparator implements Comparator<Persoana>{
    @Override
    public int compare(Persoana pers1, Persoana pers2){
        return pers1.getNume().compareToIgnoreCase(pers2.getNume());
    }
}
