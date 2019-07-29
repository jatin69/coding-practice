/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    bool s[1'000'001] = {false};
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }

    void add(int key) {
        s[key] = true;
    }

    void remove(int key) {
        s[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return s[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

