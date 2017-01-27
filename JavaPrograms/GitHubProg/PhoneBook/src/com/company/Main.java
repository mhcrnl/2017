package com.company;

import com.sun.org.apache.xpath.internal.SourceTree;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    /*
    1 - Add contact
    2 - Remove contact
    3 - Show all contacts
    4 - Quit
     */

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        ArrayListNew al = new ArrayListNew();
        Contact curCont;

        while (true) {
            System.out.println(" 1 - Add contact\n" +
                    " 2 - Remove contact\n" +
                    " 3 - Show all contacts\n" +
                    " 4 - Edit contacts\n" +
                    " 5 - Quit");

            int in = scanner.nextInt();

            if (in == 1) {
                System.out.println("Input name:");
                String name = scanner.next();
                System.out.println("Input phone:");
                String phone = scanner.next();
                System.out.println("Input age:");
                int age = scanner.nextInt();
                Contact ct = new Contact(name, phone, age);
                al.add(ct);
                al.sort();
            } else if (in == 2) {
                System.out.println("Input name:");
                String name = scanner.next();
                al.remove(name);
            } else if (in == 3) {
                for (int i = 0; i < al.size(); i++) {
                    System.out.println(al.get(i).name + " " + al.get(i).phone);
                }
            } else if (in == 4) {
//                boolean find = false;
//               // Contact curCont;
//                String curName;
//                while (true) {
//                    System.out.println("Input name edit contact:");
//                    curName = scanner.next();
//
//                    for (Contact ncal : al) {
//
//                        if (ncal.name.equals(curName)) {
//                            find = true;
//                            curCont = ncal;
//                            break;
//                        }
//                    }
//                    if (find) {
//                        break;
//                    } else {
//                        System.out.println("Контакт не найден:");
//                        System.out.println(" 1 - Еще раз\n" +
//                                           " 2 - Отменить\n");
//                        in = scanner.nextInt();
//                        if (in == 2) {
//                            break;
//                        }
//                    }
//                }
//                if (find) {
//                    while (true) {
//                        System.out.println(" 1 - Edit name\n" +
//                                " 2 - Edit phone\n" +
//                                " 3 - Edit age\n" +
//                                " 4 - Edit contacts\n" +
//                                " 5 - Enter\n" +
//                                " 6 - Quit");
//                        in = scanner.nextInt();
//                        if (in == 1) {
//                            System.out.println("Input new name contact:");
//                            String newName = scanner.next();
//                            for (Contact ncal : al) {
//
//                                if (ncal.name.equals(curName)) {
//                                    ncal.name = newName;
//                                    break;
//                                }
//                                break;
//                            }
//                        } else if (in == 2) {
//                            System.out.println("Input new name phone:");
//                            String newphone = scanner.next();
//                            for (Contact ncal : al) {
//
//                                if (ncal.name.equals(curName)) {
//                                    ncal.phone = newphone;
//                                    break;
//                                }
//                                break;
//                            }
//                        }else if (in == 6) {
//                            break;
//                        }
//
//                    }
//                }
            } else if (in == 5) {
                break;
            } else {
                System.out.println("Return input.");
            }
        }
    }
}
