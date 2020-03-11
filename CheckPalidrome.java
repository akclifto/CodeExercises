/**  LeetCode difficulty: Easy

		Determine whether an integer is a palindrome. 
		An integer is a palindrome when it reads the same backward as forward.
 
*/

/*runtime: 11ms*/
class Solution {  //convert to string and check (my solution)
    public boolean isPalindrome(int x) {
        
        String reverse = new StringBuffer(String.valueOf(x)).reverse().toString();
        
        if(String.valueOf(x).equals(reverse)) {
            return true;
        } else 
            return false;
        
    }
}

/*runtime: 7ms */
class Solution2 { //solution pulled from discussion, no conversion
	
	//for negative integers and multiples of 10 (except 0) ==> are not palindromes
	if(x < 0 || x != 0 && x % 10 == 0) {
		return false;
	}
	
	int remain = 0;
	while(x > remain) {
		
		int temp = x % 10;
		remain = remain * 10 + temp;
		x /= 10;
	}
	//left checks even palindrome, right check odd palindrome
	return (x == remain || x == remain / 10);
	
}