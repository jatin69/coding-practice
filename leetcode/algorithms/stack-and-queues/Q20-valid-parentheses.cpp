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
    bool isValid(string s) {

        stack<char> st;

        for(auto ch : s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty())              { return false;   }
                if(ch==')' && st.top()!='('){ return false;   }
                if(ch=='}' && st.top()!='{'){ return false;   }
                if(ch==']' && st.top()!='['){ return false;   }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

