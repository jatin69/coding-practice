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
    int fib(int N) {
        if(N==0 || N==1){
            return N;
        }
        int first = 0;
        int second = 1;
        int res;
        for(int i=2; i<=N; ++i){
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};


