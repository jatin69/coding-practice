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
    bool isPalindrome(string s) {
        if(s.length()==0){
            return true;
        }
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(isalnum(s[l])){
                if(isalnum(s[r])){
                    if(std::tolower(s[l])!=std::tolower(s[r])){
                        return false;
                    }
                    l = l+1;
                    r = r-1;
                }
                else{
                    r = r-1;
                }
            }
            else{
                if(isalnum(s[r])){
                    l = l+1;
                }
                else{
                    l = l+1;
                    r = r-1;
                }
            }
        }
        return true;
    }
};
