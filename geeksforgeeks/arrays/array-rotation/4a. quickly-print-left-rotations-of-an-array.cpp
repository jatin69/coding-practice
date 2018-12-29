/*
 * Author : Jatin Rohilla
 * Date   : 17/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
ques - https://www.geeksforgeeks.org/print-left-rotation-array/
ques - Quickly display multiple left rotations

approach - display can be done simply
start with k (rotation count)
and display whole array, mod when overflow

*/

// CPP implementation of left rotation of
// an array K number of times
#include <bits/stdc++.h>
using namespace std;

// Function to leftRotate array multiple times
void leftRotate(int arr[], int n, int k)
{
	// Prints the rotated array from start position
	for (int i = 0; i < n; i++){
		cout << arr[ (k + i) % n]  << " ";
	}
	cout << "\n";
}

// Driver program
int main()
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	for(int k=0;k<=n;k++){
		leftRotate(arr, n, k);
	}

	return 0;
}

