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
public class Contact {
   public String _nume;
   public String _prenume;
   public String _nrTel;
   
   public Contact(String nume, String prenume, String nrTel){
       _nume = nume;
       _prenume = prenume;
       _nrTel = nrTel;
   }
   public void setNume(String nume){
       _nume = nume;
   }
   public String getNume(){
       return _nume;
   }
   public void setPrenume(String prenume){
       _prenume = prenume;
   }
   public String getPrenume(){
       return _prenume;
   }
   public void setNrTel(String nrTel){
       _nrTel = nrTel;
   }
   public String getNrTel(){
       return _nrTel;
   }
   @Override
   public String toString(){
       return _nume+" "+_prenume+" "+_nrTel;
   }
}
