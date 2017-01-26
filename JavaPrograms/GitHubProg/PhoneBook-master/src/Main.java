package src;

import java.util.Scanner;

/**
 * Created by homic1de on 28.10.2014.
 */
public class Main {
    private static Book book = new Book();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String... agrs){
        while(true) {
            menu();
        }


    }
    private static void menu(){
        System.out.println("Enter 1 - to show all users");
        System.out.println("Enter 2 - to add a user");
        System.out.println("Enter 3 - to delete a user");

        int choose = scanner.nextInt();
        switch (choose){
            case 1:book.show();
                break;
            case 2:add();
                break;
            case 3:delete();
                break;
        }

    }
    private static void delete(){
        System.out.println("Enter index of user which u want to delete");
        int index = scanner.nextInt();
        book.delete(index);
    }
    private static void add(){
        Scanner in = new Scanner(System.in);
        String name,number;
        int age;
        System.out.println("Enter User name");
        name = in.nextLine();

        System.out.println("Enter number");
        number = in.nextLine();

        System.out.println("Enter age");
        age = in.nextInt();

         book.add(name, number, age);





    }
}
