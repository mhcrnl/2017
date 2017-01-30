/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafactorypattern;

/**
 * 
 * Modelul Factory este cel mai utilizat model de programare in Java.
 * @author mhcrnl
 */
//PASUL:1 Crearea unei interfete
interface Shape{
    void draw();
} 
//PASUL:2 Crearea de clase concrete care sa implementeze interfata.
class Dreptunghi implements Shape {
    @Override
    public void draw(){
        System.out.println("DREPTUNGHI::draw");
    }
}
class Cerc implements Shape{
    @Override
    public void draw(){
        System.out.println("CERC::draw");
    }
}
class Triunghi implements Shape{
    @Override
    public void draw(){
        System.out.println("TRIUNGHI::draw");
    }
}
//PASUL:3 Crearea unei Factory pt. a genera obiecte din clasele concrete.
class ShapeFactory{
    public Shape getShape(String shapeType){
        if(shapeType == null){
            return null;
        }
        if(shapeType.equalsIgnoreCase("DREPTUNGHI")){
            return new Dreptunghi();
        }
        if(shapeType.equalsIgnoreCase("CERC")){
            return new Cerc();
        }
        if(shapeType.equalsIgnoreCase("TRIUNGHI")){
            return new Triunghi();
        }
        return null;
    }
}
//PASUL:4 Utilizarea fabricii pt. a obtine obiectele.
public class JavaFactoryPattern {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ShapeFactory fabrica = new ShapeFactory();
        Shape forma1 = fabrica.getShape("DREPTUNGHI");
        forma1.draw();
        Shape cerc = fabrica.getShape("cerc");
        cerc.draw();
        Shape triunghi = fabrica.getShape("TRiunghi");
        triunghi.draw();
    }
    
}
