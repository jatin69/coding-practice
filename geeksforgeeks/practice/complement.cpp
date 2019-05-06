/*
 * Author : Jatin Rohilla
 * Date   : 10/06/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Question - https://practice.geeksforgeeks.org/problems/complement/0
 * similar to flip - https://www.interviewbit.com/problems/flip/
 *
 * Accepted.
 */


#include<bits/stdc++.h>
using namespace std;


/*
2D array approach. Nice work coming up with it. But we need better. It has -
O(n*n) time complexity
O(n*n) space complexity
*/
vector<int> flip(string str) {

	int n = str.length();
	int **A = new int*[n];
	for(int i=0;i<n;++i){
		A[i] = new int[n];
	}

	for(int i=0;i<n;++i){
		for(int j=i; j<n;++j){
			if(i==j){
				if(str[j]=='1'){
					A[i][j] = -1;
				}
				else{
					A[i][j] = 1;
				}
			}
			else{
				if(str[j]=='1'){
					A[i][j] = A[i][j-1] - 1;
				}
				else{
					A[i][j] = A[i][j-1] + 1;
				}
			}
		}
	}

	int max = 0;
	int imax = -1, jmax = -1;
	for(int i=0;i<n;++i){
		for(int j=i; j<n;++j){
			if(A[i][j]>max){
				max = A[i][j];
				imax = i;
				jmax = j;
			}
		}
	}

	if(max==0){
		return vector<int>();
	}
	else{
		vector<int> res = { imax+1, jmax+1 };
		return res;
	}
}


int main(){

	int t;
	cin>>t;
	int useless;
	string A;
	while(t--){
		cin>>useless;
		cin>>A;
		
		vector<int> res = flip(A);

		if(res.size()==0){
			cout << "-1\n";
		}
		else{
			cout << res[0] << " " << res[1] << "\n";
		}
	}

    return 0;
}

