/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    int n = A.size();

    // finding a-b : sum of numbers
    long long int  aMINUSb = 0;
	for(int i=0; i<n; ++i){
    	aMINUSb += ((A[i]) - (i+1));
    }
//	cout << "a-b : " << aMINUSb << "\n";
    
    // finding a+b : sum of squares
    long long int  aPLUSb = 0;
	for(int i=0; i<n; ++i){
    	aPLUSb += ((A[i]+(i+1)) * (A[i]-(i+1)));
	}
    aPLUSb /= aMINUSb;
//    cout << "a+b : " << aPLUSb << "\n";
	
	long long int a = (aPLUSb + aMINUSb)/2;
    long long int b = aPLUSb - a;

    return {a, b};
}

int main(){

	vector<int> A = { 3, 1, 2, 5, 3};
	vector<int> res = repeatedNumber(A);
	for(auto it : res){
		cout << it << " ";
	}

    return 0;
}

