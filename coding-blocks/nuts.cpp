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

	int i,d,b,s;
	cin>>i>>d>>b>>s;
	
	allowed = min(i+1, s) - 1;
	i--;
	int boxcount = 0;
	while(d){

		while( d >= allowed+1){
			d = d- (b/allowed);
			boxcount++;
		}

		b = b % allowed;
	}
	


    return 0;
}

