package src;

import java.util.ArrayList;

/**
 * Created by homic1de on 28.10.2014.
 */
public class Book {
    public static ArrayList users = new ArrayList();

    public static void add(String name, String number, int age){
        User user = new User(name, number,age);
        users.add(user);
        order();


    }

    public static void order(){
        int arraySize = users.size();
        if(arraySize>1 ){

            for(int i=0; i<arraySize -1;i++){
                for(int a=0; a<arraySize -1 -i;a++){
                    User user1 = (User) users.get(a);
                    User user2 = (User) users.get(a+1);
                    if(user1.age>user2.age){
                        users.set(a,user2);
                        users.set(a+1,user1);
                    }

                }

            }

        }

    }

    public static void delete(int index){
        users.remove(index);


    }
    public static void show(){
        for(int i = 0; i< users.size(); i++){
            User user = (User) users.get(i);
            System.out.println(i+ " "+ user.name + " " +user.number +" " +user.age);

        }

    }

}

