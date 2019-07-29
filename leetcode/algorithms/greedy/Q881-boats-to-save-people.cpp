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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0;
        int j=people.size()-1;
        int count = 0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
                count++;
            }
            else{
                j--;
                count++;
            }
        }
        return count;
    }
};



