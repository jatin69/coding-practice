/*
 * Author : Jatin Rohilla
 * Date   : 30-12-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC.
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,m;
	cin>>n>>m;
	vector<int> A(n+1);
	queue<pair<int, int>> children;
	for(int i=1;i<n+1;++i){
		cin>>A[i];
		children.push({i, A[i]});
	}
	
	
	pair<int, int> it ;
	while(!children.empty()) {
		it = children.front();
		children.pop();
		if(it.second-m > 0){
			children.push({it.first, it.second-m});
		}
	}
	
	cout << it.first ;
	return 0;
}

/*
editorial -

#include<iostream>
using namespace std;

int main() {
	int n,m,x,pos=0,maxi=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		if((x+m-1)/m >= maxi){
			pos=i;
			maxi=(x+m-1)/m;
		}
	}
	cout<<pos+1;
	return 0;
}

*/
