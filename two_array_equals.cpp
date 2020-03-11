/*
Given two given arrays of equal length, the task is to find if given arrays are equal or not. 
Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation)
of elements may be different though.

Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Examples :

	Input  : arr1[] = {1, 2, 5, 4, 0};
			 arr2[] = {2, 4, 5, 0, 1}; 
	Output : Yes

	Input  : arr1[] = {1, 2, 5, 4, 0, 2, 1};
			 arr2[] = {2, 4, 5, 0, 1, 1, 2}; 
	Output : Yes
	 
	Input : arr1[] = {1, 7, 1};
			arr2[] = {7, 7, 1};
	Output : No

SOLUTION:  Sort both arrays with simple sorting alogrithm and do linear comparison.
*/
#include <iostream>		// contains cout
#include <algorithm> 	// contains sort()
//	#include <bits/stdc++.h>   //this include brings in all cpp libraries
using namespace std;

bool are_equal(int array1[], int array2[], int n, int m);
void compare(bool flag);

bool are_equal(int array1[], int array2[], int n, int m) {

	//if the array sizes are different, they are not equal
	if(n != m) {
		return false;
	}
	
	//simple sort using library
	sort(array1, array1 + n);
	sort(array2, array2 + m);
	
	
	//linear comparison
	for(int i = 0; i < n;i++) {
		
		//if arrays not equal return false;
		if(array1[i] != array2[i]) {
			
			return false;
			
		}
	}
	//if equal, will return true
	return true;
}

void compare(bool flag) {
	
	if(flag) {
		
		cout << "The arrays are equal!\n";	
		
	} else {
	
		cout << "The arrays are NOT equal!\n";
	}

}


int main() {

	//arrays to compare
	int array1[] = {3 , 5, 2, 5, 2};
	int array2[] = {2, 3, 5, 5, 2};
	int array3[] = {1, 2, 3};
	int array4[] = {1, 3, 5, 2, 5};
	//size of both arrays held in n and m
	int n = sizeof(array1) / sizeof(int);
	int m = sizeof(array2) / sizeof(int);
	int x = sizeof(array3) / sizeof(int);
	int y = sizeof(array4) / sizeof(int);
	
	compare(are_equal(array1, array2, n, m));
	compare(are_equal(array1, array3, n, y));
    compare(are_equal(array1, array4, n, y));

	return 0;
}