/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

int Solution::maxProfit(const vector<int> &prices) {
    if(prices.size() < 2){
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;
    for(int i=1; i<prices.size(); ++i){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        else if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}


