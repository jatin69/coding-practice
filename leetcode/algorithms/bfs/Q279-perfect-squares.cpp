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
    int numSquares(int n) {
        if(n==1){
            return 1;
        }

        // find all perfect squares
        vector<int> perfectSquares;
        for(int i=1; i*i<=n; ++i){
            perfectSquares.push_back(i*i);
        }

        // iterative BFS
        int levelMarker =  0;
        int level = 1;
        bool isDone = false;

        queue<int> q;
        q.push(n);
        q.push(levelMarker);

        while(1){
            int root = q.front(); q.pop();
            if(root == levelMarker){
                if(q.empty()){
                    break;
                }
                level++;
                q.push(levelMarker);
            }
            else{
                for(int i=0; i<perfectSquares.size() && perfectSquares[i] <= root; ++i){
                    if(root == perfectSquares[i]){
                        isDone = true;
                        break;
                    }
                    q.push(root-perfectSquares[i]);
                }
                if(isDone){
                    break;
                }
            }
        }

        return level;
    }
};

