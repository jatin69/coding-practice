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
    bool isHappy(int n) {
        unordered_set<int> s;
        int currNum = n, currSum = 0, d;
        while(currNum!=1){
            currSum = 0;
            while(currNum){
                d = currNum%10;
                currNum /= 10;
                currSum += (d*d);
            }
            if(s.count(currSum)>0){
                return false;
            }
            s.insert(currSum);
            currNum = currSum;
        }
        return true;
    }
};

