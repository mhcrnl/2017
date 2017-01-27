/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaconsole_phonebook1;

/**
 *
 * @author mhcrnl
 */
public class ContactMain {
    
    public static void main(String[] args) {
        
        String file = "contacte.txt";
        
        ControllerV01 controller = new ControllerV01();
        Contact[] contact1 = null, contact2 = null;
        
        
        contact1 = controller.creats();
        controller.write(file, contact1);
        contact2 = controller.read(file);
        controller.show(contact2);
    }
    
}
