/*
 * Author : Jatin Rohilla
 * Date   : 10/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 * Question- https://www.interviewbit.com/problems/noble-integer/
 * Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.
 * If such an integer is found return 1 else return -1.
 *
 */


#include<bits/stdc++.h>
using namespace std;

int mycomp(int i, int j){
	return i>j;
}

int solve(vector<int> &A) {
    sort(A.begin(),A.end(), mycomp);
	for(int i=0;i<A.size();++i){
		cout << A[i] << " ";
	}
	if(A[0]==0){
		return 1;
	}
	for(int i=1;i<A.size();++i){
		if(A[i]<0){
			break;
		}
	   if(A[i]==i && A[i]<A[i-1]  ){
            return 1;
        }
    }
    return -1;
}


int main(){

	vector<int>A = {
//		 -4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6, 7, 8, -6, 5, 0, 3, -4, 1, -10, 6, 3, -8, 0, 6, -9, -5, -5, -6, -3, 6, -5, -4, -1, 3, 7, -6, 5, -8, -5, 4, -3, 4, -6, -7, 0, -3, -2, 6, 8, -2, -6, -7, 1, 4, 9, 2, -10, 6, -2, 9, 2, -4, -4, 4, 9, 5, 0, 4, 8, -3, -9, 7, -8, 7, 2, 2, 6, -9, -10, -4, -9, -5, -1, -6, 9, -10, -1, 1, 7, 7, 1, -9, 5, -1, -3, -3, 6, 7, 3, -4, -5, -4, -7, 9, -6, -2, 1, 2, -1, -7, 9, 0, -2, -2, 5, -10, -1, 6, -7, 8, -5, -4, 1, -9, 5, 9, -2, -6, -2, -9, 0, 3, -10, 4, -6, -6, 4, -3, 6, -7, 1, -3, -5, 9, 6, 2, 1, 7, -2, 5
		-4, -2, 0, -1, -6
//		6, 6, 4, 6, 4       // special case
	};
	cout << "\n\n" << solve(A);

    return 0;
}

