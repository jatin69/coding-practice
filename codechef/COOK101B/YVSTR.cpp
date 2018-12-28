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

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		std::unordered_set<std::string> myset;
		
		// baaabb => b,a,aa,aaa,b,bb => b,a,aa,aaa,bb => 5
		int start = 0;
		int i;
		for(i=0;i<n-1;++i){
			myset.insert(s.substr(start, i-start+1));
			if(s[i] != s[i+1]){
				start = i+1;
			}
		}
		myset.insert(s.substr(start, i-start+1));
		cout << myset.size() << "\n";
	}

    return 0;
}

