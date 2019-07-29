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
    vector<int> dailyTemperatures(vector<int>& T) {
        // this is next greater element problem

        stack<int> s;
        vector<int> res(T.size(), 0);
        for(int i=0; i<T.size(); ++i){
            while(!s.empty() && T[i] > T[s.top()]){
                res[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

