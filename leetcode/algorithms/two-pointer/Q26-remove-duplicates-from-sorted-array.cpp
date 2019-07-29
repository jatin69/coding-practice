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
        // two pointer method

        if(nums.size()==0){
            return 0;
        }

        int k = 1;
        int i = 1;
        while(i < nums.size()){
            if(nums[i]==nums[i-1]){
                i++;
            }
            else{
                nums[k] = nums[i];
                i++;
                k++;
            }
        }
        return k;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

