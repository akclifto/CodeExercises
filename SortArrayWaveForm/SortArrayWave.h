#pragma once

class SortArrayWave {

private:

public:

	/*main algorithm to sort*/
	void sort_to_wave(int array[], int n);
	/*helper swap*/
	void swap(int* x, int* y);
	/*helper display to console*/
	void display(int array[], int n);
};