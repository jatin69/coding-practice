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
    string removeDuplicates(string S) {
        string res;     // use string as stack
        for(auto ch : S){
            if(res.size()==0){
                res.push_back(ch);
            }
            else if(ch == res.back()){
                res.pop_back();
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};

