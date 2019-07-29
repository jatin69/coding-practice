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
    bool search(vector<int>& nums, int target) {

        /*
        Approach : Modified binary search.
        Assumptions : array was ascending order before rotation

        Cases handled -
            1. Array may or may not be rotated
            2. Array may or may not have duplicates.
        */

        // edge cases
        if(nums.size() == 0) return false;
        if(nums.size() == 1) return nums[0] == target;

        int l = 0;
        int r = nums.size()-1;

        while (l <= r) {

            // skip duplicates from the left
            // condition (l+1 <= r) ; both shouldn't be same
            while (l < r && nums[l] == nums[l + 1]){ l++; }

            // skip duplicates from the right
            // condition (l <= r-1) ; both shouldn't be same
            while (l < r && nums[r] == nums[r - 1]){ r--;}

            // to prevent overflow
            int mid = l + (r-l)/2;

            // is target found ?
            if (target == nums[mid]){   return true; }

            // right side is not sorted; go check left side
            if (!(nums[mid] <= nums[r])) {
                if (nums[l] <= target && target < nums[mid]) { r = mid - 1; }
                else                                         { l = mid + 1; }

            }

            // left side is not sorted; go check right side
            else if (!(nums[l] <= nums[mid])){
                if (nums[mid] < target && target <= nums[r]){ l = mid + 1; }
                else                                        { r = mid - 1; }
            }

            // both side are sorted; there is no rotation
            else {
                if (target < nums[mid]){ r = mid - 1; }
                else                   { l = mid + 1; }
            }
        }
        return false;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

