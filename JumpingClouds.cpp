/*
 *      Hackerrank difficulty: easy
 *
 *      Jumping on Clouds.  Print the minimum number of jumps it takes to get from
 *      the start of the clouds to the end of the clouds.
 *
 *      jumpingOnClouds has the following parameter(s):
 *			c: an array of binary integers
 *			    0 clouds:  safe clouds to jump on ==> can walk across without a jump
 *			    1 clouds: thunderheads, need to avoid ==> need to jump over
 *
 * 		Sample Input:
 *			7
 *			0 0 1 0 0 1 0
 * 		Sample Output:
 *			4
 *
 *		SOLUTION: traverse vector, if c = 0, walk by incrementing i in if-statement, else jump. 
 */

#include <iostream>
#include <vector>
using namespace std;

//forward declaration
int jumpingOnClouds(vector<int> c);

int main()
{
    
	vector<int> c = { 0,0,1,0,0,1,0 };
	int n = 7;
    int result = jumpingOnClouds(c);
    cout << result << endl; // should output 4

    vector<int> d = { 0,1,0,1,1,0,0,1,0,1,1,0,0 };
    n = d.size();
    result = jumpingOnClouds(d);
    cout << result << endl; // should output 8
}


int jumpingOnClouds(vector<int> c) {

    int jumps = 0;

    for (int i = 0; i < c.size() - 1; i++)
    {
		if(c[i] == 0)
		{
			i++;
		}
        jumps++;
    }
    return jumps;

}