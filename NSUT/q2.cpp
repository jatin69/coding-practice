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

int main(){

lli t;
cin>>t;
while(t--){
	lli a, b;
	cin>>a>>b;
	vector<int> A(101);
	lli value = log(a);
	lli dest = log(b);
	for(int i=0;i<A.size();++i){
		A[i] = ceil((i)*value);
	}

}
    return 0;
}

