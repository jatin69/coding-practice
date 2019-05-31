/*
 * Author : Jatin Rohilla
 * Date   : 27-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/redundant-braces/
 */


#include<bits/stdc++.h>
using namespace std;

int braces(string A) {
    stack<char> s;

    for(int i=0; i<A.length(); ++i){
        if(A[i]!=')'){
            s.push(A[i]);
        }
        else{
            bool isRedundant = true;
            while(!s.empty()){
                if(s.top()=='('){
                    s.pop();
                    break;
                }
                if(s.top()=='+' || s.top()=='-'  || s.top()=='*'  || s.top()=='/'){
                    isRedundant = false;
                }
                s.pop();
            }
            if(isRedundant){
                return 1;
            }
        }
    }
    return 0;
}


int main(){

	string s;

	s = "(a + (a + b))";
	cout << braces(s) << "\n";

	s = "((a))";
	cout << braces(s) << "\n";

	s = "((a + b))";
	cout << braces(s) << "\n";

	return 0;
}

