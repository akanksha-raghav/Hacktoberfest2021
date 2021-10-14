package org.codeforcause.jdsa.lecture13;

import java.util.Arrays;

public class LexoPermute {
    public static void main(String[] args) {
//        String str = "aaceeeeeeeeebbccccaaaa";
//        int[] freq = freqMatrix(str);
//        System.out.println(Arrays.toString(freq));
        String s = "aab";
        lexoPermute("",freqMatrix(s), s.length());
    }

    private static void lexoPermute(String proc, int[] freqMatrix, int length) {
        if (length == 0) {
            System.out.println(proc);
            return;
        }
        for (int i = 0; i < freqMatrix.length; i++) {
            if (freqMatrix[i] > 0) {
                freqMatrix[i]--;
                lexoPermute(proc+(char)(i+'a'),freqMatrix,length-1);
                freqMatrix[i]++;
            }
        }
    }

    private static int[] freqMatrix(String str) {
        int[] freq = new int[26];
        for (int i = 0; i < str.length(); i++) {
            int ind = str.charAt(i) - 'a';
            freq[ind]++;
        }
        return freq;
    }
}
