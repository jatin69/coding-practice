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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size()-1;
        int carry = 0;
        int val = 0;
        vector<int> res;
        while(i >= 0 || K>0 || carry != 0){
            val = (i>=0 ? A[i--] : 0) + (K>0 ? K%10 : 0) + carry;
            res.push_back(val % 10);
            carry = val / 10;
            K = K / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

