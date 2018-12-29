/*
 * Author : Jatin Rohilla
 * Date   : 16/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * question - https://www.geeksforgeeks.org/array-rotation/
 */

/*
approach-

1. make a function which rotates array by 1, call it d times. You are done.
complexity = O(n*d)

2. Order N approach - A juggling algo   -> makes more sense to me
find GCD, make rotations in GCD

3. Reversal method -
divide into two sets A and B. ArB => ArBr => (ArBr)r => BA
(1, 2,) (3, 4, 5, 6, 7) for d = 2
Three steps -
a. reverse 0 to d-1
b. reverse d to n-1
c. reverse 0 to n-1
*/

#include<bits/stdc++.h>
using namespace std;


void printVector(vector<int> A){
	for(vector<int>::iterator it = A.begin(); it != A.end() ; ++it){
		cout << *it << " ";
	}
}

// ************  2. Juggling approach ******************
int GCD(int a, int b){
	if(b==0){
		return a;
	}
	else{
		return GCD(b, a%b);
	}
}

void JugglingLeftRotate(vector<int>& A, int d){
	int n = A.size();
	int steps = GCD(n,d);

	int i,j,k;
	for(i=0; i<steps; ++i){

		// store first in temp
		int temp = A[i];

		int j = i;      	// start element
		int k = (i+d)%n;    // second element from start
		
		while(k!=i){
			A[j] = A[k];
			j = k;          // move to next candidate
			k = (k+d)%n;    // move to next candidate
		}

		A[j] = temp;
	}
}

void JugglingRightRotate(vector<int>& A, int d){
	JugglingLeftRotate(A, A.size()-d);
}

// ************  3. reversal approach ******************
void reverse(vector<int>& A, int low, int high){
	while(low < high)
    {
    	// swap
        int t   = A[low];
		A[low]  = A[high];
		A[high] = t;
		
        low++;
		high--;
	}
}

void reversalLeftRotate(vector<int>& A, int d){
	int n = A.size();
	d = d % n;
	reverse(A, 0,d-1);
	reverse(A, d,n-1);
	reverse(A, 0,n-1);
}

void reversalRightRotate(vector<int>& A, int d){
	int n = A.size();
	d = d % n;
	reverse(A, 0,n-1);
	reverse(A, 0,d-1);
	reverse(A, d,n-1);
}

int main(){

   vector<int> A = {1, 2, 3, 4, 5, 6, 7};
   
   int d = 2;
   
//   JugglingLeftRotate(A, d);
//   JugglingRightRotate(A, d);

//   reversalLeftRotate(A, d);
//   reversalRightRotate(A, d);


   printVector(A);
   
   return 0;
}

