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

	int m;
	cin>>m;
	
	int h1, a, x1, y1;
	cin>>h1>>a>>x1>>y1;

	int h2, b, x2, y2;
	cin>>h2>>b>>x2>>y2;
	
	int time = 0;
	while(h1<a || h2<b){
		++time;
		h1 = (((((x1%m) * (h1%m))%m) + (y1%m))%m);
		h2 = (((((x2%m) * (h2%m))%m) + (y2%m))%m);
		if(h1==0 || h2==0){
			time=-1;
			break;
		}
	}
	
	cout << time;
	
    return 0;
}

