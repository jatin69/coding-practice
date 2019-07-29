/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
    int steps;
    bool operator ()(const Point& a, const Point& b){
        if(a.steps == b.steps){
            if(a.y == b.y){
                // 3. prefer x axis
                return a.x > b.x;
            }
            // 2. prefer y axis
            return a.y > b.y;
        }
        // 1. prefer steps
        return a.steps > b.steps;
    }
};

bool dfs(vector<vector<char>>& grid, int x, int y, int steps, vector<Point>& res){

    // x and y will always be valid
    if(grid[x][y] == 'X'){
        return true;
    }

    // blocking it, so its neighbours does not come back to it
    grid[x][y] = 'D';

    // go to adjacent nodes
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(auto d : directions){
        int currX = x + d[0];
        int currY = y + d[1];
        int currSteps = steps + 1;

        // invalid x and y's are not allowed to pass through
        if( currX >= 0 && currX < grid.size() &&
            currY >=0 && currY < grid[0].size() &&
            grid[currX][currY] != 'D'
        ){
            if(dfs(grid, currX, currY, currSteps, res)==true){
                res.push_back({currX, currY, currSteps});
                // true returned so it propagates that result further
                // while unravling the recursion tree
                return true;
            }
        }
    }
    return false;
}

vector<Point> minPath(vector<vector<char>>& grid){

    // edge cases
    if(grid.size() == 0 || grid[0].size()==0 || grid[0][0] == 'D'){
        return {{-1, -1, -1}};
    }

    vector<Point> res;
    if(dfs(grid, 0, 0, 0, res) == false){
        return {{-1, -1, -1}};
    }
    res.push_back({0, 0, 0});
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<vector<char>> grid = {
        {'O','O','O','O'},
        {'D','O','D','O'},
        {'O','O','O','O'},
        {'X','D','D','O'}
    };

    auto res = minPath(grid);
    cout << "\nPath is : \n";
    for(auto p : res){
        cout << "{" << p.x << ", " << p.y << "} and step number is " << p.steps << "\n";
    }
}


