/*
	Hackerrank Difficulty: Easy
	The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.

	Laura plants a Utopian Tree sapling with a height of 1 meter at the onset of spring. How tall will her tree be after  growth cycles?

	For example, if the number of growth cycles is , the calculations are as follows:

	Period  Height
	0          1		//if n = 0, then h + 1
	1          2		// h * 2
	2          3		// h + 1 , ... ,
	3          6		// h * 2 , ... ,  
	4          7
	5          14
*/

public class Solution {

    // Complete the utopianTree function below.
    static int utopianTree(int n) { //n cycles
        
        int height = 0;
        
        for(int i = 0; i <= n; i++) {
            
            if(i % 2 == 1) {
                height *= 2;
            } else {
                height += 1;
            }
        }    
        return height;
    }
	

	public static void main(String[] args){
	
		int ans = -1;
		
		for(int i = 0; i <= 7 ; i++) {
		
			ans = utopianTree(i);
			System.out.println("tree height: " + ans);
		}
	}
	
}
