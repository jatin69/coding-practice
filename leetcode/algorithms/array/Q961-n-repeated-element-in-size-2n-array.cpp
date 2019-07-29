/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (auto i = 0; i+2 < A.size(); ++i){
            if (A[i] == A[i + 1] || A[i] == A[i + 2]){
                return A[i];
            }
        }
        return A.back();
    }
};

