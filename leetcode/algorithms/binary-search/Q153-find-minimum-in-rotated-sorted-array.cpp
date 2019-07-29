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
     int findMin(vector<int> &nums) {
            if (nums.empty()) {
            return -1;
        }

        int n = nums.size();
        int left = 0, right = n - 1;

        // handles duplicates ( useful for - /find-minimum-in-rotated-sorted-array-ii )
        while (left < right && nums[left] == nums[right]) {
            right -= 1;  // or left += 1; if index is not asked
        }

        // reason:
        // 1. delete only one of the duplicates will not lose min even if duplicates happen to be min
        // 2. make left line > right line, return to the Find Minimum in Rotated Sorted Array I
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
     }
};

