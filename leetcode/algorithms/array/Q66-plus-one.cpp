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
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1; i>=0; --i){
            digits[i] += carry;
            carry = digits[i]/10;
            if(carry == 0){
                break;
            }
            else{
                digits[i] %= 10;
            }
        }
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

