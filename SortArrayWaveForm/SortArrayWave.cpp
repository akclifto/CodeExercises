#include <iostream>
#include <algorithm>		// contains sort()
#include "SortArrayWave.h"
using namespace std;


void SortArrayWave::sort_to_wave(int array[], int n)
{
	//sort existing array
	sort(array, array + n);
	cout << "Sorted before wave: \t";
	display(array, n);
	
	//swap adjacent position in the array, be sure not to overstep size of array
	//increment over two position not to effect the two adjacent sorts
	for (int i = 0; i < n - 1; i += 2)   //i to last ele in array, then incr every 2
	{
		swap(&array[i], &array[i + 1]);
	}
	cout << "After the wave: \t";
	display(array, n);
}


void SortArrayWave::swap(int* x, int* y)
{

	int temp = *x;
	*x = *y;
	*y = temp;
}


void SortArrayWave::display(int array[], int n)
{

	for (int i = 0; i < n; i++) 
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}
