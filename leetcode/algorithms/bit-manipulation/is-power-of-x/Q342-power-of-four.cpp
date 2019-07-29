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
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if((n&n-1)!=0){
            return false;
        }

        return (n & 0x55555555) != 0;
        // return (int)log2(n)%2==0;
    }
};
