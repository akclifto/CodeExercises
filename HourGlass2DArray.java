/**
https://www.hackerrank.com/challenges/2d-array/problem

Function Description
Complete the function hourglassSum in the editor below.

hourglassSum has the following parameter(s):
int arr[6][6]: an array of integers

Returns
int: the maximum hourglass sum

Sample Input
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output
19

*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the hourglassSum function below.
    static int hourglassSum(int[][] arr) {

        // //get the input from the 
        // int matr[][] = new int[6][6];
        // for(int i = 0; i < arr.length; i++){
        //     for(int j = 0; j < arr[i].length; j++){
        //         matr[i][j] = arr[i][j];
        //     }
        // }

        int maxSum = -64; //min it could be is -9 * 7 = -63. could use Integer.MIN_VALUE
        int startCol = 0;

        //each iter for the outer loop is one hour glass
        for(int r = 0; r <= 3; r++) {
            int sum = 0; //holds hourglass sum

            for(int c = startCol; c < startCol + 3; c++) {

                sum = sum + arr[r][c];  //this gets the index of the current row/col
                if(c == startCol) { // this makes sure we're on the middle piece of the hour glass
                    sum = sum + arr[r + 1][c + 1];
                }
                sum = sum  + arr[r + 2][c]; //gets corresp index in bottom row
            }
            //if space for abother hourglass(hg) in this row, goto next col
            startCol = (startCol < 3) ? startCol + 1 : 0;
            //if enough space for another hg in row, conti in same row 
            if(startCol != 0) { 
                r--; //decr in order to do this bc for loop increments
            }
            if(sum > maxSum) {
                //this holds the max that we will return
                maxSum = sum;
            }
        }
        return maxSum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
