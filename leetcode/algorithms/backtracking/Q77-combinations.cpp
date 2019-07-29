/*
 * Author : Jatin Rohilla
 * Date   : 10-06-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;


/********************************** 80 ms *****************************/

class Solution {
public:
	// notice the call by reference of currList
    void backtrack(int n, int k, int start, vector<int>& currList, vector<vector<int>>& res){
        if(currList.size()==k){
            res.push_back(currList);
            return;
        }
        for(int i = start; i<=n; ++i){
            currList.push_back(i);
            backtrack(n, k, i+1, currList, res);
            currList.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<0 || k<1 || k>n){
            return res;
        }
        vector<int> currList;
        backtrack(n, k, 1, currList, res);
        return res;
    }
};

class Solution {
public:
    void backtrack(int n, int k, int start, vector<int>& currList, vector<vector<int>>& res){
        if(k==0){
            res.push_back(currList);
            return;
        }
        for(int i = start; i<=n; ++i){
            currList.push_back(i);
            backtrack(n, k-1, i+1, currList, res);
            currList.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<0 || k<1 || k>n){
            return res;
        }
        vector<int> currList;
        backtrack(n, k, 1, currList, res);
        return res;
    }
};

/********************************** 476 ms *****************************/

class Solution {
public:
	// notice the call by value of currList
    void backtrack(int n, int k, int start, vector<int> currList, vector<vector<int>>& res){
        if(currList.size()==k){
            res.push_back(currList);
            return;
        }
        for(int i = start; i<=n; ++i){
            currList.push_back(i);
            backtrack(n, k, i+1, currList, res);
            currList.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<0 || k<1 || k>n){
            return res;
        }
        backtrack(n, k, 1, {}, res);
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

