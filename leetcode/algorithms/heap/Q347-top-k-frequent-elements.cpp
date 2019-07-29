/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// heap method

class Solution {
public:
    struct comp{
        bool operator()(auto& a, auto& b){
            if(a.second == b.second){
                a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto& ele : nums){
            m[ele]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq(m.begin(), m.end());

        vector<int> res;
        while(k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
};

// sort method

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto& ele : nums){
            m[ele]++;
        }
        vector<pair<int, int>> mapCopy(m.begin(), m.end());
        sort(mapCopy.begin(), mapCopy.end(), [](pair<int, int> a, pair<int, int> b){
            return (a.second > b.second);
        });

        vector<int> res;
        for(auto it = mapCopy.begin(); k>0 && it!=mapCopy.end(); ++it, --k){
            res.push_back(it->first);
        }
        return res;
    }
};


