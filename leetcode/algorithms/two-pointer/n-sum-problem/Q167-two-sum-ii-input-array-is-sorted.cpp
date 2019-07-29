/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if( sum == target ){
                return {i+1, j+1};
            }
            if(sum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};

