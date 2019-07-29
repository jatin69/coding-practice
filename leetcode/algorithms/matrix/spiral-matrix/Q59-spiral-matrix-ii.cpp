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
    vector<vector<int>> generateMatrix(int n) {
        if(n==0){ return {};    }
        if(n==1){ return {{1}}; }

        vector<vector<int>> res(n, vector<int>(n));
        int num = 1, limit = n*n;
        int begin = 0, end = n;
        int r = 0, c = 0;
        dir direction = RIGHT;

        while(num <= limit){
            switch(direction){
                case RIGHT:{
                    while(c < end){
                        res[r][c] = num++;
                        c++;
                    }
                    r++;
                    c--;
                    direction = DOWN;
                }break;
                case DOWN:{
                    while(r < end){
                        res[r][c] = num++;
                        r++;
                    }
                    r--;
                    c--;
                    direction = LEFT;
                }break;
                case LEFT:{
                    while(c >= begin){
                        res[r][c] = num++;
                        c--;
                    }
                    r--;
                    c++;
                    direction = UP;
                }break;
                case UP:{
                    while(r > begin){
                        res[r][c] = num++;
                        r--;
                    }
                    r++;
                    c++;
                    begin++;
                    end--;
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

