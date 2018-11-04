/*
failing on
95, 83

should be 1, 9 => *6, digitsum, *1, digitsum
mine => *7, digitsum, digitsum, digitsum

Can be done by recursion ? Full Binary Tree ? How to find leaves ?

*/

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int lli;

lli digitSum(lli N){

	lli sum = 0;
	while(N){
		sum += (N%10);
		N /= 10;
	}
	return sum;
}

bool isSingleDigit(lli n){
	return (n>=0 && n<=9);
}

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n, d ;
		cin>>n>>d;

		lli
			curr ,
			multiplier ,
			dsum,
			minDsum,
			minVal = n + 1 // always replaced in first time
			;

		for(lli i=0; i<10; ++i){
			
			dsum = 0;

			// add i times
			curr = n + (d*i);
			
			// then digit sum recursively
			while(!isSingleDigit(curr)){
				curr = digitSum(curr);
				dsum++;
			}

			if( curr < minVal){
				minVal = curr;
				multiplier = i;
				minDsum = dsum;
			}

			if(curr == 1L){
				break;
			}
		}
		cout << "mul is " << multiplier << "\n";
		lli steps = multiplier + minDsum;
		cout << minVal << " " << steps << "\n";
	}

    return 0;
}

