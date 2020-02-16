/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

*/

int reverse(int x){

    long result = 0;
    
    while(x !=0) {
        
        int last = x % 10;
        x = x / 10;
        result =  result * 10 + last;
    }
    
    if(result > INT_MAX || result < INT_MIN) {
        //fail
        return 0;
    }
    return (int)result;
}
