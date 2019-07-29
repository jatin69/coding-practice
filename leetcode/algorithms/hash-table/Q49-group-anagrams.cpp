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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto it : strs){
            string s = it;
            sort(s.begin(), s.end());
            m[s].push_back(it);
        }
        vector<vector<string>> res;
        for(auto it : m){
            res.push_back(it.second);
        }
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

