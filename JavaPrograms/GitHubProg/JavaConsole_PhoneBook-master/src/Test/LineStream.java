/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mhcrnl
 */
public class LineStream {
    
    static String inputFile = "Contact.txt", outputFile = "pwContact.txt";
    
    public void lineStream(String inputFile, String outputFile) throws IOException{
    
    BufferedReader bf = null;
    PrintWriter pw = null;
    
    try { 
        bf = new BufferedReader(new FileReader(inputFile));
        pw = new PrintWriter(new FileWriter(outputFile));
         
        String line;
        while((line = bf.readLine()) != null){
            pw.println(line);
        }
        } finally {
            if(bf != null){
                bf.close();
            }
            if(pw != null){
                pw.close();
            }
        }
    }
    
    public static void main(String[] args) {
        LineStream ls = new LineStream();
        try {
            ls.lineStream(inputFile, outputFile);
        } catch (IOException ex) {
            Logger.getLogger(LineStream.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
