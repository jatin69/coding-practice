/*
 * Author : Jatin Rohilla
 * Date   : 17/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

question - https://www.geeksforgeeks.org/maximum-sum-iarri-among-rotations-given-array/

time - O(n)
space - O(1)

 */


#include<bits/stdc++.h>
using namespace std;


int maxSum(vector<int>& A) {
	
	int n = A.size();
	int Asum = 0;
	int currValue = 0;
	
	for(int i=0;i<n;++i){
		Asum += A[i];
		
		// value at zero left rotations.
		currValue += (i*A[i]);
	}
	
	int maxValue = 0;
	// start by left rotating original array by 1
	for(int i=1;i<n;++i){
		
		/* One left rotation will decrease the multiplication factor by 1
		so we gotta subtract ( 1*A[0] + 1*A[1] + ... 1*A[n-1] )
		But if we look closely we see that A[0] had a multiplication factor 0 initially
		so we are taking away from zero. Can't do that. So gotta give it back.
		Asum - A[i-1] represents array sum except first element.
		Also, first element now goes to last & now has n-1 multiplication factor.
		*/
		currValue = currValue - (Asum - A[i-1]) + (n-1)*A[i-1];
		maxValue = max(maxValue, currValue);
	}

	return maxValue;
}

int main(){

	vector<int> A = {
		8, 3, 1, 2
	};
	
	cout << maxSum(A);

    return 0;
}

