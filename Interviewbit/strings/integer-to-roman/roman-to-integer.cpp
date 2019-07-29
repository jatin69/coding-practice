/*
 * Author : Jatin Rohilla
 * Date   : 12-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/courses/1/topics/5/problems/roman-to-integer/previous_submissions/
 */


#include<bits/stdc++.h>
using namespace std;

int romanToInt(string A) {
    std::unordered_map<char, int> roman = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

    int res = 0;
    int i=0;
    for(i=0; i+1<A.length(); i++){
        if(roman[A[i]] >= roman[A[i+1]]){
            res += roman[A[i]];
        }
        else{
            res -= roman[A[i]];
        }
    }
    res += roman[A[i]];
    return res;
}

int main(){

	// assuming provided romans are correct
	vector<string> A = {
		"I", "IV", "XLIV", "LXXXVIII"
	};

	cout << "Testcases  : \n\n";
	for(auto s : A){
		cout << setw(10) << s << " :   " <<  setw(10) << romanToInt(s) << "\n";
	}

    return 0;
}

