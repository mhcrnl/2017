/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaconsole_phonebook;

import java.util.Scanner;

/**
 *
 * @author mhcrnl
 */
public class JavaConsole_PhoneBook {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int select;
        Controller controller = new Controller();
        Scanner in = new Scanner(System.in);
        do{
            // Meniul aplicatiei
            System.out.println("=============== <> MENIU <> =================");
            System.out.println("============<> 1 ADAUGA COMTACT  ============");
            System.out.println("============<> 2 AFISEAZA CONTACTE ==========");
            System.out.println("============<> 4 INCHIDE APLICATIA ==========");
            
            select = in.nextInt();
            int number =1;
            switch(select){
                case 1:
                    controller.adaugaContact();
                    
                    break;
                case 2:
                    controller.afiseazaContact();
                    
                    break;
                case 4:
                        
            }
        } while (select !=4);
        
        
    }
    
}
