// Cpp_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

#define NO_OF_CHARS 256

/*Given a string, find the first non-repeating character in it. For example,
 *if the input string is “GeeksforGeeks”, then output should be ‘f’ and if input string
 *is “GeeksQuiz”, then output should be ‘G’*/

int *get_char_count(char *str)
{
	int *count = (int*)calloc(sizeof(int), NO_OF_CHARS);
	int i;

	for(i = 0; *(str + i); i++)
	{
		count[*(str + i)]++;
	}
	
	return count;
}

int first_nonRepeater(char *str)
{
	int* count = get_char_count(str);
	int index = -1;

	for(int i = 0; *(str + i); i++)
	{
		if(count[*(str + i)] == 1)
		{
			index = i;
			break;
		}
	}
	free(count);
	return index;
}

void check_string(char *str, int index)
{
	if (index == -1)
	{
		cout << "No non-repeating strings\n";
	}
	else
		cout << "First non-repeating character in the given string is " << str[index] << ".\n";
}

void display_egg_puzzle(eggDrop_puzzle egg, int eggs, int floors)
{
	cout << "The minimum number of trials in worst case: \n";
	cout << eggs << " eggs\n";
	cout << floors << " floors\n";
	cout << "Result:  " << egg.egg_drop(eggs, floors) << ".\n";
	return;
}

void display_egg_puzzle2D(eggDrop_puzzle egg, int eggs, int floors)
{
	cout << "\nThe minimum number of trials in worst case: \n";
	cout << eggs << " eggs\n";
	cout << floors << " floors\n";
	cout << "Result:  " << egg.egg_drop_2D(eggs, floors) << ".\n";
	return;
}


int main()
{

// first non-repeating char exercise--------------------------------------------------------------

	cout << "FIRST NON-REPEATING CHARACTER EXERCISE\n\n";
	//check string, should return n
	char str[] = "this is the end?";
	int index = first_nonRepeater(str);
	check_string(str, index);

	//check string, no repeating strings
	char str2[] = "aaaaaa";
	index = first_nonRepeater(str2);
	check_string(str2, index);

// EGG DROPPING PUZZLE------------------------------------------------------------------------------

	cout << "\n\n\nEGG DROPPING PUZZLE \n";

	int eggs = 3;		 // number of eggs
	int floors = 19;	 // number of floors
	eggDrop_puzzle egg, egg_2D;
	display_egg_puzzle(egg, eggs, floors);

	//alternative way with 2D array sample - BROKEN
	// eggs = 2;
	// floors = 36;
	// eggDrop_puzzle egg2;
	// display_egg_puzzle(egg2, eggs, floors);
	// display_egg_puzzle2D(egg_2D, eggs, floors);
	
	// egg_2D.destroy_egg_puzzle(egg_2D.egg_floor);
	//getchar();
	return 0;


	//base stuff to get handle on cpp
	string name = "adam";
	cout << "Hello World!" << endl;
	cout << "Hello my name is " << name << ".  Thanks!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
