/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

string Solution::addBinary(string A, string B) {

    string res;
    int val = 0 ;
    int carry = 0;

    for(int i = A.length()-1, j = B.length()-1; i>=0 || j>=0; i--,j--){

        val = ((i>=0 ? A[i]-'0' : 0) + (j>=0 ? B[j]-'0' : 0) + carry);

        if(val==3)     {     val = 1;    carry = 1;  }
        else if(val==2){     val = 0;    carry = 1;  }
        else{                            carry = 0;  }
        res = to_string(val) + res;
    }
    if(carry==1){   res = '1' + res;    }
    return res;
}


