/*
 * Author : Jatin Rohilla
 * Date   : 10/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question : https://www.interviewbit.com/problems/add-one-to-number/
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {

    A[A.size()-1]++;
    for(int i=A.size()-1;i>=1;i--){
        if(A[i]>9){
            A[i] -= 10;
            A[i-1]++;
        }
    }

	if(A[0]>9){
		A[0] -= 10;
		vector<int>::iterator it = A.begin();
		A.insert(it,1);
	}

    while(A[0]==0){
        A.erase(A.begin());
    }
    
    return A;
}

int main(){

	vector <int> A ={
//		9, 9
	0, 1, 2 ,3
	};
	
	vector <int> res = plusOne(A);
	
	for(int i=0;i<res.size();++i){
		cout<<A[i];
	}

    return 0;
}

