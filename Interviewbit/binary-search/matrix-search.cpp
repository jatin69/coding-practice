/*
 * Author : Jatin Rohilla
 * Date   : 4-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/matrix-search/
 */


#include<bits/stdc++.h>
using namespace std;

// approach - start from top right
int searchMatrix(vector<vector<int> > &A, int B) {

    int i = 0;
    int j = A[0].size()-1;

    while(i<A.size() && j>=0){
        if(B == A[i][j]){
            return 1;
        }
        else if(B < A[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}


int main(){

	vector<vector<int>> A ;

	A = {	{ 1,  3,  5, 7},
			{10, 11, 16, 20},
	  		{23, 30, 34, 50}
		};
	
	cout << searchMatrix(A, 3) << "\n";


	A = {	{1, 2, 4, 58, 60, 70, 99}
		};

	cout << searchMatrix(A, 58) << "\n";


    return 0;
}

