/*
 * Author : Jatin Rohilla
 * Date   : 18-02-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
question - https://www.geeksforgeeks.org/find-a-rotation-with-maximum-hamming-distance/
Statement - max hamming distance

approach -
simulate rotations and find max hamming

time - O(n^2)
space - constant
*/


#include<bits/stdc++.h>
using namespace std;


int maxHamming(vector<int> A) {
	int n = A.size();
	int maxHam=0, currHam=0;
	
	// i => LEFT rotated i times
	for(int i=0;i<n;++i){
		
		currHam=0;
		// for ith rotation, find hamming distance
		for(int j=0; j<n; ++j){
			if(A[j]!=A[(j+i)%n]){
				currHam++;
			}
		}
		// checking if the current one is max
		if(currHam > maxHam){
			maxHam = currHam;
//			cout << "\nMax Ham rotation is  : ";
//			for(int j=0; j<n; ++j) cout << A[(j+i)%n] << "  ";
		}
		
		// we are only interested in max one, if current one is max possible, break
		if(maxHam==n){
			break;
		}
	}
	
	return maxHam;
}

int main(){

	vector<int> A = {
		2, 4, 6, 8
//		1, 4, 1
//		2, 4, 8, 0
	};

	cout << "\nMax Hamming Distance : "<< maxHamming(A);
    return 0;
}

