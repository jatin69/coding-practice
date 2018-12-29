/*
 * Author : Jatin Rohilla
 * Date   : 18/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
ques - https://www.geeksforgeeks.org/queries-left-right-circular-shift-array/

approach -
1. find net rotation

2. Now we only need to move indexes, not elements

Suppose we need sum for range [1..3]
Initially,
Index   => 0  1 2 3 4
Element => 1 (2 3 4) 5

One right circular rotation later,
Index   => 0  1 2 3  4
Element => 5 (1 2 3) 4

Equivalent to,
Index   =>  0 1 2  3 4
Element => (1 2 3) 4 5

Indexes move one LEFT for one RIGHT CIRCULAR ROTATION
similarly,
Indexes move one RIGHT for one LEFT CIRCULAR ROTATION

Also keep in mind
overflow  ( handle using mod n i.e. by subtracting n )
underflow ( handle by adding n => 0-1 = -1 + n = n-1 => leftmost to rightmost shift)

Now simply calculate range sum for (l to r) +- rotations.

3. We can even optimise further. No need to calculate sum again and again.
Simply store cummulative sum => prefix sum & use it.
when l<r => Csum(r+1) - Csum(l)
when l>r => Csum(r to n-1) + Csum(0 to l) => Csum(n) + Csum(r+1) - Csum(l)

Be careful with bounds. Example is -
Index = 0 1 2  3  4
Array = 1 2 3  4  5
Csum  = 1 3 6 10 15

Now sum of 1 to 3 => 9
Now sum of 3 to 1 => 12

*/


#include<bits/stdc++.h>
using namespace std;

void QueryExecuter(const vector<int>& A, const int* Csum, int& rotationCount, int queryType, int l, int r=-1) {
	
	int n = A.size();
	
	// RIGHT rotation => results in left shifting of index
	if(queryType==1){
		int x = l;
		rotationCount = (rotationCount - x)%n;
	}
	else if(queryType==2){
		int y = l;
		rotationCount = (rotationCount + y)%n;
	}
	else if(queryType==3){
		// n is added to handle any underflows
		l = (l + rotationCount + n) % n;
		r = (r + rotationCount + n) % n;
		
		int rangeSum = 0;
		
		// l is before r like 1 to 3
		if(l <= r) {
			rangeSum = Csum[r+1] - Csum[l];
		}
		// r is before l like 3 to 1
		else{
			rangeSum = Csum[n] + Csum[r+1] - Csum[l];
		}
		cout << rangeSum << "\n";
	}
	
}

void QueryWrapper(vector<int> A) {
	
	// prefix sum
	// Csum[i] contains sum of first zero elements
	int realSize = A.size()+1;
	int *Csum = new int[realSize];
	
	Csum[0] = 0;
	for(int i = 1; i < realSize ; ++i){
		Csum[i] = Csum[i-1] + A[i-1];
	}
	
	int rotationCount = 0;      // is passed by reference
	int x,y,l,r;

	// Queries
	
	x = 3;
	QueryExecuter(A, Csum, rotationCount,  1, x);
	
	l=0;
	r=2;
	QueryExecuter(A, Csum, rotationCount,  3, l, r);

	y=1;
	QueryExecuter(A, Csum, rotationCount,  2, y);

	l=1;
	r=4;
	QueryExecuter(A, Csum, rotationCount,  3, l, r);
}

int main(){

	vector<int> A = {
		1, 2, 3, 4, 5
	};
	
	QueryWrapper(A);
	
    return 0;
}

