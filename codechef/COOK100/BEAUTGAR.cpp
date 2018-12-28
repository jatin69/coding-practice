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
	while(t--){
		string s;
		cin>>s;
		int n = s.size();

		if(n==1){
			cout << "yes" << "\n";
		}
		else if(n&1){
			cout << "no" << "\n";
		}
		else{
			int cutA = -1, cutB = -1;
			bool failed = false;
			for( int i=0; i<n; ++i){
				if(s[i]==s[(i+1)%n]){
//					
//					if(s[i] == s[(i+2)%n] ){
//						failed = true;
//						break;
//					}
					
					if(cutA==-1){
						cutA = (i+1)%n;
					}
					else if(cutB == -1){
						cutB = i;
					}
					else{
						failed = true;
						break;
					}
				}
			}
//			cout << "cut A : " << cutA << " and cutB " << cutB << "\n";
			if(failed || ( cutA!=-1 && (cutB==-1 || cutA==cutB))) {
				cout << "no" << "\n";
			}
			else{
				cout << "yes" << "\n";
			}
		}
	}

    return 0;
}

