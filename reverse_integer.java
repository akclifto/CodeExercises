/** 
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
*/

class Solution {
    public int reverse(int x) {
        
        long result = 0;
        int remainder = 0;
        
        while(x != 0) {
            
            remainder = x % 10;
            x = x / 10;
            result = result * 10 + remainder;
        }
        
        //failing case.
        if(result < Integer.MIN_VALUE || result > Integer.MAX_VALUE) {
            return 0;
        }
        
        return (int) result;        
    }
}
