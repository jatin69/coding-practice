/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
private:

    // max heap by default
    priority_queue<int, vector<int>, less<int>> leftHalf;

    // min heap
    priority_queue<int, vector<int>, greater<int>> rightHalf;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {

        // edge case
        if(leftHalf.empty()){
            leftHalf.push(num);
            return;
        }

        // lefthalf has size n+1 and rightHalf has size n
        if(leftHalf.size() > rightHalf.size()){
            if(num > leftHalf.top()){
                rightHalf.push(num);
            }
            else{
                rightHalf.push(leftHalf.top());
                leftHalf.pop();
                leftHalf.push(num);
            }
        }
        // lefthalf has size n and rightHalf has size n+1
        else if(rightHalf.size() > leftHalf.size()){
            if(num > rightHalf.top()){
                leftHalf.push(rightHalf.top());
                rightHalf.pop();
                rightHalf.push(num);
            }
            else{
                leftHalf.push(num);
            }
        }
        // lefthalf and rightHalf have equal elements
        else{
            if(num > ((leftHalf.top() + rightHalf.top())/2.0)){
               rightHalf.push(num);
            }
            else{
                leftHalf.push(num);
            }
        }
    }

    double findMedian() {

        // median is the root of the larger heap

        if(leftHalf.size() == rightHalf.size()){
            return ((leftHalf.top() + rightHalf.top())/2.0);
        }

        if(leftHalf.size() > rightHalf.size()){
            return leftHalf.top();
        }

        return rightHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

