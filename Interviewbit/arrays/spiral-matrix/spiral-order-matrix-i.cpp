/*
 * Author : Jatin Rohilla
 * Date   : 4-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/spiral-order-matrix-i/
 */


#include<bits/stdc++.h>
using namespace std;

// note that matrix is not necessarily square

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> res;

    int m = A.size();
    int n = A[0].size();
    int count = m*n;
    int currCount = 0;

    int direction = 1;  // left
    int r=0, c=0;
    int rbegin=0, rend=m-1;
    int cbegin=0, cend=n-1;

    while(currCount < count){
        switch(direction){
            case 1 : {  // left
                while(c <= cend){
                    res.push_back(A[r][c]);
                    currCount++;
                    c++;
                }
                c--;
                r++;
                direction = 2;
            }break;
            case 2 : {  // down
                while(r <= rend){
                    res.push_back(A[r][c]);
                    currCount++;
                    r++;
                }
                r--;
                c--;
                direction = 3;
            }break;
            case 3 : {  // right
                while(c >= cbegin){
                    res.push_back(A[r][c]);
                    currCount++;
                    c--;
                }
                c++;
                r--;
                direction = 4;
            }break;
            case 4 : {  // up
                while(r > rbegin){
                    res.push_back(A[r][c]);
                    currCount++;
                    r--;
                }
                r++;
                c++;
                direction = 1;

                rbegin++;
                rend--;
                cbegin++;
                cend--;
            }break;
        }
    }
    return res;
}


int main(){

	vector<vector<int>> A = {

//		{1,2,3},
//		{4,5,6},
//		{7,8,9}
		
		{1,2},
		{3,4},
		{5,6},
		{7,8},

	};
    
    vector<int> res = spiralOrder(A);
    for(auto it : res){
    	cout << it << " ";
	}

	cout << "\n";
    
    return 0;
}

