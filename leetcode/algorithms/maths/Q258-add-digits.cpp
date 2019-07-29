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
    int addDigits(int num) {
        return num==0 ? 0 : (num%9==0) ? 9 : (num%9);
    }
};
