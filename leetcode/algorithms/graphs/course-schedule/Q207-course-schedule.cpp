/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// simple topological sort

// using indegree method

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree;

        // vector<vector<int>> adj(numCourses, vector<int>());
        // vector<int> degree(numCourses, 0);

        int dependent, independent;
        for(auto& coursePair : prerequisites){
            dependent = coursePair[0];
            independent = coursePair[1];
            adj[independent].push_back(dependent);
            degree[dependent]++;
        }


        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(degree[i] == 0){
                q.push(i);
            }
        }

        int totalCoursesToTake = numCourses;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            totalCoursesToTake--;
            for(auto next : adj[curr]){
                degree[next]--;
                if(degree[next] == 0){
                    q.push(next);
                }
            }
        }

        return totalCoursesToTake == 0;
    }
};


