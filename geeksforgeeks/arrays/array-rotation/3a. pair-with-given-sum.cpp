/*
 * Author : Jatin Rohilla
 * Date   : 17/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
question - https://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/

Two approaches -

1. O( NlogN ) time and constant space
sort the array. and apply 2 pointer approach.

2. O(N) time and O(N) space
Hashing approach.

BOTH APPROACHES HANDLES NEGATIVES AS WELL.
 */


#include<bits/stdc++.h>
using namespace std;
typedef vector< tuple<int,int> > listOfTuples;

/* approach 1 : Sort and two pointer approach - O( logN )
   modified to return all pairs which satisfy the sum
*/
listOfTuples pairSumTwoPointer(vector<int> A, int requiredSum){
	
	listOfTuples res;

	// sort
	sort(A.begin(), A.end());
	
	// two pointer approach
	int i=0;
	int j=A.size()-1;
	
	while(i<j){
		
		if( A[i] + A[j] == requiredSum ) {
			res.push_back(make_tuple( A[i], A[j]));
			i++;
			j--;
		}
		else if( A[i] + A[j] < requiredSum ) {
			i++;
		}
		else if( A[i] + A[j] > requiredSum ) {
			j--;
		}
	}

	return res;
	
}


/* approach 2 : Hashmap approach - O(N) time and O(N) space
*/
listOfTuples pairSumHashmap(vector<int> A, int requiredSum){
	unordered_set<int> uset;
	listOfTuples res;
	for(int i=0; i<A.size(); ++i){

		int temp = requiredSum - A[i];

		// if not unfound => found => store in res
		if( uset.find(temp) != uset.end() ) {
			res.push_back(make_pair(A[i], temp));
		}
		
		// make an entry into hashtable
		uset.insert(A[i]);
	}
	return res;
}

int main(){

	vector<int> A = {
		1,2,3,4,5,6,7   // sum 9
//		1,-2,-3,5,6,11  // sum 9
//		-8, 24          // sum 16
	};

	int requiredSum = 9;

	listOfTuples res = pairSumTwoPointer(A, requiredSum);
//	listOfTuples res = pairSumHashmap(A, requiredSum);

	for(listOfTuples::iterator it = res.begin(); it != res.end(); ++it){
		cout << "(" << get<0>(*it) << ", " << get<1>(*it) << ")" << "\n";
	}

    return 0;
}

