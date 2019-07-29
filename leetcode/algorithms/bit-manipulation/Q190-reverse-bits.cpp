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
    uint32_t reverseBits(uint32_t n) {
        int bits = 8*sizeof(n);
        uint32_t m = 0;
        for (int i = 0; i < bits; i++) {
            m <<= 1;
            m |= n & 1;
			n >>= 1;
        }
        return m;
    }
};

/*
uint32_t reverseBits(uint32_t n) {

    // swap 16 bit groups
    n = ((n & 0x0000FFFF) << 16) | ((n & 0xFFFF0000) >> 16);

    // swap 8-bit groups
    n = ((n & 0x00FF00FF) << 8) | ((n & 0xFF00FF00) >> 8);

    // swap 4-bit groups
    n = ((n & 0x0F0F0F0F) << 4) | ((n & 0xF0F0F0F0) >> 4);

    // swap 2-bit groups
    n = ((n & 0x33333333) << 2) | ((n & 0xCCCCCCCC) >> 2);

    // swap adjacent bits
    n = ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA) >> 1);

    return n;
}
*/
