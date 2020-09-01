/**
Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, and he wants to maximize the number of toys he buys with this money.

Given a list of prices and an amount to spend, what is the maximum number of toys Mark can buy? For example, if prices = [1, 2, 3, 4] and Mark has k = 7 to spend, he can buy items [1, 2, 3] for 6, or [3, 4] for 7 units of currency. 
He would choose the first group of 3 items.

Sample Input
7 50
1 12 5 111 200 1000 10

Sample Output
4

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

    // Complete the maximumToys function below.
    static int maximumToys(int[] prices, int k) {

        //sort acending
        Array.Sort(prices);

        //loop through and reduce amount k for each item in prices array
        //foreach not helpful here because we need to access the index of prices as a 'counting' measure.
        //foreach uses IEnumerator, and indexing isn't supported.
        for(int i = 0; i < prices.Length; i++) {
            k = k - prices[i];
            //if out of money k, return i (ie, the max number of items we are able to purchase)
            if(k < 0){
                return i;
            }
        }
        //If k > 0, we have money left over, and can buy everything in the prices array, so return the full length.
        return prices.Length;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string[] nk = Console.ReadLine().Split(' ');

        int n = Convert.ToInt32(nk[0]);

        int k = Convert.ToInt32(nk[1]);

        int[] prices = Array.ConvertAll(Console.ReadLine().Split(' '), pricesTemp => Convert.ToInt32(pricesTemp))
        ;
        int result = maximumToys(prices, k);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
