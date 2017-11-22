/*
 * Author : Jatin Rohilla
 * Date   : 23/11/2017
 *
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 */


#include<iostream>
using namespace std;


bool isPowerOfTwo(long long int n){
    long long int cmp= 1;
    while(cmp <= n){
        // cout<<"cmp is "<<cmp<<"\t";
        // cout<<"n is "<<n<<"\n";
        if(!(cmp ^ n)){
            return true;
        }
        cmp = cmp<<1;
    }
    return false;
}


int main(){

    cout << (isPowerOfTwo(0				)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(1				)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(16			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(128			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(4096			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(32768			)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(1048576		)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(2147483648	)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(4294967296	)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(8589934592	)?"yes":"no") << "\n";
    cout << (isPowerOfTwo(17179869184	)?"yes":"no") << "\n";


    return 0;
}

