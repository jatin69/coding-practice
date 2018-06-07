/*
 * Author : Jatin Rohilla
 * Date   : 06/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Q - Given an array of integers, every element appears twice except for one. Find that single one
 * approach : xor cancels out even occurences. single element remains.
 */


#include<bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
    int num = A[0];
    for(int i=1; i<A.size(); ++i){
        num ^= A[i];
    }
    return num;
}

int main(){

	vector<int> A = {
	1,1,2,3,4,5,3,5,4
	};
	int single = singleNumber(A);
	cout << "Single occurence element is : "<< single;
    return 0;

}

