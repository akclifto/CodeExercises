/*
 *Leetcode difficulty: Easy
 *Write a function to find the longest common prefix string amongst an array of strings.
  If there is no common prefix, return an empty string "".

	Example 1:
		Input: ["flower","flow","flight"]
		Output: "fl"

	Example 2:
		Input: ["dog","racecar","car"]
		Output: ""
		Explanation: There is no common prefix among the input strings.
 *
 *	Runtime: 4ms
 */

#include <iostream>
#include <string>
#include <vector>
#include "LCPrefix.h"
using namespace std;

//driver
int main()
{
	vector<string> input;
	input.push_back("flower");
	input.push_back("flow");
	input.push_back("flight");

	Solution sol;
	string result = sol.longestCommonPrefix(input);
	sol.display_out(result); //prints fl

	input.clear();
	input.push_back("dog");
	input.push_back("racecar");
	input.push_back("car");
	result = sol.longestCommonPrefix(input);
	sol.display_out(result); //prints no common prefix

	input.clear();
	input.push_back("flower");
	input.push_back("flow");
	input.push_back("flowing");
	input.push_back("flowers");
	result = sol.longestCommonPrefix(input);
	sol.display_out(result);  //prints flow
	
}
