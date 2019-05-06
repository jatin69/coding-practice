/*
 * Author : Jatin Rohilla
 * Date   : 1-09-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */
 
 // O(n) time
 // O(1) space version in screeenshots


#include<bits/stdc++.h>
using namespace std;

int OcountDecodings(string str, int s, int l, int* mem){
	
	cout << "called\n";
	if(s==l){
		return 1;
	}
	else if(s<l){
		int f1=0,f2=0;
		
		if(mem[s]!=0){
			return mem[s];
		}
		
		if(atoi(str.substr(s, 1).c_str()) <= 26){
			if(mem[s+1]==0){
				f1 = OcountDecodings(str, s+1, l, mem);
				mem[s+1] = f1;
			}
			else{
				f1 = mem[s+1];
			}
		}

		if(atoi(str.substr(s, 2).c_str()) <= 26){
			if(mem[s+2]==0){
				f2 = OcountDecodings(str, s+2, l, mem);
				mem[s+2] = f2;
			}
			else{
				f2 = mem[s+2];
			}
		}
		mem[s] = f1+f2;
		return mem[s];
	}
	else{
		return 0;
	}
}

int countDecodings(string str){

	int n = str.length();
	
	if(n==1){
		return 1;
	}

	int* mem = new int[n];
	for(int i=0;i<n;++i){
		mem[i] = 0;
	}
	
	mem[0] = 1;
	mem[1] = mem[0];

	if(atoi(str.substr((n-1)-1, 2).c_str()) <= 26){
		mem[1] += 1 ;
	}
	
	
	for(int i=n-2;i>0;--i){
		mem[n-i] = mem[n-i-1];
		if(atoi(str.substr(i-1, 2).c_str()) <= 26){
			mem[n-i] += mem[n-i-2];
		}
	}
	
	return mem[n-1];
	
}

int main(){

	string str = "1";
	
	/*
	1261
	
	1,2,6,1
	1,26,1
	12,6,1
	
	
	1,2,	1,1,2
	1,2,	11,2
	1,2,	1,12
	
	1,21, 1,2
	1,21, 12
	
	12, 	1,1,2
	12, 	11,2
	12, 	1,12
	
	*/


	/*
	1,2,	1,2
	1,2,	12
	1,21,2
	
	12,		1,2
	12,		12
	
	*/
	
	/*  121
	
	1,2,1
	1,21
	
	12,1

	*/
//	
//	int n = str.length();
//	int* mem = new int[n];
//	for(int i=0;i<n;++i){
//		mem[i] = 0;
//	}
	cout << countDecodings(str);

    return 0;
}

