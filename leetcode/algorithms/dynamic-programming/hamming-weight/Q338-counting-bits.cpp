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
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0] = 0;
        for(int i=1; i<=num; ++i){
            res[i] = res[ i>>1 ] + (i & 1);
        }
        return res;
    }
};

