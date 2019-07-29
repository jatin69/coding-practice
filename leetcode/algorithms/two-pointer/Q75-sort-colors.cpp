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
    void sortColors(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return;
        }

        int i = 0;              // walker
        int p = 0;              // zero tracker
        int q = nums.size()-1;  // two tracker

        while(i <= q){
            if(nums[i]==0){
                swap(nums[i], nums[p]);
                p++;
                i++;   // this walker gave me 0, and 0 is what was needed
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[i], nums[q]);
                q--;
                // notice how i is not incremented
                // this walker may or may not give me 0, i need to verify in next iteration
            }
        }
    }
};
/*
void sortColors(vector<int>& nums){
    int low = 0, mid = 0, high = nums.size() - 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}
*/


int main(){

	cout<<"Hello World";

    return 0;
}

