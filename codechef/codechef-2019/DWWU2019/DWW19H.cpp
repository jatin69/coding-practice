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
		cin.ignore();
		string s;
		getline(cin, s);
		
		// S is just middle, no connection
		
		if(!(s[0]=='S' && s.back()=='S')){
			
			int count = 0;
			for(char ch : s){
				if(ch=='S') count++;
			}

			if(count < 2){
				cout << "0\n";
			}
			else{
				cout << n * (count-1) << "\n";
			}

			continue;
		}
		
		// S at the back and front
		


		
	}
	return 0;
	
}



