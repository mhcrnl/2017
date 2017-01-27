package com.company;

public class Contact {
    public String name;
    String phone;
    int age;

    public Contact(String name,String phone,int age){
        this.name = name;
        this.phone = phone;
        this.age = age;
    }

    public String  toString(Contact c){
       return "Name: "+c.name+" Phone: " + c.phone + " age: " + c.age;
    }
}