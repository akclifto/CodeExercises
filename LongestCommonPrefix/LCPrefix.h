#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
	
public:
	
	/**
	 * \brief find longest common prefix by search each word, at same character
	 * \param str input to find prefix
	 * \return common prefix.  If none, return ""
	 */
	string longestCommonPrefix(vector<string> &str);
	
	/**
	 * \brief display the result of the program implementation
	 * \param result 
	 */
	void display_out(string &result);

};

