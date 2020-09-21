// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

/**
Codility lesson:  Binary Gap
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

class Solution { public int solution(int N); }

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/


class Solution {
    public int solution(int N) {
        
        
        //convert int to binary string, then to char[]
        String s = Integer.toBinaryString(N);
        char[] ch = s.toCharArray();
        int gap = 0, j = 0;
        
        //base case
        if(N == 0) {
            return 0;
        }
        
        //remove trailing zeroes (1000) becomes (1)
        while(N % 2 == 0){
            N = N / 2;
        }
        
        //loop through ch[], if c is 0, start the count, if c is 1, reset count
        //if gap greater than the current gap
        for(char c : ch){
            if(c =='0') {
                j++;
            }
            if(c == '1') {
                if (j > gap) {
                    gap = j;
                }
                j = 0;
            }
        }
        return gap;
        
    }
