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

    bool canPlaceFlowers(vector<int>& fb, int n) {

        bool possible;
        int count=0;

        for(int i=0;i<fb.size();++i){
            possible = true;
            if(fb[i]==0){

                if(i-1 >= 0 && fb[i-1]==1 ) possible = false;
                if(i+1 <= fb.size()-1 && fb[i+1]==1 ) possible = false;

                if(possible){
                    i++;
                    count++;
                    if(count>=n){
                        return true;
                    }
                }
            }
        }
        return (count>=n);
    }
};

