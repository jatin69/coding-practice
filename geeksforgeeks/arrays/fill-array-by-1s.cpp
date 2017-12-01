/*
 * Author : Jatin Rohilla
 * Date   : 01/12/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * link - https://practice.geeksforgeeks.org/problems/fill-array-by-1s/0
 * appraoch -
 
 Trivial solution  : perform actual iterations - TLE
 Thoughtful : count longest series of 0's
 when approached from both sides it takes approx n/2 iterations to fill.

 edge cases -
 starting and ending has zero series snake,
 we can only approach from one side, if this > prev n/2 value,
 this will need more time to fill.
 Also when the whole array is 0, it can never be filled, so display -1.
 
 */


#include<iostream>
using namespace std;

int main(){


	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		
		
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		
		bool allzero=true;
		for(int i=0;i<n;++i){
			if(a[i]==1){
				allzero=false;
			}
		}

		if(allzero){
			cout<< "-1" <<"\n";
			continue;
		}
		
		int count=0;
		int max=-1;

		// longest subarray of 0's
		for(int i=0;i<n;++i){
			
			if(a[i]==0){
				count=0;
				while(a[i]==0){
					i++;
					count++;
				}
				if(count>max){
					max=count;
				}
				
			}
		}
		
		// required iterations to fill those subarray
		int longest;
		if(max%2!=0){
			longest=max/2 + 1;
		}
		else{
			longest=max/2;
		}
		
		
		int i;
		
		// initial streak
		i=0;
		count=0;
		while(a[i]==0){
			i++;
			count++;
		}
		if(count>longest){
			longest=count;
		}
		
		// last streak
		i=n-1;
		count=0;
		while(a[i]==0){
			i--;
			count++;
		}
		if(count>longest){
			longest=count;
		}

		cout<< longest <<"\n";
	}


    return 0;
}

