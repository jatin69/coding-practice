/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// initial

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
        for (int p : prices) {
            b1 = max(b1, -p);
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        return s2;
    }
};

// more general

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);
        for(int p : prices){
            for(int i=k; i>=1; --i){
                buy[i] = max(buy[i], sell[i-1]-p);
                sell[i] = max(sell[i], buy[i]+p);
            }
        }
        return sell[k];
    }
};



