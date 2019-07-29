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
    bool isIPValid(string& s){
        size_t prev = -1;
        size_t nPos = s.find(".");
        int count = 0;

        while(nPos != string::npos){

            // if len is > 3, it can never be under 256
            int len = nPos - prev - 1;
            if( len > 3 ){ return false; }

            // val should be under 256, and 0 should be single preceded
            int val = stoi(s.substr(prev+1, len));
            if(val > 255){ return false; }
            if(val >= 0 && val <=9 && len != 1){ return false; }
            if(val >= 10 && val <=99 && len != 2){ return false; }
            if(val >= 100 && val <=255 && len != 3){ return false; }

            count++;
            prev = nPos;
            nPos = s.find(".", nPos + 1);
        }


        if(count == 3){
            nPos = s.length();

            // if len is > 3, it can never be under 256
            int len = nPos - prev - 1;
            if( len > 3 ){ return false; }

            // val should be under 256, and 0 should be single preceded
            int val = stoi(s.substr(prev+1, len));
            if(val > 255){ return false; }
            if(val >= 0 && val <=9 && len != 1){ return false; }
            if(val >= 10 && val <=99 && len != 2){ return false; }
            if(val >= 100 && val <=255 && len != 3){ return false; }

        }

        return true;
    }

    void backtrack(string& s, int start, int dots, vector<string>& res){
        if(!isIPValid(s)){
            return;
        }
        if(dots == 0){
            res.push_back(s);
            return;
        }
        for(int len = 1; len <= 3 ; ++len){
            if(start+len >= s.length()) break;

            s.insert(start+len, ".");
            backtrack(s, start+len+1, dots-1, res);
            s.erase(start+len, 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        // an IP address has length between 4 and 12
        if(s.length() < 4 || s.length() > 12){
            return res;
        }

        backtrack(s, 0, 3, res);
        return res;
    }
};


int main(){

	cout<<"Hello World";

    return 0;
}

