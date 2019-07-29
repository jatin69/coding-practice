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
    int evalRPN(vector<string>& tokens) {
        // postfix evaluation

        stack<int> s;
        int n1, n2, res;

        for(auto token : tokens){
            if(token == "+"){
                n2 = s.top(); s.pop();
                n1 = s.top(); s.pop();
                res = (n1 + n2);
                s.push(res);
            }
            else if(token == "-"){
                n2 = s.top(); s.pop();
                n1 = s.top(); s.pop();
                res = (n1 - n2);
                s.push(res);
            }
            else if(token == "*"){
                n2 = s.top(); s.pop();
                n1 = s.top(); s.pop();
                res = (n1 * n2);
                s.push(res);
            }
            else if(token == "/"){
                n2 = s.top(); s.pop();
                n1 = s.top(); s.pop();
                res = (n1 / n2);
                s.push(res);
            }
            else{
                s.push(stoi(token.c_str()));
            }
        }
        return s.top();
    }
};

