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

int singleNumber(const vector<int> &A) {
    int num = 0;
    for(auto it : A){
        num ^= it;
    }
    return num;
}

int main(){

	vector<int> A = {1,2,2,3,1};
	cout << singleNumber(A);

    return 0;
}

