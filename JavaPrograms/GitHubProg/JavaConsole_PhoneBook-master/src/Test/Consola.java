/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test;

import java.io.Console;

/**
 *
 * @author mhcrnl
 */
public class Consola {
    
    public static void main(String[] args) {
        Console c = System.console();
        
        if(c == null){
            System.out.println("Sistemul nu are consola!");
            System.exit(1);
        }
        
        String nume = c.readLine("Introduce-ti numele: ");
        System.out.println(nume);
    }
    
}
