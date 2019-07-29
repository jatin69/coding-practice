/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */

#include <iostream>
using namespace std;
int getSum(vector<int>& nums, int i, int target){
    cout << "i is "<< i << " and target is  " << target << "\n";
    if(i==nums.size() && target == 0){
        return 1;
    }
    if(i<nums.size()){
        return (getSum(nums, i+1, target - nums[i]) + getSum(nums, i+1, target + nums[i]));
    }
    return 0;
}
int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.size()==0){
        return 0;
    }
    return getSum(nums, 0, S);
}
int main() {
    vector<int> v = {1, 1, 2};
    cout << findTargetSumWays(v, 2);
}

