/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<n;++i){
        A[i] = (A[i]) + ((A[A[i]]%n)*n);
    }
    for(int i=0;i<n;++i){
        A[i] = A[i]/n;
    }
}

// 4 0 2 1 3
// 3 4 2 0 1
