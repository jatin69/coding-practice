/*
 * Author : Jatin Rohilla
 * Date   : 8/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * link - https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0/
 *
 * approach - efficient method to check multiple of 3 is-
 * count set bits at odd place, count set bits at even places
 * if the difference of both is a multiple of 3, the number is also multiple of 3.
 */


#include<iostream>
#include<math.h>
using namespace std;

int main(){

	int t,n,evencount,oddcount;
	cin>>t;
	string num;
	while(t--){
		oddcount=0;
		evencount=0;
		cin>>num;

		n= num.size();
		if(n%2 !=0){
			num.push_back(0);
			n++;
		}
		for(int i=0;i<n; i=i+2){
			if(num[i]=='1'){
				oddcount++;
			}
			if(num[i+1]=='1'){
				evencount++;
			}
		}
		
		int count = abs(oddcount-evencount);
		if(count%3==0){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
	}

    return 0;
}

