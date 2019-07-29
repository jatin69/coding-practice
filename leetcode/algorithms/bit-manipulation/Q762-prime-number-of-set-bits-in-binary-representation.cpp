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
    bool isSmallPrime(int n){
        switch(n){
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19: return true;
            default: return false;
        }
    }
    int countPrimeSetBits(int L, int R) {

        // ceil(log2(pow(10,6))) is 20
        // we only need primes upto here
        // and only these many bits are needed to represent all numbers

        int count = 0;
        for(int i=L; i<=R; ++i){
            if(isSmallPrime(std::bitset<20>(i).count())){
                count++;
            }
        }
        return count;
    }
};

