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
    string removeOuterParentheses(string S) {
        int leftCount = 0;
        int rightCount = 0;
        string res = "";
        int start = 0;
        for(int i=0; i<S.length(); ++i){
            if(S[i]=='('){
                leftCount++;
            }
            else if(S[i]==')'){
                rightCount++;
            }
            if(leftCount == rightCount){
                res += S.substr(start+1, (i-start-1));
                leftCount = rightCount = 0;
                start = i+1;
            }
        }
        return res;
    }
};

