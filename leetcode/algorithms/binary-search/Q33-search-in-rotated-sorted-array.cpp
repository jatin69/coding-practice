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
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<r){
            mid = l + (r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){

            }
            else{

            }
        }
        return -1;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

