/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::gcd(int A, int B) {
    if(B==0){
        return A;
    }
    return gcd(B, A%B);
}


