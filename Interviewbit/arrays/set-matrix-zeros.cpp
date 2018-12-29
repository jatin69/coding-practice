/*
 * Author : Jatin Rohilla
 * Date   : 18/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

original link - https://www.interviewbit.com/problems/set-matrix-zeros/
Question - Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0. Do it in place

Similar question - https://www.geeksforgeeks.org/a-boolean-matrix-question/


approach -

1. Mark current row and column for later processing
To mark, push them in separate row & column vectors.
later process everything.
Time - O(m*n)
space - O(m+n)  // exceeds requirement

2.
Mark current row and column for later processing
=> can't simply multiply by -ve marking because it will be nullified at intersections
=> can't use multiply by two or above because it's going out of range
I need something which makes zero when encountered with zero
use -1 along with many if conditions. Job done.
Time -  exceeds requirement
space - O(1)  

3. Efficient approach
use two flag variables to store status of 0th row and 0th column.
Now process matrix (m-1 * n-1) by reusing space of 0th row and 0th column as Aux space
At last, process 0th row and column using flags.
 */


#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {

	int R = A.size();
	int C = A[0].size();

	// flags to hold status of first row and column
	bool rowFlag = false;
	bool colFlag = false;
	
	// processing 0th row
	for(int j=0; j<C;++j){
		if(A[0][j] == 0){
			rowFlag = true;
			break;
		}
	}
	
	// processing 0th column
	for(int i=0;i<R;++i){
		if(A[i][0] == 0){
			colFlag = true;
			break;
		}
	}

	// processing matrix of size M-1 * N-1
	for(int i=1;i<R;++i){
		for(int j=1; j<C;++j){
			if(A[i][j]==0){
				A[0][j] = 0;        
				A[i][0] = 0;
			}
		}
	}
	
	// Modifying the matrix of size M-1 * N-1
	for(int i=1;i<R;++i){
		for(int j=1; j<C;++j){
			if(A[i][0] == 0 || A[0][j] == 0 ){
				A[i][j] = 0;
			}
		}
	}
	
	// modifying the 0th row if needed
	if(rowFlag){
		for(int j=0;j<C;++j){
				A[0][j]=0;
		}
	}

	// modifying the 0th column if needed
	if(colFlag){
		for(int i=0; i<R; ++i){
				A[i][0]=0;
		}
	}
	
}


int main(){

	vector<vector<int>> A = {
		{1,0,1},
		{1,1,1},
		{1,1,1}

//		{1,1},
//		{0,1},
//		{0,1}
	};


	setZeroes(A);
	cout << "\n";
	for(int i=0;i<A.size();++i){
		for(int j=0; j<A[i].size();++j){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}


    return 0;
}

