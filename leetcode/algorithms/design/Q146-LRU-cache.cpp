/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:

    // LRU cache capacity; user defined
    int capacity;

    // doubly linked list for quick addition and deletion
    // list of key, val because
    // we also want to use hashmap erase when we have just the list iterator
    list<pair<int, int>> dataList;

    // hashmap -> (key, dataList iterator)
    unordered_map<int, list<pair<int,int>>::iterator> cache;

public:

    // constructor
    LRUCache(int _capacity) : capacity(_capacity) {}

    // get the key's data value
    int get(int key) {

        // find in hashmap; return -1 if not found
        auto it = cache.find(key);
        if (it == cache.end()){  return -1; }

        // access the element; move to head of dataList
        int currKey = it->second->first;
        int currValue = it->second->second;
        dataList.erase(it->second);
        dataList.push_front({currKey, currValue});
        it->second = dataList.begin();

        return it->second->second;
    }

    // put key value if not exists; update key's value if exists
    void put(int key, int value) {

        // find in hashmap
        auto it = cache.find(key);
        if(it == cache.end()){

            // if capacity is reached, delete last item
            // cache.size() is faster than list.size()
            if(cache.size() == capacity){
                cache.erase(dataList.back().first);
                dataList.pop_back();
            }

            dataList.push_front({key, value});
            cache[key] = dataList.begin();
            return;
        }

        // already exists, just access/update it

        // move to front of dataList
        dataList.erase(it->second);
        dataList.push_front({key, value});
        it->second = dataList.begin();  // update iterator's value
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

