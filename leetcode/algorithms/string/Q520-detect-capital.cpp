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
    bool detectCapitalUse(string word) {
        if(word.length() < 2){
            return true;
        }

        if(std::isupper(word[0])){
            if(std::isupper(word[1])){
                // all after this should be uppercase
                for(int i = 2; i<word.length(); ++i){
                    if(!isupper(word[i])) return false;
                }
            }
            else{
                // all after this should be lowercase
                for(int i = 2; i<word.length(); ++i){
                    if(!islower(word[i])) return false;
                }
            }
        }
        else{
            // all after this should be lowercase
            for(int i = 1; i<word.length(); ++i){
                if(!islower(word[i])) return false;
            }
        }

        return true;
    }
};

