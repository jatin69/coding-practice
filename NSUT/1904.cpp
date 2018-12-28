/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, // no of songs in playlist
	 	w, // partly allowed
	    k; // time taken to reach home
	cin>>n>>w>>k;
	
	// pleasures
	vector<int> pleasure(n);
	for(int i=0;i<n;++i){
		cin>> pleasure[i];
	}
	
	// lengths
	vector<int> length(n);
	for(int i=0;i<n;++i){
		cin>> length[i];
	}
	
	vector<int> sol(n);
	
	for(int i = n-1; i>=0 ; i--){

		int timeToHome = k;
		int partlyAllowed = w;

		int j = i;
		int currentPleasure = 0;
		while(timeToHome && j<n){

			int halfLen = ceil(length[j]/2);
			
			if(partlyAllowed && timeToHome >= halfLen){
				currentPleasure += pleasure[j];
				timeToHome -= halfLen;
				partlyAllowed--;
			}
			else if( timeToHome >= length[j] ){
				currentPleasure += pleasure[j];
				timeToHome -= length[j];
			}
			else{
				break;
			}
			j++;
		}
		sol[i] = currentPleasure;
	}
	
	int maxVal = sol[0];
	int idx = 0;
	for(int i=1; i<n; ++i){
		if( sol[i]  > maxVal){
			maxVal = sol[i];
			idx = i;
		}
	}
	
	cout << maxVal ;
	
	
    return 0;
}

