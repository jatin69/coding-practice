/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

void Solution::nextPermutation(vector<int> &A) {
    // 1 2 4 3 => 1 3 2 4
    // 1 4 3 2
    // 4 3 2 1
    int i = A.size()-2;
    while(i>=0 && A[i] > A[i+1]){ i--; }
    if(i>=0){
        int j = A.size()-1;
        while(A[j] < A[i]){ j--; }
        swap(A[j], A[i]);
    }
    reverse(A.begin() + i+1, A.end());
}


