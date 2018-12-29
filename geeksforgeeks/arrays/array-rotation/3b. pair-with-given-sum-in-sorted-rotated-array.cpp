/*
 * Author : Jatin Rohilla
 * Date   : 17/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

pre question - pair-with-given-sum.cpp
curr question - https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

approach -
2 pointer approach can be applied with tweaking.

a. find `start` and `end` indices
=> start is essentially the smallest, end is the largest.
largest is also known as pivot. find pivot in logN.

b. Now use two pointer approach (order N), alongwith
modulo to handle overflow and negative modulo to handle underflow

Collectively takes O(N)
Now, Because it's taking O(N) regardless,
we may ditch the logN pivot and simply use O(N) pivot find

NOTE : ASCENDING ORDER WORLD

*/


#include<bits/stdc++.h>
using namespace std;

typedef vector< tuple<int,int> > listOfTuples;
listOfTuples pairSumSortedTwoPointer(vector<int> A, int requiredSum){

	listOfTuples res;
	int n = A.size();

	int pivot;
	for(int k=0; k<n; ++k) {
		if(A[k] > A[k+1]) {
			pivot = k;
			break;
		}
	}
	
	// two pointer approach
	int i = ( pivot + 1)%n;        // i is index of min element
	int j =  pivot;             // j is index of max element

	
	// free entry at starting point
	do{
//		cout << "start index i= " << i << " and end index j = " << j << "\n";

		if( A[i] + A[j] == requiredSum ) {
			res.push_back(make_tuple( A[i], A[j]));
			i = (i+1)%n;
			j = (n+ j-1)%n ;    // to handle negative modulo
		}
		
		else if( A[i] + A[j] < requiredSum ) {
			i = (i+1)%n;
		}
		
		else if( A[i] + A[j] > requiredSum ) {
		//	j = (j-1)%n;    // when j=0 => (-1)%n => negative modulo needed
			j = (n+ j-1)%n ;    // to handle negative modulo
		}
		
	}while(!(i==j || i==j+1 ) ); // goes back to starting state or meets

	return res;

}



int main(){

		vector<int> A = {
//		3,4,5,6,7,1,2  			// sum 9    // breaks at i==j+1
//		6,7,1,2,3,4,5   		// sum 9
		11, 15, 1, 6, 8, 9, 10  // sum 16   // breaks at i==j
	};

	int requiredSum = 16;

	listOfTuples res = pairSumSortedTwoPointer(A, requiredSum);

	for(listOfTuples::iterator it = res.begin(); it != res.end(); ++it){
		cout << "(" << get<0>(*it) << ", " << get<1>(*it) << ")" << "\n";
	}


    return 0;
}

