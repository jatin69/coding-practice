/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());

    int minXOR = INT_MAX;
    for(int i=1;i<A.size();++i){
        minXOR = min(minXOR, A[0]^A[i]);
    }

    for(int i=0;i<A.size()-1;++i){
        minXOR = min(minXOR, A[A.size()-1]^A[i]);
    }

    return minXOR;
}


