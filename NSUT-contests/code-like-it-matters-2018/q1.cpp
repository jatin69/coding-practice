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

typedef long long int lli;

string tostr(lli d){
	string res, ans ;
	int q;
	
	while(d>9){
		q = d%10;
		d = d/10;
		switch(q){
			case 0 : ans = '0'; break;
			case 1 : ans = '1'; break;
			case 2 : ans = '2'; break;
			case 3 : ans = '3'; break;
			case 4 : ans = '4'; break;
			case 5 : ans = '5'; break;
			case 6 : ans = '6'; break;
			case 7 : ans = '7'; break;
			case 8 : ans = '8'; break;
			case 9 : ans = '9'; break;
		}
		res.append(ans);
	}
	
	switch(d){
		case 0 : ans = '0'; break;
		case 1 : ans = '1'; break;
		case 2 : ans = '2'; break;
		case 3 : ans = '3'; break;
		case 4 : ans = '4'; break;
		case 5 : ans = '5'; break;
		case 6 : ans = '6'; break;
		case 7 : ans = '7'; break;
		case 8 : ans = '8'; break;
		case 9 : ans = '9'; break;
	}
	res.append(ans);
	return res;
}

int LenANDtoBaseA(lli x, lli a){
	
	string ans ;
	int d;
	while(x >= a){
		d = x % a;
		ans.append(tostr(d));
		x = x/a;
	}
	ans.append(tostr(x));
	return ans.length();
}

int main(){
	

lli t;
cin>>t;

while(t--){
	lli x, a;
	cin>>x>>a;

	lli sum = 0;
	for(lli i=0; i<=x; ++i){
		sum += LenANDtoBaseA(i, a);
	}
	cout << sum  << "\n";

}
	
    return 0;
}

