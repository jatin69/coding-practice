/*
 * Author : Jatin Rohilla
 * Date   : 6/6/18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question : https://www.geeksforgeeks.org/minimum-xor-value-pair/
 * appraoch : sort the array. This is done because, XOR is minimum
 * when elements have same bits & elements have same bits when they are closer.
 * Then check consecutive pairs, for minimum Xor
 * This approach takes order NlogN where N is the size of array
 *
 * can be implemented in order N using Trie. To be done later.
 */

#include<bits/stdc++.h>
using namespace std;

int findMinXor(vector<int> &A) {
    // Sort given array
    sort(A.begin(), A.end());

    int minXor = INT_MAX;
    int val = 0;

    // calculate min xor of consecutive pairs
    for (int i = 0; i < A.size() - 1; i++) {
        val = A[i] ^ A[i + 1];
        minXor = min(minXor, val);
    }

    return minXor;
}

int main(){

	vector<int> A = {
	//1,43,5,2,99,6,23,3,4
	0, 4, 7, 9
	};
	int minXor = findMinXor(A);
	cout << "Min xor value is : "<< minXor;
    return 0;
}

