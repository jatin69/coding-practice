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
    int trailingZeroes(int n) {
        if(n<=0){
            return 0;
        }
        int count = 0;
        while(n){
            n /= 5;
            count += n;
        }
        return count;
    }
};

