/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    int capacity;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for(auto num : nums){
            pq.push(num);
            if(pq.size() > capacity){
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > capacity){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

