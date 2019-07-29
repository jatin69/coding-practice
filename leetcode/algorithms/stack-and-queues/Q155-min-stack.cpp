/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data.push(x);
        if (minimum.empty() || minimum.top() >= x) {
            minimum.push(x);
        }
    }

    void pop() {
        if (top() == getMin()) {
            minimum.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minimum.top();
    }
private:
    stack<int> data, minimum;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

