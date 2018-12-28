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

	int n;
	cin>>n;
	while(n--){
		double L, K, T1, T2, H;
		cin>> L>>K>>T1>>T2>>H;
		// Rainfall rate :  mm per second
		double rainFallRate =  H/((T1-T2)*60*60);       // wrong
		double leakRate = K*60*60;
		
		
		
		double waterHeight;
		
		double time = T1*60*60;

		while(time--){
			waterHeight += rainFallRate;
			
			if(waterHeight >= L){
				waterHeight -= leakRate;
			}
		}
		
		cout << waterHeight;
		
		
		
	}

    return 0;
}

