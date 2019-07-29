/*
 * Author : Jatin Rohilla
 * Date   : 10/06/18
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Objective : find the duplicate element in read only array.
 * Below used approach can also be applied when it is allowed to modify the array.
 * NOTE : Array element has range 1 to n
 *
 * (buggy) question - https://www.interviewbit.com/problems/find-duplicate-in-array/
 * question and solution differ.
 *
 * n+1 elements given, range is 1 to n, one element is repeated
 * approach -
 * simply xor all array element & elements 1 to n
 * 1 to n will form xor pairs and cancel out. Duplicated one wil be left.
 *
 * This method can only be used when a single duplicate is there.
 * fails when multiple duplicates like [ 3, 4, 1, 4, 1]
 *
 * Time : Order N
 * Space : order 1
 */


#include<bits/stdc++.h>
using namespace std;



int repeatedNumber(const vector<int> &A) {

	int nPlusOne = A.size();
	int n = nPlusOne-1;
	int x = 0;
	x ^= A[0];
    for(int i=1;i<=n;++i){
        x ^= A[i]^i;
    }
    if(x==0){
		return -1;
	}
	return x;
}


int main(){

	vector<int> A = { 3, 2, 1, 4, 1};
	cout << repeatedNumber(A);


    return 0;
}

