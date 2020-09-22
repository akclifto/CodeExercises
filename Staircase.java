/**
Hackerrank problem: https://www.hackerrank.com/challenges/staircase/problem

Sample Input
6 
Sample Output

     #
    ##
   ###
  ####
 #####
######

Expl:  print hashes with one space, right justified given an int.

*/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the staircase function below.
    static void staircase(int n) {
        
        //this is a pain in java. makes a char array, fill with blanks.
        // if using string, requires override toString()
        char[] arr = new char[n];
        Arrays.fill(arr, ' ');

        //loop through, & fill with # starting at end of arr, move backwd at ith pos.  
        // arr[n - i] --> arr[6 - i(ex, 2)] = puts you at 2nd to last position.
        //print each iter
        for(int i = 1; i <= n; i++) {
            arr[n - i] = '#';
            System.out.println(arr);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        staircase(n);

        scanner.close();
    }
}
