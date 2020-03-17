/*
	Hackerrank Difficulty: Easy
	Complete the countingValleys function in the editor below. It must return an integer that denotes the number of valleys Gary traversed.

	countingValleys has the following parameter(s):

	n: the number of steps Gary takes
	s: a string describing his path
	Input Format

	The first line contains an integer , the number of steps in Gary's hike.
	The second line contains a single string , of  characters that describe his path.
	Sample Input

	8
	UDDDUDUU
	Sample Output

	1
	Explanation

	If we represent _ as sea level, a step up as /, and a step down as \, Gary's hike can be drawn as:

	_/\      _
	   \    /
		\/\/
	He enters and leaves one valley.

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

    // Complete the countingValleys function below.
    static int countingValleys(int n, string s) {

        int valleys = 0;
        int floor = 0;

        foreach(char i in s){
            
            if(i == 'D') {
                floor--;
            } 
            if(i == 'U') {
                floor++;
            }

            if(floor == 0 && i == 'U') {
                valleys++;
            }
        }
        return valleys;
    }

    static void Main(string[] args) {
		
		int n = 8;
		String s = "UDDDUDUU";
		//should output 1 as result
		int result = countingValleys(n, s);
		Console.WriteLine(result);	
    }
}

