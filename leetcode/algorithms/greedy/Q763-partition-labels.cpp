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
    vector<int> partitionLabels(string S) {

        // get last occurence of alphabets
        vector<int> lastOccurence(26, 0);
        for(int i=0; i<S.length(); ++i){
            lastOccurence[S[i]-'a'] = i;
        }

        vector<int> res;
        int begin = 0;
        int end = 0;
        for(int i=0; i<S.length(); ++i){
            end = max(end, lastOccurence[S[i]-'a']);
            if(i == end){
                res.push_back(end-begin+1);
                begin = end+1;
            }
        }
        return res;
    }
};



