/*
 * Author : Jatin Rohilla
 * Date   : 6-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/colorful-number/
 */


#include<bits/stdc++.h>
using namespace std;

int colorful(int A) {
    string s = to_string(A);
    int psize, pbeg, pend;

    std::unordered_map<long long int, int> m;

    for(psize = 1; psize <= s.length(); ++psize){
        for(pbeg = 0; pbeg + psize -1< s.length() ; ++pbeg){
            pend = pbeg + psize - 1;

            long long int product = 1;
            for(int i=pbeg; i<=pend; ++i){
                product *= (s[i]-'0');
            }

            if(m.find(product)==m.end()){
                m[product] = 1;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}

int main(){

	int n;

	n = 23;
	cout <<colorful(n) << "\n";

	n = 3245;
	cout <<colorful(n) << "\n";
	
	n = 323;
	cout <<colorful(n) << "\n";

    return 0;
}

