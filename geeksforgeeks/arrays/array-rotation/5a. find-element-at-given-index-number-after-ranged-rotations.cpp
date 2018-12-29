/*
 * Author : Jatin Rohilla
 * Date   : 17/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

ques - https://www.geeksforgeeks.org/find-element-given-index-number-rotations/
statement - after a series of ranged LEFT ROTATIONS, find an element at a given index

index is fixed, elements rotate
In our solution approach, we keep the elements as it is, and rotate the index instead.

approach -
we only need element at that index. so only concerned with that element.
let asked index is `idx`
if idx is out of range of rotattion, no effect
if idx is leftmost, it becomes rightmost
if idx is normal member, it becomes idx-1
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

	cout<<"Hello World";

    return 0;
}

/*
// CPP code to rotate an array
// and answer the index query
#include <bits/stdc++.h>
using namespace std;

// Function to compute the element at
// given index
int findElement(int arr[], int ranges[][2],
			int rotations, int index)
{
	for (int i = rotations - 1; i >= 0; i--) {

		// Range[left...right]
		int left = ranges[i][0];
		int right = ranges[i][1];

		// Rotation will not have any effect
		if (left <= index && right >= index) {
			if (index == left)
				index = right;
			else
				index--;
		}
	}

	// Returning new element
	return arr[index];
}

// Driver
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	// No. of rotations
	int rotations = 2;

	// Ranges according to 0-based indexing
	int ranges[rotations][2] = { { 0, 2 }, { 0, 3 } };

	int index = 1;

	cout << findElement(arr, ranges, rotations, index);

	return 0;

}

*/
