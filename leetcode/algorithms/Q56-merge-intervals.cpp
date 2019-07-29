/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2){
            return intervals;
        }

        sort(begin(intervals), end(intervals), [](auto a, auto b){
            if(a[0]==b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

