/*
 * Author : Jatin Rohilla
 * Date   : 27-05-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/evaluate-expression/
 */


#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A) {
    stack<int> s;
    int n1, n2, res;
    for(int i=0; i<A.size(); ++i){
        if(A[i].compare("+")==0){
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            res = n1 + n2;
            s.push(res);
        }
        else if(A[i].compare("-")==0){
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            res = n1 - n2;
            s.push(res);
        }
        else if(A[i].compare("*")==0){
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            res = n1 * n2;
            s.push(res);
        }
        else if(A[i].compare("/")==0){
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            res = n1 / n2;
            s.push(res);
        }
        else{
            s.push(atoi(A[i].c_str()));
        }
    }

    return s.top();
}


int main(){

	vector<string> A;

	A = {"2", "1", "+", "3", "*"};   // 9
	cout << evalRPN(A) << "\n";
	
	A = {"4", "13", "5", "/", "+"};   // 6
	cout << evalRPN(A) << "\n";

    return 0;
}

