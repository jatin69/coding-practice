/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::numSetBits(unsigned int A) {
    unsigned int n = A;
    int count = 0;
    while(n){
        n &= n-1;
        count++;
    }
}


