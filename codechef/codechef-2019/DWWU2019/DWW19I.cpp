/*
 * Author : Jatin Rohilla
 * Date   : Dec-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> A(n);
		for(int i=0;i<n;++i){
			cin >> A[i];
		}
		
		if(n==1){
			cout << A[0] << " " << "1" << "\n";
			continue;
		}
		
		int answer = __gcd(A[0], A[1]);
		for(auto el : A){
			answer = __gcd(el, answer);
		}
		int cost = 0;
		for(auto el : A){
			cost += el / answer;
		}
		cout << answer << " " << cost << "\n";
	}
	return 0;
}
