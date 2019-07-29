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
    enum dir{RIGHT, DOWN, LEFT, UP};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return {};
        }
        vector<int> res;
        int limit = matrix.size()*matrix[0].size();

        int rowBegin = 0;
        int rowEnd = matrix.size();
        int colBegin = 0;
        int colEnd = matrix[0].size();

        int r = 0;
        int c = 0;
        dir direction = RIGHT;

        while(res.size() < limit){
            switch(direction){
                case RIGHT: {
                    while(c < colEnd){ res.push_back(matrix[r][c]); c++; }
                    r++;
                    c--;
                    direction = DOWN;
                }break;
                case DOWN: {
                    while(r < rowEnd){ res.push_back(matrix[r][c]); r++; }
                    r--;
                    c--;
                    direction = LEFT;
                }break;
                case LEFT: {
                    while(c >= colBegin){ res.push_back(matrix[r][c]); c--; }
                    r--;
                    c++;
                    direction = UP;
                }break;
                case UP: {
                    while(r > rowBegin){ res.push_back(matrix[r][c]); r--; }
                    r++;
                    c++;
                    rowBegin++;
                    colBegin++;
                    rowEnd--;
                    colEnd--;
                    direction = RIGHT;
                }break;
            }
        }
        return res;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

