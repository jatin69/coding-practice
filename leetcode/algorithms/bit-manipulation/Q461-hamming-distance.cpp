/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// explicit

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int count = 0;
        while(n){
            count++;
            n = n & n-1;
        }
        return count;
    }
};


// STL

class Solution {
public:
    int hammingDistance(int x, int y) {
        return std::bitset<32>(x^y).count();
    }
};

