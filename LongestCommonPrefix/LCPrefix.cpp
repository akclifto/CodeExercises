

#include <vector>
#include <string>
#include "LCPrefix.h"

#include <iostream>
using namespace std;

string Solution::longestCommonPrefix(vector<string>& str)
{
	string result = "";

	// if str empty, return
	if (str.empty())
	{
		return result;
	}
	// set result to beginning of string
	result = str[0];
	
	// loop through vector string, if str and iter do not match, break and return result,
	// else pop to end of result and continue
	for(vector<string>::iterator iter = str.begin() + 1; iter != str.end(); iter++)
	{
		while(result != "")
		{
			if(iter->find(result) == 0)
			{
				break;
			}
			else
			{
				result.pop_back();
			}
		}
		// if result is empty, return result
		if(result == "")
		{
			return result;
		}
	}
	return result;
}

void Solution::display_out(string &result)
{
	if (result.empty())
	{
		cout << "There is no common prefix among the input strings." << endl;
	}
	else
	{
		cout << "Result: " << result << endl;
	}
}
