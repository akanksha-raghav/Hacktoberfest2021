package com.akanksha.class1;

public class Inverse {
    public static void main(String[] args) {
        int num = 25134;
        System.out.println(inverse(num));
    }

    private static int inverse(int num) {
        int pos = 1, res = 0;
        while (num > 0) {
            int r = num % 10;
            res = res + pos * (int)Math.pow(10, r-1);
            num /= 10;
            pos++;
        }
        return res;
    }

}
