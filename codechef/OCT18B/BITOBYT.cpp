#include<iostream>
using namespace std;

int main(){

	long long int t;
	long long int n;
	cin>>t;
	while(t--){
		cin >> n;
		long long int bits = 1;
		long long int nibbles = 0;
		long long int bytes = 0;

		long long int i=0;
		long long int p = -1 ;
		long long int next = 2;
		while(i + next < n){

			i = i+next;
			
			if(bits!=0){
				nibbles += 1L*bits;
				bits = 0;
				next = 8;
				
			}
			else if(nibbles!=0){
				bytes += 1L*nibbles;
				nibbles = 0;
				next = 16;
				
			}
			else if(bytes!=0){
				bits += 2L*bytes;
				bytes = 0;
				next = 2;
				
			}
			
		}

		cout << bits << " " << nibbles << " " << bytes << "\n";


	}

    return 0;
}

