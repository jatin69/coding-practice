/*
 * Author : Jatin Rohilla
 * Date   : 10-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/sorted-insert-position/
 */


#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &A, int B) {
    size_t idx = upper_bound(A.begin(), A.end(), B) - A.begin();
    if(A[idx-1] == B){
        return idx-1;
    }
    else{
        return idx;
    }
}

int main(){

	vector<int> A = {1,3,5,6};
	
	cout <<searchInsert(A, 5) << "\n";  // 2
	cout <<searchInsert(A, 2) << "\n";  // 1
	cout <<searchInsert(A, 7) << "\n";  // 4
	cout <<searchInsert(A, 0) << "\n";  // 0

    return 0;
}


// observe editorial
int searchInsert_observe(vector<int> &A, int target) {
    int n = A.size();
    int start = 0, end = n - 1;
    int mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(target == A[mid]){
            return mid;
        }
        else if(target < A[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}

// same logic editorial
int searchInsert_same_logic(vector<int> &A, int B) {
    int n= A.size();
    int l=0,r=n-1,mid,ans;
    if(n==0 || B<A[0]) return 0;
    else if(B>A[n-1]) return n;
    while(l<=r){
        mid= l+(r-l)/2;
        if(A[mid]==B)
            return mid;
        else if(A[mid]>B){
            ans= mid;
            r= mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}

