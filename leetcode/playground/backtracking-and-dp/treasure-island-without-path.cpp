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
    // Point(int _x=-1, int _y=-1, int _steps=-1) : x{_x}, y{_y}, steps{_steps}{}
    // friend ostream& operator << (ostream& os, const Point& ob);
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

// ostream& operator << (ostream& out, const Point& p){
//     out << "{"<< p.x <<", " << p.y << "} and steps : " << p.steps << "\n";
//     return out;
// }

int minPath(vector<vector<char>> grid){
    int r = grid.size();
    int c = grid[0].size();

    // bfs to find shortest path
    vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int x = 0, y = 0, steps = 0;
    // priority_queue<Point, vector<Point>, Point> q;
    queue<Point> q;
    q.push({x, y, steps});
    grid[x][y] = 'D';
    Point p;
    while(!q.empty()){
        // p = q.top();
        p = q.front();
        q.pop();
        steps = p.steps + 1;
        for(auto d : dir){
            x = p.x + d.first;
            y = p.y + d.second;
            if(x >= 0 && y>=0 && x<r && y<c && grid[x][y]!='D'){
                cout << "{"<< x <<", " << y << "} and steps : " << steps << "\n";

                // to reach last element
                // if(x == r-1 && y==c-1){ return steps; }

                // to reach just X
                if(grid[x][y]=='X'){ return steps; }

                q.push({x, y, steps});
                grid[x][y] = 'D';
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<char>> grid = {
        {'O','O','O','O'},
        {'D','O','D','O'},
        {'O','O','O','O'},
        {'X','D','D','O'}
    };
    cout << minPath(grid);
}


