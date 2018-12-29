/*
 * Author : Jatin Rohilla
 * Date   : 18/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
question - https://www.interviewbit.com/problems/wave-array/
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

approach -
sort and swap alternate
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int n;
	int t;
	
    if(A.size()%2==0){
    	n = A.size();
	}
	else{
		n = A.size()-1;
	}
    for(int i=0;i<n;i=i+2){
		t = A[i];
    	A[i] = A[i+1];
    	A[i+1] = t;
	}

    return A;
}

int main(){

	vector<int> A = {
		5, 1, 3, 2, 4       // 2 1 4 3 5    expected
	};

	vector<int> B = wave(A);
	cout << "\n";
	for(int i=0;i<B.size();++i){
		cout << B[i] << " ";
	}
	cout << "\n";

    return 0;
}

