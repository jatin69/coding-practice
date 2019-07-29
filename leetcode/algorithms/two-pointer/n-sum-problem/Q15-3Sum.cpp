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
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i+2<nums.size() ;++i){
            int p = i+1;
            int q = nums.size()-1;
            int currSum = 0;
            while(p<q){
                currSum = nums[i]+nums[p]+nums[q];
                if(currSum==0){
                    res.push_back({nums[i], nums[p], nums[q]});
                    while(p<q && nums[p]==nums[p+1]){ p++; }
                    while(p<q && nums[q]==nums[q-1]){ q--; }
                    p++;
                    q--;
                }
                else if(currSum < 0){
                    p++;
                }
                else{
                    q--;
                }
            }
            while(i+2 < nums.size() && nums[i]==nums[i+1]){ i++; }
        }
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

