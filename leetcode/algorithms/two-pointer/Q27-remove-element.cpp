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
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=val){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

