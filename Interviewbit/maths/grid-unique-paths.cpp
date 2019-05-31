/*
 * Author : Jatin Rohilla
 * Date   : 27-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/grid-unique-paths/
 * status - revise again
 */


#include<bits/stdc++.h>
using namespace std;

/******************************* my solution - recursion ***********************/

int paths(int row, int totalRows, int col, int totalColumns){
    if(row == totalRows-1 && col == totalColumns-1){
        return 1;
    }
    int n1 = 0;
    int n2 = 0;
    if(row+1 < totalRows){
        // cout << "calling (" << row+1 << ", " << col << ")" << " xx ";
        n1 = paths(row+1, totalRows, col, totalColumns);
    }
    if(col+1 < totalColumns){
        // cout << "calling (" << row << ", " << col+1 << ")" << " xx ";
        n2 = paths(row, totalRows, col+1, totalColumns);
    }
    return n1+n2;
}

int uniquePaths_mine(int A, int B) {
    return paths(0, A, 0, B);
}

/******************************* Editorial 1 - maths ***********************/

int uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)!
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}


/******************************* Editorial 2 - DP ***********************/

int uniquePaths(int A, int B) {
    vector<vector<int>> grid(A,vector<int>(B,0));
    if(A==0 && B==0)
        return 1;
    grid[0][0]=1;
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            if(i-1>=0)
                grid[i][j] += grid[i-1][j];
            if(j-1>=0)
                grid[i][j] += grid[i][j-1];
        }
    }

    return grid[A-1][B-1];
}


int main(){

	cout<<"Hello World";

    return 0;
}

