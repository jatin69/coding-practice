/*
 * Author : Jatin Rohilla
 * Date   : 12-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/integer-to-roman/
 */


#include<bits/stdc++.h>
using namespace std;

string intToRoman(int A) {
    std::vector<pair<int, string>> roman = {
      { 1, "I"},
      { 4, "IV"},   { 5, "V"},
      { 9, "IX"},   { 10, "X"},
      { 40, "XL"},  { 50, "L"},
      { 90, "XC"},  { 100, "C"},
      { 400, "CD"}, { 500, "D"},
      { 900, "CM"}, { 1000, "M"}
    };

    string res;
    int n = A;
    int i=roman.size()-1;
    while(n){
        while(n >= roman[i].first){
            n -= roman[i].first;
            res.append(roman[i].second);
        }
        i--;
    }
    return res;
}

int main(){

	// assuming provided romans are correct
	vector<int> A = {
		1, 4, 44, 88, 45, 446, 756, 987, 3999
	};

	cout << "Testcases  : \n\n";
	for(auto s : A){
		cout << setw(10) << s << " :   " <<  setw(10) << intToRoman(s) << "\n";
	}

    return 0;
}

