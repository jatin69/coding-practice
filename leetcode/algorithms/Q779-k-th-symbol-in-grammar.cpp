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
    int kthGrammar(int N, int K) {
        if(N==1){
            return 0;
        }
        if(K%2==0){
            if(kthGrammar(N-1, K/2)==0){
                // parent : 0 & k is even (2)
                // => so 0 goes to 01 => even index value : 1
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            // parent : 0 & k is odd (1)
            // => so 0 goes to 01 => odd index value : 0
            if(kthGrammar(N-1, (K+1)/2)==0){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
};


