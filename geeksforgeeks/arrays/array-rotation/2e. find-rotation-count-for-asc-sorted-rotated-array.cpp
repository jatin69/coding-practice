/*
 * Author : Jatin Rohilla
 * Date   : 16/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 
original ques - find rotation count for clockwise rotated array
original link - https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

modified ques - find rotation count for left rotated array

NOTE : ASCENDING ARRAY
 */


#include<bits/stdc++.h>
using namespace std;

/* returns index of minimum element in logN time */
int findMinIndex(vector<int> A, int l, int h){
	
	// no pivot => already sorted => 0 rotations
	if(l>h){
		return 0;
	}
	
	if(l==h){
		return l;
	}
	
	int mid = (l+h)/2;
	
	if( mid-1 >=l && A[mid-1] > A[mid]){
		return mid;
	}
	if( mid+1 <= h && A[mid] > A[mid+1]){
		return mid+1;
	}
	
	// check second half first
	if(A[mid] > A[h]){
		return findMinIndex(A, mid+1, h);
	}
	else{
		return findMinIndex(A, 0, mid-1);
	}
	
}

int main(){

		vector<int> A = {
		15, 18, 2, 3, 6, 12
//		4, 5, 6, 7, 8, 9, 1, 2, 3
//		1, 2, 3, 4, 5, 6
//		3,4,5,6,7,8, 1,2
//		2, 3, 4, 5, 6
//		1, 2, 3
//		5, 4, 3, 2, 1       // not valid because we are assuming ascending world
	};

	int res = findMinIndex(A, 0, A.size()-1);
	int n = A.size() ;
	cout << "\nClockwise Rotation count : " << res ;
	cout << "\nLeft Rotation count : " << (n - res)%n;


    return 0;
}

