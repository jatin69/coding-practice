/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    return (max(A[0]*A[1]*A[n-1], A[n-2]*A[n-3]*A[n-1]));
}



