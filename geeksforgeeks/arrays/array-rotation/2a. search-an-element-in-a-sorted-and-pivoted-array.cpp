/*
 * Author : Jatin Rohilla
 * Date   : 16/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

Ques - https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/


NOTE :: ALL ELEMENTS ARE DISTINCT

approach 1 - order logN - coded below
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[r], recur for arr[mid+1..r].
    b) Else recur for arr[l..mid]
    
    
approach 2 - also order logN - find pivot & call binary search
Input arr[] = {3, 4, 5, 1, 2}
Element to Search = 1
  1) Find out pivot point and divide the array in two
      sub-arrays. (pivot = 2) // Index of 5
  2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then
             search in left array
      (b) Else Search in right array
          (1 will go in else as 1 < 0th element(3))
  3) If element is found in selected sub-array then return index
     Else return -1.
 */


#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& A, int key, int l, int h){
	if(l>h){
		return -1;
	}
	
	int mid = (l+h)/2;
	if(A[mid]==key){
		return mid;
	}
	
	// is first half sorted
	if(A[l] <= A[mid]){
		
		// quick check based on key value
		if(A[l] <= key && key <= A[mid]){
			return search(A, key, l, mid-1);
		}
		else{
			return search(A, key, mid+1, h);
		}
		
	}
	// if first half is not sorted, second half is definitely sorted
	else{
		
		// quick check based on key value
		if(A[mid] <= key && key <= A[h]){
			return search(A, key, mid+1, h);
		}
		else{
			return search(A, key, l, mid-1);
		}
	}
	
}

int main(){

	vector<int> A = {4, 5, 6, 7, 8, 9, 1, 2, 3};
	int key = 49;
	int res  = search(A, key, 0, A.size()-1);
	
	if(res!=-1){
		cout << "Index: " << res ;
	}
	else{
		cout << "Key not found";
	}

    return 0;
}

