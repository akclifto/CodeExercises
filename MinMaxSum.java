/**
Hackerrank problem: https://www.hackerrank.com/challenges/mini-max-sum/problem

Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. 
Then print the respective minimum and maximum values as a single line of two space-separated long integers.

Sample Input
1 2 3 4 5
Sample Output
10 14

Expl:  min -> 1 + 2 + 3 + 4 = 10
       max -> 2 + 3 + 4 + 5 = 14

*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) {

        long min = 0, max = 0;
        Arrays.sort(arr);

        for(int i = 0; i < arr.length; i ++) {

            //find min, ignore the last index position
            if(i == arr.length - 1) {
                max += arr[i];
            //find max, ignore the first index position
            } else if(i == 0) {
                min += arr[i];
            // sum each on iteration.
            } else {
            min += arr[i];
            max += arr[i];
            }
        }
        System.out.println(min + " " + max);

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[5];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 5; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        miniMaxSum(arr);

        scanner.close();
    }
}
