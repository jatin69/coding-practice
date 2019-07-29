/*
 * Author : Jatin Rohilla
 * Date   : June-July-2019
 *
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 */


#include<bits/stdc++.h>
using namespace std;

// source code here
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart=0;
        int windowEnd=0;
        unordered_map<char, int> charMap;

        int maxLen = 0;
        while(windowEnd < s.length()){
            if(charMap.find(s[windowEnd]) != charMap.end()){
                maxLen = max(maxLen, windowEnd-windowStart);
                windowStart = max(windowStart, charMap[s[windowEnd]] + 1);
            }
            charMap[s[windowEnd]] = windowEnd;
            windowEnd++;
        }
        maxLen = max(maxLen, windowEnd-windowStart);
        return maxLen;
    }
};


// using set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart=0;
        int windowEnd=0;
        unordered_set<char> charSet;

        int maxLen = 0;
        while(windowEnd < s.length()){
            if(charSet.find(s[windowEnd]) != charSet.end()){
                maxLen = max(maxLen, windowEnd-windowStart);
                charSet.erase(s[windowStart]);
                windowStart++;
            }
            else{
                charSet.insert(s[windowEnd]);
                windowEnd++;
            }
        }
        maxLen = max(maxLen, windowEnd-windowStart);
        return maxLen;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

