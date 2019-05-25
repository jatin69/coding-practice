/*
 * Author : Jatin Rohilla
 * Date   : 9-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/remove-element-from-array/
 */


#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &A, int B) {
    int j = 0;
    for(int i=0;i<A.size();++i){
        if(A[i]!=B){
        	A[j] = A[i];        // this saves even more computation for this question
//            swap(A[i], A[j]);
            j++;
        }
    }
    return j;
}


int main(){

	vector<int> A = {4, 1, 1, 2, 1, 3};
	int B = 1;

	int len = removeElement(A, B);
	cout << "len is " << len << "\n";
	cout << "array is : ";
	for(auto it :A){
		cout << it << " ";
	}
	cout << "\n";

    return 0;
}

