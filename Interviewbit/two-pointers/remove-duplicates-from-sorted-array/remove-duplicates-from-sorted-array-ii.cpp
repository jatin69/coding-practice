/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


int Solution::removeDuplicates(vector<int> &A) {
    int marked = A[0]-1;

    // mark
    for(int i=0; i+2<A.size(); ++i){
        if( i+2 < A.size() && A[i]==A[i+1] && A[i+1]==A[i+2]){
            A[i] = marked;
        }
    }

    // sweep
    int j = 0;
    for(int i=0; i<A.size(); ++i){
        if(A[i]!=marked){
            A[j] = A[i];
            j++;
        }
    }

    return j;
}

