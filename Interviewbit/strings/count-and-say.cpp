/*
 * Author : Jatin Rohilla
 * Date   : 17/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 * link - https://www.interviewbit.com/problems/count-and-say/
 *
 */


#include<iostream>
#include<string>
using namespace std;

string countAndSay(int A) {

	string begin = "1";
	string str ="" ;
	string res ="1" ;
	int count,n;
	A--;
	while(A--){
		//cout<<"str is "<<str<<"\n";
		str	= begin;
		n=str.length();
		res= "";
		
		for(int i=0;i<n;++i){
			count=1;
			//cout<<str[i]<<"\t"<<str[i+1];
			while(i<n && str[i]==str[i+1]){
				count++;
				i++;
			}
			res += to_string(count) + str[i];
		}
		//cout<<"Res is "<<res<<"\n";
		begin=res;
	}
	
	return res;
}


int main(){

	int n;
	n=1;
	//n=2;
	//n=4
	
	cout<<countAndSay(n);

    return 0;
}

