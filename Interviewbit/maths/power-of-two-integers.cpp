/*
 * Author : Jatin Rohilla
 * Date   : 2-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * https://www.interviewbit.com/problems/power-of-two-integers/
 *
 */


#include<bits/stdc++.h>
using namespace std;

// editorial
int isPower(int A) {
    if(A==1)	return 1;
    
    for(int i=2;i<=sqrt(A);i++){
        long long int num=1;
        while(true){
		// moving forward as powers of i : step by step incremental method
            num=num*i;
            if(num==A){
				return 1;
			}
            else if(num>A){
				break;
			}
        }
    }

    return 0;
}

// avoid logs : extremely unpredictable
int isPower_mine(int N) {
    if(N==1){
        return 1;
    }

    int limit = sqrt(N);
    float P;
    cout << "limit is " << limit << "\n";
    for(int A = 2; A <= limit ; ++A ){
        P = (float) log(N)/(float)log(A);
        cout << "P is " << fixed << P << "\n";
        if(P - (int)P < 0.0001){
            return 1;
        }
    }

    return 0;
}

int main(){

	int n;
	cout.precision(10);
	
	n=1;
	cout << "N is " << n << " and result is : " << isPower(n) << "\n\n";

	n=4;
	cout << "N is " << n << " and result is : " << isPower(n) << "\n\n";

	n = 16808;  // 0
	cout << "N is " << n << " and result is : " << isPower(n) << "\n\n";

	n = 823543;
	cout << "N is " << n << " and result is : " << isPower(n) << "\n\n";

	n = 536870912;
	cout << "N is " << n << " and result is : " << isPower(n) << "\n\n";
	
	n = 1024000000;
	cout << "N is " << n << " and result is : " << isPower(n) << "\n\n";

    return 0;
}

