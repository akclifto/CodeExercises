#pragma once


class eggDrop_puzzle
{
private:
	
public:
	/**
	 * \brief comparison method to find max value between two given ints
	 * \param a: first value
	 * \param b: second value
	 * \return  a if a > b, else return b
	 */
	int max(int a, int b);

	/**
	 * \brief recursive function to get the minimum number of trials needed
	 *		in worst case with n eggs and k floors
	 * \param n: number of eggs
	 * \param k: number of floors
	 * \return minimum number of trials
	 */
	int egg_drop(int n, int k);

	/**
	 * \brief iterative function to get the minimum number of trials needed
	 *		in worst case with n eggs and k floors
	 * \param n: number of eggs
	 * \param k: number of floors 
	 * \return minimum number of trials.
	 */
	int egg_drop_2D(int n, int k);

	/**
	 * \brief destroy the egg puzzle made in egg_drop_2D
	 * \param egg_floor the 2D array to destroy
	 */
	void destroy_egg_puzzle(int** egg_floor);	
};

