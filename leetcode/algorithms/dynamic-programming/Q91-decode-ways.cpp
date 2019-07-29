/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        if(n==0) return 0;
        if(n==1) return (s[n-1]-'0' >= 1 && s[n-1]-'0' <=9) ? 1 : 0;

        int first = 1;
        int second = (s[n-1]-'0' >= 1 && s[n-1]-'0' <=9) ? 1 : 0;
        int third;
        int val;
        for(int i = n-2; i>=0 ;--i){

            third = 0;
            val = ((s[i]-'0'));
            if(val >=1 && val <= 9){
                third += second;
            }
            val = ((s[i]-'0')*10 + (s[i+1]-'0'));
            if(val >=10 && val <= 26){
                third += first;
            }
            first = second;
            second = third;
        }
        return third;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

