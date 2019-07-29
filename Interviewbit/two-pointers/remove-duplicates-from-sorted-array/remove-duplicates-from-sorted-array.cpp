/*
 * Author : Jatin Rohilla
 * Date   : 8-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
 */


#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &A) {

    int j = 0;
    for(int i=0;i<A.size();++i){
        while(i<A.size()-1 && A[i]==A[i+1]){    i++;    }
        swap(A[i], A[j]);
        j++;
    }

    A.erase(A.begin()+j, A.end());
    return j;
}


int main(){

	vector<int> A = { 1,1,1,1, 2,2,2,2, 3,3, 4,4,4,4};
	
	int len = removeDuplicates(A);
	cout << "len is " << len << "\n";
	cout << "array is : ";
	for(auto it :A){
		cout << it << " ";
	}
	cout << "\n";

    return 0;
}

