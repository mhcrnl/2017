/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package agendatelefonica;

/**
 *
 * @author mhcrnl
 */
public class AgendaTelefonica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Salut din Agenda Telefonica.");
        //ReadmeFile readme = new ReadmeFile();
        Contact con = new Contact("Mihai", "Cornel", "0722270796");
        System.out.println("CONTACT: "+con.toString());
        //readme.scrieReadme();
        while(true){
            Control.meniu();
        }
        
    }
    
}
