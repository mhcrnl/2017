/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Test;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

/**
 *
 * @author mhcrnl
 */
public class CopyCharacterStream {
    
    static String inputFile = "Contact.txt", outputFile = "fwContact.txt";
    
    public void copyCharacterStream(String inputFile, String outputFile)throws IOException{
        
        Reader fr = null;
        Writer fw = null;
        
        try {
             fr = new FileReader(inputFile);
             fw = new FileWriter(outputFile);
            
            int c;
            while((c = fr.read()) != -1){
                fw.write(c);
            }
            
        } finally {
            if(fr != null){
                fr.close();
            }
            if(fw != null){
                fw.close();
            }
        }
    }
    public static void main(String[] args) throws IOException {
        CopyCharacterStream ccs = new CopyCharacterStream();
        ccs.copyCharacterStream(inputFile, outputFile);
    }
    
}
