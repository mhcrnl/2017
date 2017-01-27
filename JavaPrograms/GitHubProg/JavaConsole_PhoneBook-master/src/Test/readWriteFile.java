/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author mhcrnl
 */
public class readWriteFile {
    
    static String inputFile = "Contact.txt", outputFile = "outContact.txt";
    
    public void ReadWriteFile(String inputFile, String outputFile) throws IOException{
        
        FileInputStream fis = null;
        FileOutputStream fos = null;
        
        try{
            fis = new FileInputStream(inputFile);
            fos = new FileOutputStream(outputFile);
            
            int c;
            while((c=fis.read()) != -1){
                fos.write(c);
            }
        } finally {
            if(fis != null){
                fis.close();
            }
            if(fos != null){
                fos.close();
            }
        }
        
    }
    
    public static void main(String[] args) {
        
        readWriteFile rw = new readWriteFile();
        try {
            rw.ReadWriteFile(inputFile, outputFile);
        } catch (IOException ex) {
            Logger.getLogger(readWriteFile.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
