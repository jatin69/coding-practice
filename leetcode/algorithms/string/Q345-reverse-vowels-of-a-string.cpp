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
    string reverseVowels(string s) {

        int i = 0;
        int j = s.length()-1;
        const char* vowels = "aeiouAEIOU";

        while(i<j){

            if(strchr(vowels, s[i])==nullptr){ i++; continue; }
            if(strchr(vowels, s[j])==nullptr){ j--; continue; }

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};

