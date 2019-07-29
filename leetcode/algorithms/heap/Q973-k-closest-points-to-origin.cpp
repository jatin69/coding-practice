/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// sort and do

// partial sort

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin()+K, points.end(), [](const vector<int>& a, const vector<int>& b){
           return a[0]*a[0] + a[1]*a[1]  < b[0]*b[0] + b[1]*b[1];
        });
        return vector<vector<int>>(begin(points), begin(points) + K);
    }
};

// quick select - O(n)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // acts like partition function of quick sort
       nth_element(points.begin(), points.begin() + K , points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

// heap - priority queue

class Solution {
public:
    struct comparator{
      bool operator()(auto& lhs, auto& rhs){
          return lhs[0]*lhs[0] + lhs[1]*lhs[1] < rhs[0]*rhs[0] + rhs[1]*rhs[1];
      }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        for(auto it : points){
            pq.push(it);
            if(pq.size() > K){
                pq.pop();
            }
        }
        vector<vector<int>> res(K);
        while(!pq.empty()){
            res[--K] = pq.top();
            pq.pop();
        }
        return res;
    }
};

// explicit heaps

class Solution {
public:
    struct comparator{
      bool operator()(const vector<int>& lhs, const vector<int>& rhs){
          return lhs[0]*lhs[0] + lhs[1]*lhs[1] > rhs[0]*rhs[0] + rhs[1]*rhs[1];
      }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        vector<vector<int>> res(points.begin(), points.end());
        std::make_heap(res.begin(), res.end(), comparator());

        vector<vector<int>> out;
        while(K--){
            out.emplace_back(res.front());
            std::pop_heap(res.begin(), res.end(), comparator());
            res.pop_back();
        }
        return out;
    }
};
