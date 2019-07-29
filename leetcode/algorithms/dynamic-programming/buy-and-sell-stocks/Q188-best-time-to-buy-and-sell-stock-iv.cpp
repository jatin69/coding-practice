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
    int maxProfit(int k, vector<int>& prices) {
        int prevSell = 0;
        int currSell = 0;
        int currBuy = INT_MIN;
        for(int p : prices){
            for(int i=k; i>=1; --i){
                currBuy = max(currBuy, prevSell - p);
                currSell = max(currSell, currBuy + p);
                prevSell = currSell;
            }
        }
        return currSell;
    }
};

