/*
 * Author : Jatin Rohilla
 * Date   : 14-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/amazing-subarrays/
 */


#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': return true;
        default : return false;
    }
}

int solve(string A) {
    int count = 0;
    for(int i=0; i<A.length(); ++i){
        if(isVowel(A[i])){
            count += (A.length()-i);
            count %= 10003;
        }
    }
    return count;
}

int main(){

	string s;

	s = "ABEC";
	cout << solve(s) << "\n";

	s = "BUABEC";
	cout << solve(s) << "\n";

    return 0;
}

