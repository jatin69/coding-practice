/*
 * Author : Jatin Rohilla
 * Date   : 6-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/sort-by-color/
 */


#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &A) {

    int trackerOfZero = 0;
    int trackerOfTwo = A.size()-1;

    for(int i= trackerOfZero; i<=trackerOfTwo; ++i){
        if(A[i]==0){
            swap(A[i], A[trackerOfZero++]);
        }
        else if(A[i]==2){
            swap(A[i], A[trackerOfTwo--]);
            i--;
        }
    }
}


int main(){

	vector<int> A = { 1,1,1,1,1,0,0,1,2,1,2,1,1,0};
	sortColors(A);
	for(auto it : A){
		cout << it << " ";
	}
	cout << "\n";
    return 0;
}

