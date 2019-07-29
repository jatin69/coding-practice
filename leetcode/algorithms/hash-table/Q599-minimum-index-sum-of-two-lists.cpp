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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> initialMap;
        for(int i=0; i<list1.size(); ++i){
            initialMap[list1[i]] = i;
        }
        map<int, vector<string>> intersectionMap;
        for(int i=0; i<list2.size(); ++i){
            if(initialMap.count(list2[i]) > 0){
                intersectionMap[initialMap[list2[i]] + i].push_back(list2[i]);
            }
        }
        return intersectionMap.begin()->second;
    }
};

