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
    int minAddToMakeValid(string S) {
        int left = 0;
        int count = 0;
        for(char ch : S){
            if(ch == '('){
                left++;
            }
            else if(ch == ')'){
                if(left == 0){
                    count++;
                }
                else{
                    left--;
                }
            }
        }
        count += left;
        return count;
    }
};

