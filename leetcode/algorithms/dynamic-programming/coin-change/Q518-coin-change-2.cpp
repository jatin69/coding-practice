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
    int change(int target, vector<int>& coins) {
        vector<int> cache(target+1, 0);
        cache[0] = 1;

        for(auto coin : coins){
            for(int i=coin; i<=target; ++i){
                cache[i] += cache[i-coin];
            }
        }
        return cache[target];
    }
};

