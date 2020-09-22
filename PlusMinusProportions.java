/**
Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. 
Print the decimal value of each fraction on a new line with  places after the decimal.

Sample Input
6  <- number of input
-4 3 -9 0 4 1         

Sample Output

0.500000
0.333333
0.166667

Expl: There are 3 positive inputs, hence 3/6 == 0.500000 
      There are 2 negative inputs, hence 2/6 == 0.333333
      There are 1 zero inputs,     hence 1/6 == 0.166667
*/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the plusMinus function below.
    static void plusMinus(int[] arr) {

        float n = 0, p = 0, z = 0;

        for(int i = 0; i < arr.length; i++) {

            if(arr[i] < 0) {
                n++;
            } else if(arr[i] > 0) {
                p++;
            } else {
                z++;
            }
        }

        System.out.printf("%6f%n", (proportion(p, arr))); //format 6 decimals places
        System.out.printf("%6f%n", (proportion(n, arr))); //format 6 decimals places
        System.out.printf("%6f%n", (proportion(z, arr))); //format 6 decimals places
    }

    //helper
    static float proportion(float n, int[] arr) {
        return n/arr.length;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        plusMinus(arr);

        scanner.close();
    }
}
