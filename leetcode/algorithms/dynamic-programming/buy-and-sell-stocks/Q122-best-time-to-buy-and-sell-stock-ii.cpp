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
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;

        int n = prices.size();
        int maxProfit = 0;
        int peak = prices[0];
        int valley = prices[0];

        int i=1;
        while(i < n){
            while(i < n && (prices[i] <= prices[i-1])){ i++;}
            valley = prices[i-1];
            while(i < n && (prices[i] >= prices[i-1])){ i++;}
            peak = prices[i-1];
            maxProfit += ( peak - valley );
        }
        return maxProfit;
    }
};
