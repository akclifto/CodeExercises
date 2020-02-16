
/** LeetCode:  Difficulty: Easy
 * Note: The returned array must be malloced, assume caller calls free().
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 *RUNTIME: 59ms
 */

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *ret = malloc(sizeof(int) * 2);
    int i, j, comp;
    int *data = nums;
    
    for(i = 0; i < numsSize; i++) {
        //find compliment to target
        comp = target - data[i];
        //printf("Comp: % d \n", comp);

        for(j = 1; j < numsSize; j++) {
            //printf("data[j]: %d \n", data[j]);
            //find match
            if(comp == data[j]) {
                ret[0] = i;
                ret[1] = j;
                printf("Match found.\n");
                return ret;
            }
        }
    }
    //failed to find two sum
    return (int*)-1;
}


void main() {

    int arr[6] = {11,1, 8, 7, 2, 5};
    int target = 7;
    int *val = (int*)malloc(sizeof(int) * 2);
    //printf("size: %d\n", sizeof(arr) / sizeof(int));
    val = twoSum(arr, 6, target, (int*)sizeof(int));
    printf("\nret: %d %d\n", val[0], val[1]);
    printf("target two sum %d indeces = [%d, %d]\n", target, val[0], val[1]);

}
