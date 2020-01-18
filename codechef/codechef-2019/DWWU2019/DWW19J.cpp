/*
 * Author : Jatin Rohilla
 * Date   : Dec-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){

	if(n<=1) return false;

	int limit = sqrt(n);
	for(int i=2; i<=limit; ++i){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		if(isPrime(n)){
			cout << "Divesh\n";
		}
		else{
			cout << "Tanya\n";
		}
	}
	return 0;
}

