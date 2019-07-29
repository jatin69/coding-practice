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
    int countPrimes(int n) {
        if(n<2){
            return 0;
        }
        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;
        int count = 0;
        for(int i=2;i<n;++i){
            if(sieve[i]){
                count++;
                for(int j=2; i*j<n; ++j){
                    sieve[i*j] = false;
                }
            }
        }
        return count;
    }
};

