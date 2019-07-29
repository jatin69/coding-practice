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
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> cache(grid[0].size(), INT_MAX);

        cache[0] = 0;
        for(int i=0; i<grid.size(); ++i){
            // cout << "entering cache : ";
            // for(auto it : cache){ cout << it << " "; } cout <<"\n";
            cache[0] += grid[i][0];
            for(int j=1; j<grid[0].size(); ++j){
                cache[j] = min(cache[j], cache[j-1]) + grid[i][j];
            }
            // cout << "exiting cache : ";
            // for(auto it : cache){ cout << it << " "; } cout <<"\n";
        }
        return cache.back();
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

