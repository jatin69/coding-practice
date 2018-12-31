/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * Question - https://codingninjas.in/app/practice/62938/3170/shubham-and-tea
 * TLE. Needs DP
 * editorial attached.
 */
 

#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& redBulls, vector<int>& teaCups, int i, int currRedBulls, int maxTeaCups){
	
	if(i==teaCups.size() || currRedBulls==0){
		cout << "\nreturning : "<< maxTeaCups;
		return maxTeaCups;
	}
	
	return max(
				func(redBulls, teaCups, i+1, currRedBulls-1, maxTeaCups+teaCups[i]),    // pick teacups
				func(redBulls, teaCups, i+1, currRedBulls-1 + redBulls[i], maxTeaCups)  // pick redbulls
			  );
	
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int S, R;
		cin>>S>>R;
		vector<int> redBulls(S+1);
		for(int i=1;i<=S;++i){
			cin>>redBulls[i];
		}
		vector<int> teaCups(S+1);
		for(int i=1;i<=S;++i){
			cin>>teaCups[i];
		}
		
		int shopId = 1;
		int currRedBulls = R;
		int maxTeaCups = 0;
		cout << "\n" << func(redBulls, teaCups, shopId, currRedBulls, maxTeaCups);
		cout << "\n";
	}

    return 0;
}

/*
1
5 2
1 1 1 1 1 1
11 10 9 0 10 
*/
