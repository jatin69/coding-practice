/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::primesum(int A) {
    vector<bool> sieve(A+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2; i<=A; ++i){
        if(sieve[i]){
            for(int j=2; i*j <= A ;++j){
                sieve[i*j] = false;
            }
        }
    }

    int i;
    for(i=2; i<=A;++i){
        if(sieve[i] && sieve[A-i]){
            break;
        }
    }
    return {i, A-i};
}


