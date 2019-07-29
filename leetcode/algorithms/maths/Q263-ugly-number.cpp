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
    bool isUgly(int num) {
        if(num < 1){
            return false;
        }

        while(num%2==0){
            num /= 2;
        }

        while(num%3==0){
            num /= 3;
        }

        while(num%5==0){
            num /= 5;
        }

        return num==1;
    }
};

