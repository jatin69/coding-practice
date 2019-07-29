/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::lis(const vector<int> &A) {
    if(A.size()==0) return 0;
    if(A.size()==1) return 1;

    vector<int> LIS(A.size(), 1);
    for(int i=1; i<A.size(); ++i){
        for(int j=0; j<i; ++j){
            if(A[i] > A[j]){
                LIS[i] = max(LIS[i], LIS[j]+1);
            }
        }
    }
    return *max_element(begin(LIS), end(LIS));
}


