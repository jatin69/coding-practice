/*
 * Author : Jatin Rohilla
 * Date   : 12-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/power-of-2/
 */


#include<bits/stdc++.h>
using namespace std;

string divideStringByTwo(string n){

    int i=0;
    string res;
    int digit, quot , rem = 0;
    while(i<n.length()){
        digit = n[i]-'0';
        quot = (rem*10 + digit)/2;
        rem = digit%2;
        if(res.length()==0 && quot==0){
            // dont use 0 at starting
        }
        else{
            res.push_back(quot+'0');
        }

        i++;
    }
    return res;
}

int power(string A) {
    if(A.compare("1")==0){
        return 0;
    }

    string n = A;

    while(((n.back()-'0')%2==0) && (n.back()!='0')){
        n = divideStringByTwo(n);
    }

    if(n.compare("1")==0){
        return 1;
    }
    return 0;
}


int main(){

	vector<string> A = {
		"1", "2", "4", "7",
		"512", "1024", "2048", "5465768789", "432456700",
		"18446744073709550000",
		"34315486476536324",
		"147573952589676412928"
	};
	
	cout << "Testcases  : \n\n";
	for(auto s : A){
		cout << setw(30) << s << " :   " <<  setw(15) << ((power(s)) ? "Power of 2" : "Not Power of 2") << "\n";
	}

    return 0;
}

