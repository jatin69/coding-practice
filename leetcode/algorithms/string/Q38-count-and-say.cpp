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
    string countAndSay(int n) {
        string s = "1";
        n = n-1;
        while(n--){
            string aux = "";
            for(int i=0; i<s.length(); ++i){
                int count = 1;
                while(i+1 < s.length() && s[i]==s[i+1]){ i++; count++; }
                aux += to_string(count);
                aux.push_back(s[i]);
            }
            s = aux;
        }
        return s;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

