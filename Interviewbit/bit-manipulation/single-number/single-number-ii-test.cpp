/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

int count_method(vector<int> A){
	
	vector<int> count(32);
	int result = 0;
	for(int b=0; b<32; ++b){
		for(int i=0; i<A.size(); ++i){
			count[b] += (A[i] >> b) & 0x1;
		}
		result |= (count[b]%3 <<b);
	}
	return result;
}

int main(){

	vector<int> A = {
		1,1,1,2,2,4,2
	};
	int one=0, two=0, three=0;
	for(auto it : A){
		
		two |= (one & it);
		one ^= it;
		
		three = (one & two);
		one &= ~three;
		two &= ~three;
	}
	
	cout << one << "\n";
	
	cout <<count_method(A) << "\n";
    return 0;
}

