/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


// approach 1 : sort

class Solution {
public:
    struct comp{
        int x;
        comp(int x){
            this->x = x;
        }
        bool operator()(const int &a, const int& b){
            if(abs(a-x) == abs(b-x)){
                return a<b;
            }
            return abs(a-x) < abs(b-x);
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), comp(x));
        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};


// approach 2 : binary search
// https://leetcode.com/articles/find-k-closest-elements/
