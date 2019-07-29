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
    int nextGreaterElement(int n) {
        if(n>=0 && n<=9){
            return -1;
        }

        int d;
        vector<int> digits;
        while(n){
            d = n%10;
            n = n/10;
            digits.push_back(d);
        }

        if(is_sorted(digits.begin(), digits.end())){
            return -1;
        }

        sort(digits.begin(), digits.end());
        int num = 0;
        for(int i=0; i<digits.size(); ++i){
            num += digits[i]*pow(10, i);
        }
        return num;
    }
};


