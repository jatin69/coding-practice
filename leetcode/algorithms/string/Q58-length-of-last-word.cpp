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
    int lengthOfLastWord(string s) {
        // skip all space from back
        int i = s.length()-1;
        while( i>=0 && s[i]==' '){ i--; }
        // count until space comes
        int len = 0;
        while( i>=0 && s[i]!=' '){ i--; len++; }
        return len;
    }
};

int main(){

	cout<<"Hello World";

    return 0;
}

