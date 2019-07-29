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
    string largestNumber(vector<int>& nums) {
        // 4ms code

        vector<string> strs;
        for(auto ele : nums){
            strs.push_back(to_string(ele));
        }
        sort(strs.begin(), strs.end(), [](string a, string b){
            return (a + b) > (b + a) ;
        });

        // minor edge case. Even after sorting, largest element is zero.
        // it will just make 00000
        if(strs[0] == "0"){ return "0"; }

        string res = "";
        for(auto s : strs){
            res += s;
        }
        return res;
    }
};

/*
// 12 ms
string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b){
        return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
    });
    if(nums[0]==0){
        return "0";
    }
    string res = "";
    for(auto ele : nums){
        res += to_string(ele);
    }
    return res;
}

*/

