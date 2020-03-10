/**
 * EGG DROPPING PUZZLE
 * Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from,
 * and which will cause the eggs to break on landing. We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that
	the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, the experiment
can be carried out in only one way. Drop the egg from the first-floor window; if it survives,
drop it from the second floor window. Continue upward until it breaks. In the worst case, this method
may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that
is guaranteed to work in all cases?

**The problem is not actually to find the critical floor, but merely to decide floors from which eggs
should be dropped so that total number of trials are minimized.**

1) Optimal Substructure:
When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn’t break.

1) If the egg breaks after dropping from xth floor, then we only need to check for floors lower
	than x with remaining eggs; so the problem reduces to x-1 floors and n-1 eggs
2) If the egg doesn’t break after dropping from the xth floor, then we only need to check for
	floors higher than x; so the problem reduces to k-x floors and n eggs.

PSEUDOCODE
  k ==> Number of floors
  n ==> Number of Eggs
  eggDrop(n, k) ==> Minimum number of trials needed to find the critical floor in worst case.
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): x in {1, 2, ..., k}}
 */


#include <iostream>
#include <limits>
#include "eggDrop_puzzle.h"
using namespace std;


//tertiary boolean to find max val between int a and int b
int eggDrop_puzzle::max(int a, int b)
{
	return (a > b) ? a : b;
}

int eggDrop_puzzle::egg_drop(int n , int k)
{
	int min = INT_MAX;
	int result;

	//if floors are 1 or less, thats the minimum
	if(k == 1 || k == 0)
	{
		return k;
	}

	//if there's one egg, return floors since there will be only one trial
	if(n == 1)
	{
		return k;
	}

	//Figure out all droppings from 1st to kth floor and return min + 1
	for(int i = 1; i <= k; i++)
	{
		result = max(egg_drop(n - 1, i - 1), egg_drop(n, k - i));
		if(result < min)
		{
			min = result;
		}
	}
	
	return min + 1;
}


int eggDrop_puzzle::egg_drop_2D(int n, int k)
{
	int **egg_floor = new int* [n + 1];	
	int i, j;

	for(i = 0; i < n; i++)
	{
		egg_floor[i] = new int[k + 1];
	}

	//Need one trial for one floor and 0 trials for 0 floors
	//similar to the first if-statement in the recursive implementation
	for (i = 1; i <= n; i++)
	{
		egg_floor[i][1] = 1;
		egg_floor[i][0] = 0;
	}

	//Will always need j trials for one egg and j floors
	for(j = 1; j <= k; j++)
	{
		egg_floor[1][j] = j;
	}

	//fill rest of entries using optimal substructure property:
	//	https://en.wikipedia.org/wiki/Optimal_substructure
	for(i = 2; i <= n; i++)
	{
		for(j = 2; j <= k; j++)
		{
			egg_floor[i][j] = INT_MAX;
			
			for(int x = 1; x <= j; x++)
			{
				int result = 1 + max(egg_floor[i - 1][x - 1], egg_floor[i][j - x]);
				if(result < egg_floor[i][j])
				{
					egg_floor[i][j] = result;
				}
			}
		}
	}
	//this should hold the result.
	return egg_floor[n][k];
}

void eggDrop_puzzle::destroy_egg_puzzle(int** egg_floor)
{
	delete[] *egg_floor;
	delete[] egg_floor;
	cout << "egg_puzzle deleted\n";
}









