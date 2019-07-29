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
    struct comparator{
      bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs){
          if(lhs.first == rhs.first){
              // freq is same
              // lexographically greater first ( kinda max heap ) : opposite sign used
              return lhs.second < rhs.second;
          }
          // min heap : less freq first : opposite sign to be used
          return lhs.first > rhs.first;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {

        // count frequency
        unordered_map<string, int> m;
        for(auto word : words){
            m[word]++;
        }

        // put in priority queue
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        for(auto it : m){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        // form result
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};

