/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaabstractfactory;

/**
 * java abstract factory pattern
 * @author mhcrnl
 */
interface Shape{
    void draw();
}
class Rectangle implements Shape{
    @Override
    public void draw(){
        System.out.println("Rectangle::draw");
    }
}
class Square implements Shape{
    @Override
    public void draw(){
        System.out.println("Square::draw");
    }
}
class Circle implements Shape{
    @Override
    public void draw(){
        System.out.println("Circle::draw");
    }
}
interface Color{
    void fill();
}
class Red implements Color{
    @Override
    public void fill(){
        System.out.println("Red::fill()");
    }
}
class Green implements Color{
    @Override
    public void fill(){
        System.out.println("Green::fill()");
    }
}
class Blue implements Color{
    @Override
    public void fill(){
        System.out.println("Blue::fill()");
    }
}
abstract class AbstractFactory{
    abstract Color getColor(String Color);
    abstract Shape getShape(String Shape);
}
class ShapeFactory extends AbstractFactory{
    @Override
    public Shape getShape(String shapeType){
        if(shapeType==null){
            return null;
        }
        if(shapeType.equalsIgnoreCase("Circle")){
            return new Circle();
        }
        else if(shapeType.equalsIgnoreCase("RECTANGLE")){
            return new Rectangle();
        }
        else if(shapeType.equalsIgnoreCase("SQUARE")){
            return new Square();
        }
        return null;
    }
    @Override
    Color getColor(String color){
        return null;
    }
}
class ColorFactory extends AbstractFactory{
    @Override
    public Shape getShape(String shapeType){
        return null;
    }
    @Override
    Color getColor(String color){
        if(color == null){
            return null;
        }
        if(color.equalsIgnoreCase("RED")){
            return new Red();
        }
        else if(color.equalsIgnoreCase("GREEN")){
            return new Green();
        }
        else if(color.equalsIgnoreCase("BLUE")){
            return new Blue();
        }
        return null;
    }
}
class FactoryProducer{
    public static AbstractFactory getFactory(String choise){
        if(choise.equalsIgnoreCase("SHAPE")){
            return new ShapeFactory();
        }
        else if(choise.equalsIgnoreCase("CoLOR")){
            return new ColorFactory(); 
        }
        return null;
    }
}
public class JavaAbstractFactory {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        AbstractFactory shapeFactory = FactoryProducer.getFactory("SHAPE");
        Shape shape1 = shapeFactory.getShape("Circle");
        shape1.draw();
        
        Shape shape2 = shapeFactory.getShape("RECTANGLE");
        shape2.draw();
        
        Shape shape3 = shapeFactory.getShape("SQUARE");
        shape3.draw();
        
        AbstractFactory colorFactory = FactoryProducer.getFactory("COLOR");
        Color color1 = colorFactory.getColor("RED");
        color1.fill();
        
        Color color2 = colorFactory.getColor("Green");
        color2.fill();
        
        Color color3 = colorFactory.getColor("BLUE");
        color3.fill();
    }
    
}
