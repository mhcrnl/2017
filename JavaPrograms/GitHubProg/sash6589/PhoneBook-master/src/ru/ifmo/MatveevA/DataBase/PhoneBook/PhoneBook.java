package ru.ifmo.MatveevA.DataBase.PhoneBook;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class PhoneBook {
    private String path;

    private Map<String, String > dataBase;

    public PhoneBook(String path) {
        String[] result = {};
        dataBase = new HashMap<String, String>();

        this.path = path;


        if (new File(this.path).exists()) {
            try {
                Scanner in = new Scanner(new File(this.path));
                StringBuffer data = new StringBuffer();

                while (in.hasNext()) {
                    data.append(in.nextLine()).append("\n");
                    String s = data.toString();
                    int index = s.indexOf(" ");
                    dataBase.put(s.substring(0, index), s.substring(index + 1, s.length()));
                    data.delete(0, data.length());
                }

                in.close();
            } catch ( Exception ex ) {
                ex.printStackTrace();
            }
        }
    }

    private String get(String s) {
        if (dataBase.containsKey(s)) {
            return dataBase.get(s);
        }
        else {
            return "contact does not exist\n";
        }
    }

    private String add(String key, String value) {
        dataBase.put(key, value);

        return "Done\n";
    }

    private String delete(String s) {
        if (dataBase.containsKey(s)) {
            dataBase.remove(s);
        }
        return "Done\n";
    }

    private String update(String key, String value) {
        if (dataBase.containsKey(key)) {
            delete(key);
            add(key, value);
        }

        return "Done\n";
    }

    public void start() {
        Scanner sc = new Scanner(System.in);
        String s;

        do {
            System.out.println("Enter request!");
            System.out.println("ADD <nickname> <Number, Name>");
            System.out.println("GET <nickname>");
            System.out.println("UPDATE <nickname> <newNumber, newPhone>");
            System.out.println("DELETE <nickname>");
            System.out.println("If you want to exit, enter " +'"' + "FINISH" + '"');

            s = sc.next();

            if ("GET".equals(s)) {
                String nickname = sc.next();
                System.out.println(get(nickname));
            }
            if ("ADD".equals(s)) {
                String nickname = sc.next();
                String value = sc.nextLine();
                value += "\n";
                System.out.println(add(nickname, value));
            }

            if ("DELETE".equals(s)) {
                String nickname = sc.next();
                System.out.println(delete(nickname));
            }

            if ("UPDATE".equals(s)) {
                String nickname = sc.next();
                String value = sc.nextLine();
                value += "\n";
                System.out.println(update(nickname, value));
            }
        } while (!("FINISH".equals(s)));

        try {
            File flt = new File(this.path);

            FileWriter wrt = new FileWriter(flt);

            for (Map.Entry<String, String> entry: dataBase.entrySet()) {
                wrt.append(entry.getKey() + entry.getValue() + "\n");
            }
            wrt.flush();
            wrt.close();
        } catch(Exception e) {
            e.printStackTrace();
        }
        sc.close();
    }
}
