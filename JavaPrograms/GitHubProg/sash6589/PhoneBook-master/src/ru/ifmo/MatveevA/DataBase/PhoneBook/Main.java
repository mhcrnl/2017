package ru.ifmo.MatveevA.DataBase.PhoneBook;

import java.io.File;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String path;

        System.out.println("Please enter the path to the file where the data is stored");

        Scanner in = new Scanner(System.in);

        path = in.next();

        PhoneBook book = new PhoneBook(path);

        book.start();
    }
}
