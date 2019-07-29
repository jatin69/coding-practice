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
    vector<string> findOcurrences(string text, string first, string second) {
        std::istringstream ss(text);
        vector<string> aux, res;
        string token;
        while(getline(ss, token, ' ')){
            aux.push_back(token);
        }
        for(int i=2; i<aux.size(); ++i){
            if(aux[i-2] == first && aux[i-1] == second){
                res.push_back(aux[i]);
            }
        }
        return res;
    }
};
