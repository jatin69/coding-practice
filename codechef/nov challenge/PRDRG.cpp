/*
 * Author : Jatin Rohilla
 * Date   : 3-11-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin>>n;
		long long int y =  1L << n;
		
		bool right = true;
		int ans = 0;
		
		while(n--){
			if(right){
				ans = (ans*2) + 1;
			}
			else{
				ans = (ans*2) -1;
			}
			right = !right;
		}
		
		cout << ans << " " <<  y << " ";
	}

    return 0;
}

