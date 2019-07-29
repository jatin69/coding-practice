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
    void backtrack(vector<int>& curr, int start, int& count){
        if(start == curr.size()){
            count++;
            return;
        }
        for(int i=start; i<curr.size(); ++i){
            if(start%curr[i] == 0 || curr[i]%start == 0){
                swap(curr[start], curr[i]);
                backtrack(curr, start+1, count);
                swap(curr[start], curr[i]);
            }
        }
    }

    int countArrangement(int N) {
        if(N==1){ return 1; }
        int count = 0;
        vector<int> curr(N+1);
        iota(curr.begin(), curr.end(), 0);
        backtrack(curr, 1, count);
        return count;
    }
};


