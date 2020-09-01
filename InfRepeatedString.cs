/**
Hackerrank Problem: Infinite Repeated String
Difficulty: Easy

Lilah has a string, , of lowercase English letters that she repeated infinitely many times.
Given an integer, , find and print the number of letter a's in the first  letters of Lilah's infinite string.
For example, if the string  and , the substring we consider is , the first  characters of her infinite string. 
There are  occurrences of a in the substring.

Output Format
Print a single integer denoting the number of letter a's in the first  letters of the infinite string created by repeating  infinitely many times.
-----
Sample Input 0
aba
10
-----
Sample Output 0
7
---
Solution:
    count the occurrences of char in string, mulitply by the number of times the string repeats given length of n, then add any remainder 
    using modulus.  

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

    // Complete the repeatedString function below.
    static long repeatedString(string s, long n) {

        long count = 0;
        //count the number of occurrences in the string for 'a'
        foreach(char i in s){
            if(i.Equals('a')) count++;
        }
        Console.WriteLine(count);
        //found out how many times the line repeats, then multiple
        long repitition = n / s.Length;
        count = count * repitition;

        //check the remainder to see if 'a' occurs, then add to count.
        for(int i = 0; i < n % s.Length; i++){
            if(s[i].Equals('a')) count++;
        }
        return count;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        long n = Convert.ToInt64(Console.ReadLine());

        long result = repeatedString(s, n);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
