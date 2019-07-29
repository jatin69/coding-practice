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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<long long int> dp(n,0);
        dp[0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(obstacleGrid[i][j] == 1 ){
                  dp[j]=0;
                }
                else if(j>0) {
                  dp[j] += dp[j-1];
                }

            }
        }
        return dp[n-1];
    }

    // my solution
    /*
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid.size()==0) return 0;
        if(obstacleGrid[0].size()==0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long int>> cache(m, vector<long long int>(n));
        cache[0][0] = 1;

        for(int i=1; i<m; ++i){
           cache[i][0] = (obstacleGrid[i][0] == 1 ? 0 : cache[i-1][0]);
        }
        for(int j=1; j<n; ++j){
            cache[0][j] = (obstacleGrid[0][j] == 1 ? 0 : cache[0][j-1]);
        }

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                cache[i][j] = (obstacleGrid[i][j] == 1) ? 0 : cache[i-1][j] + cache[i][j-1];
            }
        }
        return cache[m-1][n-1];
    }
    */
};

int main(){

	cout<<"Hello World";

    return 0;
}

