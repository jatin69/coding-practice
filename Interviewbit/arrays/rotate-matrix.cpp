/*
 * Author : Jatin Rohilla
 * Date   : 18/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

link - https://www.interviewbit.com/problems/rotate-matrix/
Question - rotate matrix clockwise 90 degree

approach -
transpose & reverse each row
OR
reverse each column and transpose

 */


#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &A) {
	
	for(int i=0;i<A.size();++i){
		for(int j=i+1; j<A[i].size();++j){
			swap(A[i][j], A[j][i]);
		}
	}
	
	for(int i=0;i<A.size();++i){
		int j= 0;
		int k = A[i].size()-1;
		while(j<k){
			swap(A[i][j], A[i][k]);
			j++;
			k--;
		}
	}

}


int main(){

	vector<vector<int>> A = {
		{1,2},
		{3,4}
	};
	
	rotate(A);
	
	for(int i=0;i<A.size();++i){
		for(int j=0; j<A[i].size();++j){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

    return 0;
}

