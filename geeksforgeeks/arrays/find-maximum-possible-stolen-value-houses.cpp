/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Related problem : max-sum-without-adjacent-editorial.cpp
 *
 */


#include<iostream>
using namespace std;

int main(){

	int A[]={6, 7, 1, 3, 8, 2, 4};
	int n = sizeof(A)/sizeof(A[0]);

	int max_val,pred,prev;
	
	pred=A[0];
	prev=max(A[0],A[1]);
	max_val=max(prev,pred);
	
	for(int i=2;i<n;++i){
		max_val= max( pred+A[i], prev);
		pred=prev;
		prev=max_val;
	}
	
	cout<<max_val<<"\n";

    return 0;
}

