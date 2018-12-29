/*
 * Author : Jatin Rohilla
 * Date   : 16/06/18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

NOTE: Assuming ASCENDING order array & DISTINCT ELEMENTS

==> pre question - https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
solution - search-an-element-in-a-sorted-and-pivoted-array.cpp

==> current question -> find pivot in case of ASCENDING ARRAY
pivot is first problem element. ( largest element )
approach - find mid, then check around mid for problem
If none, check for bug in first half ( because max is needed )

==> follow up question - https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
solutions -
find-pivot-min-max-in-a-asc-sorted-rotated-array.cpp
find-pivot-min-max-in-a-desc-sorted-rotated-array.cpp

*/


#include<bits/stdc++.h>
using namespace std;

// default pivot finds max element
int findPivot(vector<int>& A, int l, int h){
	
	if(l>h){
		return -1;
	}
	
	if(l==h){
		return l;
	}
	
	int mid = (l+h)/2;
	
	// anomaly check at mid
	if( mid+1 <= h &&  A[mid] > A[mid+1]){
		return mid;
	}
	if( mid-1 >= l && A[mid-1] > A[mid]){
		return mid-1;
	}
	
	// first half is checked first => Because we wanna max ( default pivot = max )
	if(A[l] > A[mid]){
		return findPivot(A, l, mid-1);
	}
	else{
		return findPivot(A, mid+1, h);
	}
	
	
}

int main(){

	vector<int> A =
	 {
		3,4,5,6,7,8, 1,2
//		4, 5, 6, 7, 8, 9, 1, 2, 3
//		2, 3, 4, 5, 6
//		4, 5, 1, 2, 3
//		1,2, 3
//		5, 4, 3, 2, 1       // not valid test case, because we are in ascending world
	 };
	int idx  = findPivot(A, 0, A.size()-1);

	if(idx!=-1){
		cout << "Pivot index is : " << idx ;
	}
	else{
		cout << "No pivot. Array is sorted.";
	}

    return 0;
}

