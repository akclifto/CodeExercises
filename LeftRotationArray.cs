/**
A left rotation operation on an array shifts each of the array's elements  unit to the left. For example, if  left rotations are performed on array , then the array would become .

Given an array  of  integers and a number, , perform  left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.
An array of integers a.
An integer d, the number of rotations.

Solution:  loop through, then position at b[i] equals a at (i + number of rotations) % length of a. 
    Ex: a with length 3:: --> b[0] = a[(0 + 4) % a.Length] = b[0] equals a[4 % 3] == a[1], so b[0] = a[1] 
        then move to next loop position b[1]
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

    // Complete the rotLeft function below.
    static int[] rotLeft(int[] a, int d) {

        int[] b = new int[a.Length];

        for(int i = 0; i < a.Length; i++){
            b[i] = a[(i + d) % a.Length];
        }

        return b;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string[] nd = Console.ReadLine().Split(' ');

        int n = Convert.ToInt32(nd[0]);

        int d = Convert.ToInt32(nd[1]);

        int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp))
        ;
        int[] result = rotLeft(a, d);

        textWriter.WriteLine(string.Join(" ", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
