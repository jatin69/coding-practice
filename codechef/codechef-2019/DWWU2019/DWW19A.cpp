/*
 * Author : Jatin Rohilla
 * Date   : Dec-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

int main(){
	unordered_map<char, char> m = {
		{ '1', '1' },
		{ '2', '7' }, { '7', '2' },
		{ '3', '8' }, { '8', '3' },
		{ '4', '5' }, { '5', '4' },
		{ '6', '9' }, { '9', '6' },
	};

	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		
		ulli i=0, j=s.length()-1;
		while(i<j && s[i]!='0' && s[j]!='0' && (s[i]==m[s[j]])){
			i++; j--;
		}
		
		if(i<j){
			cout << "false\n";
		}
		else if(i==j && s[i]=='0'){
			cout << "false\n";
		}
		else{
			cout << "true\n";
		}
	}
	return 0;
}


