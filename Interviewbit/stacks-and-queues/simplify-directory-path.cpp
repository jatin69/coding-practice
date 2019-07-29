/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

string Solution::simplifyPath(string str) {
    std::stringstream ss(str);
    string s;
    stack<string> st;
    while(getline(ss, s, '/')){
        if(s=="." || s==""){
            continue;
        }
        if(s==".."){
             if(!st.empty()){
                 st.pop();
             }
        }
        else{
            st.push(s);
        }
    }
    stack<string> r;
    while(!st.empty()){
        r.push(st.top()); st.pop();
    }
    string res = "";
    while(!r.empty()){
        res += "/" + r.top(); r.pop();
    }
    if(res == ""){
        res = "/";
    }
    return res;
}


