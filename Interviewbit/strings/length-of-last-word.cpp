/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/length-of-last-word/
 */


#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {

    int ws=0, we=0, len = 0;
    int i = A.length()-1;

    while(i>=0 && A[i]==' '){ --i; }
    we = i+1;
    // cout << "we is " << we << ", ";

    while(i>=0 && A[i]!=' '){ --i; }
    ws = i+1;

    // cout << "ws is " << ws << ", ";
    len = we - ws ;
    return len;
}

int main(){

	string s;
	
	s = "   ";
	cout <<lengthOfLastWord(s) << "\n";
	
	s = "d";
	cout <<lengthOfLastWord(s) << "\n";

	s = "Hello World";
	cout <<lengthOfLastWord(s) << "\n";

	s = "  Hello World  ";
	cout <<lengthOfLastWord(s) << "\n";

    return 0;
}

