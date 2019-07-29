/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size()==0) return 0;
    if(A.size()==1) return 1;

    int n = A.size();
    vector<int> LIS(n, 1);
    for(int i = 1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(A[i] > A[j]){
                LIS[i] = max(LIS[i], LIS[j]+1);
            }
        }
    }

    vector<int> LDS(n, 1);
    for(int i = n-2; i>=0; --i){
        for(int j=i+1; j<n; ++j){
            if(A[i] > A[j]){
                LDS[i] = max(LDS[i], LDS[j]+1);
            }
        }
    }
    int maxVal = LIS[0] + LDS[0] - 1;
    for(int i=1; i<n; ++i){
        maxVal = std::max(maxVal, LIS[i] + LDS[i] - 1);
    }
    return maxVal;
}


