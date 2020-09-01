/**
Given an array of integers, sort the array in ascending order using the Bubble Sort algorithm above. Once sorted, print the following three lines:

Array is sorted in numSwaps swaps., where  is the number of swaps that took place.
First Element: firstElement, where  is the first element in the sorted array.
Last Element: lastElement, where  is the last element in the sorted array.

Hint: To complete this challenge, you must add a variable that keeps a running tally of all swaps that occur during execution.
For example, given a worst-case but small array to sort:  we go through the following steps:

swap    a       
0       [6,4,1]
1       [4,6,1]
2       [4,1,6]
3       [1,4,6]
It took 3 swaps to sort the array. Output would be

Array is sorted in 3 swaps.  
First Element: 1  
Last Element: 6  

*/

using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    // Complete the countSwaps function below.
    static void countSwaps(int[] a) {

        int count = 0;

        for(int i = 0; i < a.Length; i++) {

            for(int j = 0; j < a.Length - i - 1; j++) {
                if(a[j] > a[j + 1]) {

                    swap(a, j, j + 1);
                    count++;
                }
            }
        }
        Console.WriteLine("Array is sorted in {0} swaps.", count);
        Console.WriteLine("First Element: {0}", a[0]);
        Console.WriteLine("Last Element: {0}", a[a.Length - 1]);
    }

    static void swap(int[]a, int pos1, int pos2) {

        // int temp = a[j];
        // a[j] = a[j + 1];
        // a[j + 1]= temp;
        
        int temp = a[pos1];
        a[pos1] = a[pos2];
        a[pos2] = temp; 

    }

    static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());

        int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp))
        ;
        countSwaps(a);
    }
}
