/*
 *  Hackerrank Difficulty: Easy.
 *
 * Count the number of pairs in a randomly sorted array.
 * Complete the sockMerchant function in the editor below. It must return an integer representing
 * the number of matching pairs of socks that are available.
 *
 * sockMerchant has the following parameter(s):
 *      n: the number of socks in the pile
 *      ar: the colors of each sock
 *
 * SOLUTION:  Sort the array, loop through and count pairs of ar[i] and ar[i + 1].
 *      If there is, increment count and i.
  */

using System;

class Solution
{

    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar)
    {
        int count = 0;

        Array.Sort(ar);
        for (int i = 0; i < n - 1; i++)
        {
            if (ar[i] == ar[i + 1])
            {
                count++;
                i++;
            }
        }

        return count;
    }

    static void Main(string[] args)
    {

        int n = 10;
        int[] ar = {10, 20, 20, 10, 10, 30, 50, 10, 20, 50};
        int result = sockMerchant(n, ar);

        Console.WriteLine(result);
    }
}