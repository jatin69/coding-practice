/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// better - 12ms

class Solution {
public:
    void capture(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }

        if(grid[i][j]!='1'){
            return;
        }

        grid[i][j] = '2';
        capture(grid, i, j+1);
        capture(grid, i, j-1);
        capture(grid, i+1, j);
        capture(grid, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int noOfIslands = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j = 0; j<grid[0].size(); ++j){
                if(grid[i][j]=='1'){
                    noOfIslands++;
                    capture(grid, i, j);
                }
            }
        }
        return noOfIslands;
    }
};


// naive - 84ms

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // edge case
        if(grid.size()==0){
            return 0;
        }

        int init_i = 0;
        int init_j = 0;
        int i;
        int j;
        int noOfIslands = 0;
        queue<pair<int, int>> q;
        set<pair<int, int>> s;

        while(1){
            if(q.empty()){
                bool flag = false;
                i = init_i;
                j = init_j;
                while(i < grid.size()){
                    while(j < grid[0].size()){
                        cout << "checking : i is " << i << " and j is " << j << "\n";
                        if(s.find({i, j})==s.end() && grid[i][j]=='1'){
                            flag = true;
                            break;
                        }
                        j++;
                    }
                    if(flag){
                        break;
                    }
                    i++;
                    j = 0;
                }

                cout << "i is " << i << " and j is " << j << "\n";
                if(i==grid.size()){
                    break;
                }
                init_i = i;
                init_j = j+2;

                noOfIslands++;
                q.push({i, j});
                s.insert({i, j});
            }
            std::tie(i, j) = q.front(); q.pop();
            // cout << "popped : i is " << i << " and j is " << j << "\n";

            // top
            if( i-1 >=0 && grid[i-1][j]=='1' && s.find({i-1, j})==s.end() ){
                // cout << "process : i is " << i+1 << " and j is " << j << "\n";
                q.push({i-1, j});
                s.insert({i-1, j});
            }

            // bottom
            if( i+1 < grid.size() && grid[i+1][j]=='1'  && s.find({i+1, j})==s.end() ){
                // cout << "process : i is " << i+1 << " and j is " << j << "\n";
                q.push({i+1, j});
                s.insert({i+1, j});
            }

            // left
            if( j-1 >=0 && grid[i][j-1]=='1'  && s.find({i, j-1})==s.end() ){
                // cout << "process : i is " << i << " and j is " << j+1 << "\n";
                q.push({i, j-1});
                s.insert({i, j-1});
            }

            // right
            if( j+1 < grid[0].size() && grid[i][j+1]=='1'   && s.find({i, j+1})==s.end() ){
                // cout << "process : i is " << i << " and j is " << j+1 << "\n";
                q.push({i, j+1});
                s.insert({i, j+1});
            }


        }
        return noOfIslands;
    }
};

