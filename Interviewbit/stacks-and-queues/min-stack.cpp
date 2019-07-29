/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int minEle;

MinStack::MinStack() {
    s = stack<int>();
    minEle = 0;
}

void MinStack::push(int x) {
    if(s.empty()){
        s.push(x);
        minEle = x;
    }
    else{
        if(x >= minEle){
            s.push(x);
        }
        else{
            s.push(2*x - minEle);
            minEle = x;
        }
    }
}

void MinStack::pop() {
    if(s.empty()){
        return;
    }
    if(s.top() >= minEle){
        return s.pop();
    }
    else{
        minEle = 2*minEle - s.top();
        s.pop();
    }
}

int MinStack::top() {
    if(s.empty()){
        return -1;
    }
    if(s.top() >= minEle){
        return s.top();
    }
    else{
        return minEle;
    }
}

int MinStack::getMin() {
    if(s.empty()){
        return -1;
    }
    return minEle;
}



