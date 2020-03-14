/*
 * Leetcode Difficulty: Medium
 *
 * PROBLEM:  Convert a string to integer.
 * constraints:
 *		
 *		-Only the space character ' ' is considered as whitespace character.
 *		-Assume we are dealing with an environment which could only store integers
 *			within the 32-bit signed integer range: [−231,  231 − 1].
 *		-If the numerical value is out of the range of representable values,
 *			INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 *		-First non-whitespace must be an integer, or no conversion occurs
 *		-Whitespaces are ignored.
 *
 * Contains edge case errors for INT MAX and MIN +/- 1
 */

#include "StringATOI.h"
#include <iostream>
using namespace std;

int main()
{
	Solution atoi;
	int output = -1;

	string sample = "423";
	output = atoi.my_atoi(sample);
	atoi.display(output);

	sample = "     34";
	output = atoi.my_atoi(sample);
	atoi.display(output);

	sample = "this and 39";
	output = atoi.my_atoi(sample);
	atoi.display(output);

	sample = "3484 and some stuff";
	output = atoi.my_atoi(sample);
	atoi.display(output);

	sample = "-42";
	output = atoi.my_atoi(sample);
	atoi.display(output);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


int Solution::my_atoi(string s)
{
	int index = 0;
	int result = 0;
	int offset = 0;
	bool flag = true;

	while (index < s.length() && s[index] == ' ')
	{
		index++;
	}

	if (index == s.length() || s[index] != '-' &&
		s[index] != '+' && s[index] < 48 || s[index] > 57)
	{
		return 0;
	}
	
	if(s[index] == '-' || s[index] == '+')
	{
		if(s[index] == '-')
		{
			flag = false;
		}
		index++;
	}

	if(index != s.length() && s[index] >= 48 && s[index] <= 57)
	{
		result = result + s[index] - 48;
		index++;
	} else
	{
		return 0;
	}

	for(; index != s.length(); ++index)
	{	
		if (s[index] >= 48 && s[index] <= 57)
		{
			offset = s[index] - 48;
			if (result <= (INT_MAX / 10) )
			{
				result = result * 10;
			}
			else
			{
				return flag ? INT_MAX : INT_MIN;
			}

			if (!flag && result >= (INT_MAX - offset))
			{
				return INT_MIN;
			}

			if (flag && result > (INT_MAX - offset))
			{
				return INT_MAX - 1;
			}

			result = result + offset;
		
		}
		else
		{
			break;
		}
	}
	
	return flag ? result : -result;
	
}

void Solution::display(int output)
{
	if(output == -1)
	{
		cout << "ERROR, output not changed \n";
	}

	if(output == 0)
	{
		cout << "output for the program is " << output <<
			" ==> non-whitespaces not integer values at beginning of string. \n";
	} else
	{
		cout << output << endl;
	}
}
