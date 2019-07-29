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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        int temp;
        for(auto& row : A){
            for(int i=0; i<(n+1)/2; ++i){
                temp = row[i] ^ 1;
                row[i] = row[n-i-1] ^ 1;
                row[n-i-1] = temp;
            }
        }

        return A;
    }
};

