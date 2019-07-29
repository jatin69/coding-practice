/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::coinchange2(vector<int> &coins, int target) {
     vector<int> cache(target+1, 0);
        cache[0] = 1;

        for(auto coin : coins){
            for(int i=1; i<=target; ++i){
                if((i-coin >=0)){
                    cache[i] += cache[i-coin];
                }
            }
        }
        return cache[target];
}


