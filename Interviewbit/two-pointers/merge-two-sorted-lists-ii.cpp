/*
 * Author : Jatin Rohilla
 * Date   : 9-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
 */


#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {

    int i=0;
    int j=0;

    while(j<B.size()){
        if(i>=A.size()){
            A.insert(A.begin()+i, B[j]);
            j++;
            continue;
        }

        if(B[j] < A[i]){
            A.insert(A.begin()+i, B[j]);
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){

	vector<int> A = {1,2,4};
	vector<int> B = {5, 6,7, 8};
	
	merge(A, B);
	
	for(auto it : A){
		cout << it << " ";
	}
	cout << "\n";

    return 0;
}

