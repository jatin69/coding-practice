/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(aux.empty()){
            _transfer();
        }
        int temp = aux.top();
        aux.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        if(aux.empty()){
            _transfer();
        }
        return aux.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return aux.empty() && s.empty();
    }

private:
    stack<int> s;
    stack<int> aux;

    /** transfers all elements from s to aux stack. */
    void _transfer(){
        while(!s.empty()){
            aux.push(s.top());
            s.pop();
        }
    }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
