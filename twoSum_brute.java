/**LEETCODE : Difficulty : Easy 

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

RUNTIME: 59ms
*/
class Solution {
    
    
    public int[] twoSum(int[] nums, int target) {
     //basically the leetcode sol for brute force
        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                
                if(nums[j] == (target - nums[i])) {
                    return new int[] {i,j};
                }
            }
        }
        //if fail
        throw new IllegalArgumentException("Two Sum failed.");
    }
}
