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
    string addBinary(string a, string b) {
        string res = "";

        int i = a.length()-1, j = b.length()-1;
        int val = 0, carry = 0;

        while(i >=0 || j >=0 || carry==1){
            val = (i >=0 ? a[i--]-'0' : 0) + (j >=0 ? b[j--]-'0' : 0) + carry;
            res += (val%2) + '0';
            carry = val/2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

