/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, ditemp, pitemp, deadi, reqi;
	cin>>t;
	while(t--) {
		
		int cummSum[32]{0};
		int D;
		cin>>D;
		while(D--){
			cin >> ditemp >> pitemp;
			cummSum[ditemp] = pitemp;
		}
		
		for(int i=1;i<=31;++i){
			cummSum[i] = cummSum[i] + cummSum[i-1];
		}

		int Q;
		cin>>Q;
		while(Q--){
			cin >> deadi >> reqi;
			if( cummSum[deadi] >= reqi ){
				cout << "Go Camp" << "\n";
			}
			else{
				cout << "Go Sleep" << "\n";
			}
		}
		
	}

    return 0;
}

