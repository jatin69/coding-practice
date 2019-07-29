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
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i=0; i<prices.size(); ++i){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else if(prices[i]-minPrice > maxProfit){
                maxProfit = prices[i]-minPrice;
            }
        }
        return maxProfit;
    }
};


// even better

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN, s1 = 0;
        for (int p : prices) {
            b1 = max(b1, -p);
            s1 = max(s1, b1 + p);
        }
        return s1;
    }
};
