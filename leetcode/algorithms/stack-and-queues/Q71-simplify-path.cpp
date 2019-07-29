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
    string simplifyPath(string path) {
        vector<string> res;
        std::stringstream ss(path);
        string s;
        while(getline(ss, s, '/')){
            if(s == "." || s=="") continue;
            if(s==".."){
                if(!res.empty()){
                    res.pop_back();
                }
            }
            else{
                res.push_back(s);
            }
        }

        string output = "";
        for(auto it : res){
            output += "/" + it;
        }
        if(output == ""){
            output = "/";
        }
        return output;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

