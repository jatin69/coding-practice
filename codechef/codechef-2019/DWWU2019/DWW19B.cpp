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
	cin.ignore();
	while(t--){
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		
		// count char in s1 and s2
		int c1[26]{0};
		for(char ch : s1){
			c1[ch-'A']++;
		}
		
		int c2[26]{0};
		for(char ch : s2){
			c2[ch-'A']++;
		}
		
		// traverse c2 and match with c1
		int count = 0 ;
		for(int i=0; i<26; ++i){
			if(c2[i] > c1[i]){
				count += (c2[i] - c1[i]);
			}
		}
		
		cout << count << "\n";
	}
}


