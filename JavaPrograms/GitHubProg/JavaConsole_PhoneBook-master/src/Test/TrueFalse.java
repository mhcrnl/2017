/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test;

/**
 *
 * @author mhcrnl
 */
public class TrueFalse {
    public static void main(String[] args) {
       boolean a= true;
       boolean b =false;
       boolean c = true;
        System.out.println("a&&b" + (a&&b));
        System.out.println("(a||b)&&c"+((a||b)&&c));
        System.out.println("a||b "+(a&&b));
        System.out.println("a&&b"+(a&&b));
    }
}
