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
private:
    string rotateLock(string currLock, int index, int direction){
        currLock[index] = (((currLock[index] - '0') + direction + 10)%10)+'0';
        return currLock;
    }
public:
    int openLock(vector<string>& deadends, string target) {

        if(target == "0000"){
            return 0;
        }
        vector<vector<int>> possibleRotations = {
            {0, 1}, {0, -1},
            {1, 1}, {1, -1},
            {2, 1}, {2, -1},
            {3, 1}, {3, -1},
        };

        unordered_set<string> visited;
        for(auto it: deadends){
            visited.insert(it);
        }

        string levelMarker = "null";
        string currLock;
        int rotations = 1;

        queue<string> q;
        string possiblePath = "0000";
        if(visited.find(possiblePath)==visited.end()){
            q.push(possiblePath);
            visited.insert(possiblePath);
        }
        q.push(levelMarker);

        while(!q.empty()){
            currLock = q.front(); q.pop();
            if(currLock == levelMarker){
                if(q.empty()){
                    break;
                }
                rotations++;
                q.push(levelMarker);
            }
            else{
                for(auto option : possibleRotations){
                    possiblePath = rotateLock(currLock, option[0], option[1]);
                    if(possiblePath == target){
                        return rotations;
                    }
                    if(visited.find(possiblePath)==visited.end()){
                        q.push(possiblePath);
                        visited.insert(possiblePath);
                    }
                }
            }
        }
        return -1;
    }
};

