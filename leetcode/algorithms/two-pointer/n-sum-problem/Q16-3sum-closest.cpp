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
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(begin(nums), end(nums));

        int n = nums.size();
        int p, q, diff, minDiff = INT_MAX;

        for(int i=0; i+2<n; ++i){
            p = i+1;
            q = n-1;
            while(p<q){
                diff = (nums[i]+nums[p]+nums[q]-target);
                if(diff == 0){
                    return (diff + target);
                }
                else if(diff > 0){
                    q--;
                }
                else if(diff < 0){
                    p++;
                }
                if(abs(diff) < abs(minDiff)){
                    minDiff = diff;
                }
            }
        }
        return minDiff + target;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

