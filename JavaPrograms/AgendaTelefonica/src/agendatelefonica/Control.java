/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package agendatelefonica;
import java.util.Scanner;
/**
 *
 * @author mhcrnl
 */
public class Control {
    private static Agenda agenda = new Agenda();
    private static Scanner scanner = new Scanner(System.in);
    
    public static void meniu(){
        int alegere;
        do{
            System.out.println("1. Afisarea contactelor.");
            System.out.println("2. Adaugarea unui contact.");
            System.out.println("3. Stergerea unui contact.");
            System.out.println("4. Exit din program.");
            alegere = scanner.nextInt();
            switch(alegere){
                case 1:
                    Agenda.afiseaza();
                    break;
                case 2:
                    adauga();
                    break;
                case 3:
                    sterge();
                    break;
                case 4: 
                    System.exit(0);
            }
        } while(alegere != 4);
    }
    private static void sterge(){
        System.out.println("Introduceti indexul contactului de sters: ");
        int index = scanner.nextInt();
        agenda.sterge(index);
    }
    private static void adauga(){
        Scanner in = new Scanner(System.in);
        String nume, prenume, nrTel;
        System.out.println("Introduceti numele contactului: ");
        nume = in.nextLine();
        System.out.println("Introduceti prenumele contactului: ");
        prenume = in.nextLine();
        System.out.println("Introduceti numarul de telefon: ");
        nrTel = in.nextLine();
        
        agenda.adauga(nume, prenume, nrTel);
    }
}
