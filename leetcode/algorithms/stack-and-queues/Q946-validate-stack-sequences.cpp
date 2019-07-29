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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        while(i < pushed.size() && j < popped.size()){
            if(!s.empty() && s.top() == popped[j]){
                s.pop();
                j++;
            }
            else{
                s.push(pushed[i]);
                i++;
            }
        }
        while(!s.empty() && s.top() == popped[j]){
            s.pop();
            j++;
        }
        return s.empty();
    }
};

