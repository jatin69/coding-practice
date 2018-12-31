/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int A[n+1][n+1]{0};
		
		int counter = 0;
		int i,j;
		A[1][1] = ++counter;

		for(int rowEle=2 ; rowEle<n+1; ++rowEle){
			i = 1;
			j = rowEle;
			while(i && j>0){
				A[i][j] = ++counter;
				i++;
				j--;
			}
		}
		
		for(int colEle = 2; colEle<n+1; ++colEle) {
			i = colEle;
			j = n;
			while( i<n+1 && j){
				A[i][j] = ++counter;
				i++;
				j--;
			}
		}
		
		for(int i = 1;i<n+1;++i){
			for(int j=1;j<n+1;++j){
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
	}

    return 0;
}

