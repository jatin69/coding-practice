/*
 * Author : Jatin Rohilla
 * Date   : 16/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

Question : find pivot, min, max element in a descending sorted rotated array
similar question - https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

Approach - achieved simply by changing > / < signs from the ascending counterpart
counterpart solution filename - find-pivot-min-max-in-a-asc-sorted-rotated-array.cpp

NOTE : Array is DESCENDING

*/


#include<bits/stdc++.h>
using namespace std;


/* standard find pivot. Default to findMin
First half checked first

Returns index of pivot
*/
int findPivot(vector<int> A, int l, int h){

	if(l>h){
		return -1;
	}

	if(l==h){
		return l;
	}

	int mid = (l+h)/2;

	// anomaly check at mid
	if( mid+1 <= h &&  A[mid] < A[mid+1]){
		return mid;
	}
	if( mid-1 >= l && A[mid-1] < A[mid]){
		return mid-1;
	}

	// first half is checked first => Because we wanna max ( default pivot = max )
	// check for bug in first half
	if(A[l] < A[mid]){
		return findPivot(A, l, mid-1);
	}
	else{
		return findPivot(A, mid+1, h);
	}


}


/* findMin ( same as findPivot )
First half checked first

Returns min (pivot) element
*/
int findMin(vector<int> A, int l, int h){

	// no pivot - array sorted // last element is max
	if(l>h){
		return A[A.size()-1];
	}

	if(l==h){
		return A[l];
	}

	int mid = (l+h)/2;

	if(mid+1 <= h && A[mid] < A[mid+1]){
		return A[mid];
	}
	if(mid-1 >= l && A[mid-1] < A[mid]){
		return A[mid-1];
	}

	// first half is checked first => Because we wanna max ( default pivot = max )
	// check for bug in first half
	if(A[l] < A[mid]){
		return findMin(A, l, mid-1);
	}
	else{
		return findMin(A, mid+1, h);
	}

}


/* findMax ( looks same as findPivot but slight diff )
second half half checked first

Max = next to pivot (min)
so 1 is added to almost all indexes, but not in base cases.
Look base cases carefully

Returns max (next to pivot) element
*/

int findMax(vector<int> A, int l, int h){

	// no pivot - array sorted // first element is min
	if(l>h){
		return A[0];
	}

	if(l==h){
		return A[l];
	}

	int mid = (l+h)/2;

	if(mid+1 <= h && A[mid] < A[mid+1]){
		return A[mid+1];
	}
	if(mid-1 >= l && A[mid-1] < A[mid]){
		return A[mid];
	}

	// check for bug in second half
	if(A[mid] < A[h]){
		return findMax(A, mid+1, h);
	}
	else{
		return findMax(A, l, mid-1);
	}
}


int main(){

	vector<int> A = {
		6, 5, 4, 3, 2, 1
//		3, 2, 1
//		4, 3, 2, 1, 6, 5
//		2, 1, 6, 5, 4, 3
//		1, 2, 3, 4, 5   // not valid because we are assuming descending world
	};

	cout << "\nPivot index : " << findPivot(A, 0, A.size()-1);
	cout << "\nMax element : " << findMax(A, 0, A.size()-1);
	cout << "\nMin element : " << findMin(A, 0, A.size()-1);

	// can be simply done if i find the pivot and use it properly

    return 0;
}

