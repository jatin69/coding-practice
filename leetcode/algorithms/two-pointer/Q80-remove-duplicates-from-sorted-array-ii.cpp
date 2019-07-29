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
    int removeDuplicates(vector<int>& nums) {
        // 2 pointer modified

        int k = 0;
        for(int i=0; i<nums.size(); ++i){
            nums[k] = nums[i];
            k++;
            if(i+1 < nums.size() && nums[i]==nums[i+1]){
                i++;
                nums[k] = nums[i];
                k++;
            }
            while(i+1 < nums.size() && nums[i]==nums[i+1]){
                i++;
            }
        }
        return k;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

