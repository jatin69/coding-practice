/*
 * Author : Jatin Rohilla
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * https://leetcode.com/problems/array-partition-i/description/
 */


#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int sum=0;
    for(int i=0;i<nums.size();i=i+2){
        sum += nums[i];
    }
    return sum;
}

int main(){

	vector<int> A = {1,4,3,2};
	
	cout << arrayPairSum(A);

    return 0;
}

