/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package setcoll;
import java.util.*;
/**
 *
 * @author mhcrnl
 */
public class SetColl {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int count[]={34,45,67,13,69,96};
        Set<Integer> set = new HashSet<Integer>();
        try{
            for(int i=0; i<5; i++){
                set.add(count[i]);
            }
            System.out.println(set);
            //Sorted set pastreaza elementele sortate dupa valoare.
            TreeSet sortedSet = new TreeSet<Integer>(set);
            System.out.println("Lista sortedSet sortata este: ");
            System.out.println(sortedSet);
            System.out.println("Primul element din sortedSet este: "+(Integer)sortedSet.first());
            System.out.println("Ultimul element din sortedSet este: "+(Integer)sortedSet.last());
            //LinkedHashSet pastreaza ordinea de inserare
            LinkedHashSet lhs = new LinkedHashSet<>(set);
            lhs.add(100);
            System.out.println("Lista lhs este: ");
            System.out.println(lhs);
            System.out.println("Dimensiunea in elemente a lhs: "+lhs.size());
            int total =0;
            //int myArr[] =lhs.toArray();
            for(int i=0; i<lhs.size(); i++){
                lhs.toArray();
                //total += lhs[i] ;
            }
            System.out.println("TOTAL lhs: "+total);
        }catch(Exception e){
            
        }
        
    }
    
}
