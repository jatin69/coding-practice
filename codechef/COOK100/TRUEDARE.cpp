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
	int ele;
	
	while(t--){

		int tr;
		cin>>tr;
		set<int> TR;
		for(int i=0;i<tr;++i){
			cin >> ele;
			TR.insert(ele);
		}
		
		int dr;
		cin>>dr;
		set<int> DR;
		for(int i=0;i<dr;++i){
			cin >> ele;
			DR.insert(ele);
		}
		
		int ts;
		cin>>ts;
		set<int> TS;
		for(int i=0;i<ts;++i){
			cin >> ele;
			TS.insert(ele);
		}
		
		int ds;
		cin>>ds;
		set<int> DS;
		for(int i=0;i<ds;++i){
			cin >> ele;
			DS.insert(ele);
		}
		
		if( includes( TR.begin(), TR.end(), TS.begin(), TS.end()) && includes( DR.begin(), DR.end(), DS.begin(), DS.end()) ){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}

	}
    return 0;
}

