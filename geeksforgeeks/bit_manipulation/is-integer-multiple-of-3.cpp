/*
 * Author : Jatin Rohilla
 * Date   : 8/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * follow up - https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0/
 * approach - following same approach, diff of set bits at odd and even places.
 */


#include<iostream>
using namespace std;

int isMultiple(int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 0;
	}
	int odd=0,even=0;
	while(n){
		if(n & 1){
			even++;
		}
		n=n>>1;
		
		if(n & 1){
			odd++;
		}
		n=n>>1;
	}
	return isMultiple(abs(even-odd));
}

int main(){

	int n=30;

	cout<< (isMultiple(n)?"yes":"no");


    return 0;
}

