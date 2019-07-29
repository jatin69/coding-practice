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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;
        for(int  currAmount=1; currAmount<=amount; ++currAmount){
            int currMinCoins = INT_MAX;
            for(auto val : coins){
                if(currAmount-val >= 0 && dp[currAmount-val] >= 0 ){
                    currMinCoins = min(currMinCoins, dp[currAmount-val]) ;
                }
            }
            if(currMinCoins == INT_MAX){
                dp[currAmount] = -1;
            }
            else{
                dp[currAmount] = currMinCoins + 1;
            }
        }
        return dp[amount];
    }
};

// updated

class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        vector<int> cache(target+1, 0);
        cache[0] = 0;
        for(int i=1; i<=target; ++i){
            int minCoins = INT_MAX;
            for(auto coin : coins){
                if(i-coin >=0){
                    minCoins = min(minCoins, cache[i-coin]);
                }
            }
            cache[i] = (minCoins == INT_MAX) ? INT_MAX : minCoins+1;
        }
        for(auto it : cache){
            cout << it << " ";
        }
        return cache[target]==INT_MAX ? -1 : cache[target];
    }
};


// latest

class Solution {
public:
    int coinChange(vector<int>& coins, int target) {

        int MAX = target + 1;
        vector<int> cache(target+1, MAX);

        cache[0] = 0;
        for(auto coin : coins){
            for(int i=coin; i<=target; ++i){
                // 2 WAYS : choose this coin, or don't choose
                cache[i] = std::min(cache[i], cache[i-coin]+1);
            }
        }
        return cache[target]==MAX ? -1 : cache[target];
    }
};
