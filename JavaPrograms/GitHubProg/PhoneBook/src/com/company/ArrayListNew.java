package com.company;

/**
 * Created by admin on 27.06.2015.
 */
/*
1) ������� ������ � ���� �������
2) ������ ������ ������ ���� ������ ��� ���������� � �������� ���������
3) ���������� ��������, �������� �������� �� �����, ������� �� �������, ��������� �������� �� �������
 */
public class ArrayListNew {

    private  Contact[] currentDate;
    private int size;
    public ArrayListNew(){
        currentDate = new Contact[1];
        size = 0;
    }

    public void add(Contact c) {
        Contact[] nc = new Contact[size + 1];
        for (int i=0; i < size; i++){
            nc[i] = currentDate[i];
        }
        nc[size] = c;
        currentDate = nc;
        size++;
    }

    public boolean remove(String name) {

        for (int i=0; i < size ; i++) {
            if (currentDate[i].name.equals(name)) {
                return this.remove(i);
            }
        }
        return false;
    }

    public boolean remove(int index) {
        if (index > size - 1 || index < 0) {
            return false;
        }
        Contact[] nc = new Contact[size - 1];
        for (int i=0; i < size ; i++){
            if (i < index) {
                nc[i] = currentDate[i];
            } else if (i > index){
                nc[i-1] = currentDate[i];
            }
        }
        currentDate = nc;
        size --;
        return  true;

    }
public void sort(){
    //1. ���������� �� ������ ����� (���� ��������)
    //2. ���������� �� ����� �����
    /*
    Alex
    alexandr
    alexey
     */

    String name1 = "abc";
    String name2 = "bcd";
    char[] arr1 = name1.toCharArray(); // ������ � ������ ��������
    char[] arr2 = name2.toCharArray();
    char ch = name1.charAt(0); // ch = 'a'

    char lowCh = Character.toLowerCase(ch);
    int x = arr1[0];
    int y = arr2[0];

    if (x < y) {
        System.out.println("x<y");
    }

    int a = 5;
    int b = 6;
}
    public boolean remove(Contact c) {
        return remove(c.name);
    }

    public boolean add(Contact c, int index) {
        if (index > size || index < 0) {
            return false;
        }
        if (index == size) {
            add(c);
            return true;
        }
        Contact[] nc = new Contact[size+1];
        for (int i=0; i <= size ; i++){
            if (i < index) {
                nc[i] = currentDate[i];
            } else if (i==index){
                nc[i] = c;
            } else if (i > index){
                nc[i] = currentDate[i-1];
            }
        }
        currentDate = nc;
        size ++;
        return  true;
    }

    public Contact get(int index) {

return currentDate[index];

    }

    public int size(){

        return size;
    }
}
