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
    // problem is defined only for recurring non finite
    // not defined for non recurring non finite
    string fractionToDecimal(int numerator, int denominator) {

        // edge case
        if(numerator == 0) {
            return "0";
        }

        string ans;

        // determining the sign of result
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }

        // convert to long to prevent overflow for -2^31
        long n = labs(numerator);
        long d = labs(denominator);
        long r = n % d;

        ans += to_string(n / d);

        // no remainder i.e. no fractical part
        if (r==0) {
            return ans;
        }

        // begin fractional part
        ans += '.';

        unordered_map<long, int> rs;
        while(r!=0){

            // has encountered this `r` before ?
            if (rs.find(r) != rs.end()) {
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }

            // store at which index this remaining was seen
            rs[r] = ans.size();

            // adding that 0 at the end
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};


