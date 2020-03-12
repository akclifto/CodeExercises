/*
 Reverse words in a given string.

 *Examples:
    Input: s = “geeks quiz practice code”
    Output: s = “code practice quiz geeks”

    Input: s = “getting good at coding needs a lot of practice”
    Output: s = “practice of lot a needs coding at good getting”
 *
 * SOLUTION: reverse each letter in the string, then reverse each word in the string
 */

using System;

namespace ReverseStringWords
{
    class ReverseString
    {
        static void Main()
        {
            string[] lines = "write this from front to back".Split(' ');
            DisplayString(lines);
            DisplayReversed(lines);
            Console.WriteLine();

        }


        static void DisplayString(string[] lines)
        {
            Console.Write("String to Reverse: \t");
            foreach (string line in lines)
            {
                Console.Write(line + " ");
            }
            Console.WriteLine();
        }


        static void DisplayReversed(string[] lines)
        {

            string answer = "";

            for (int i = lines.Length - 1; i >= 0; i--)
            {
                answer = answer + lines[i] + " ";
            }

            Console.Write("Reversed String: \t");
            Console.Write(answer.Substring(0, answer.Length - 1));
        }

    }
}
