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
    int numJewelsInStones(string J, string S) {
        vector<int> exists('z' + 1, 0);

        for(auto& ch: J){
            exists[ch] = 1;
        }
        int count = 0;
        for(auto& ch : S){
            if(exists[ch]){
                count++;
            }
        }
        return count;
    }
};
