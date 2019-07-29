/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int n, string curr, int& count){
        if(n==0){
            count++;
            return;
        }
        int j = 0;
        while(curr[j]=='0'){ j++; }
        string currWithoutLeadingZeroes = curr.substr(j, curr.length()-j);
        for(char i = '0' ; i<='9'; ++i){
            if(currWithoutLeadingZeroes.find(i, 0)==string::npos){
                backtrack(n-1, curr + i, count);
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        int count = 0;
        backtrack(n, "", count);
        return count;
    }
};

