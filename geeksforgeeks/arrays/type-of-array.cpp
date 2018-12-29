/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * link - https://practice.geeksforgeeks.org/problems/type-of-array/0
 *
 * progress - figured out a way to correctly judge array. - can be optimised.
	now find max properly.
	
	** need more thought..
	damn, nice question.
 */

/*
test case
1
57
149 138 92 39 21 1006 964 938 927 914 850 838 828 814 803 796 786 782 773 756 753 735 698 679 654 632 623 621 616 600 578 552 548 539 517 515 509 500 480 474 453 438 432 414 405 379 365 358 353 350 334 309 247 245 207 193 153

Its Correct output is:
1006 3

*/

#include<iostream>
using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i){
			cin>>a[i];
		}

		int type,max;


		// ascending check
		int i=0;
		while( i+1<n && a[i]<a[i+1]){
			++i;
		}
		//cout<<"break at i="<<i<<"\n";
		
		// if broke at initial, go for descending part
		if(i==0){
			while( i+1<n && a[i]>a[i+1]){
				++i;
			}
			// if reached end safely, it is surely descending
			if(i==n-1){
				type=2;
				max=a[0];
			}
			else if(i<n){
				if(i >= n/2){
					type=4;
					max=a[i+1];
				}
				else{
					type=3;
					max=a[i+1];
				}
			}
		}
		// if reached end safely, it is surely ascending
		else if(i==n-1){
			type=1;
			max=a[n-1];
		}
		else if(i<n){
			if(i >= n/2){
				type=4;
				max=a[i];
			}
			else{
				type=3;
				max=a[i];
			}
		}
		
		cout << max << " " << type << "\n";
		

 /*
 	int i,ascen,descen,count;

		i=0;
		count=0;
		while( i+1<n ){
			if(a[i]<a[i+1]){
				count++;
			}
			i++;
		}
		ascen=count;

		i=0;
		count=0;
		while( i+1<n){
			if(a[i]>a[i+1]){
				count++;
			}
			i++;
		}
		descen=count;
		//cout<<"as"<<ascen<<"and des"<<descen;

		if(ascen==0){
			cout << a[0] << " " << "2" << "\n";
		}
		else if(descen==0){
			cout << a[n-1] << " " << "1" << "\n";
		}
		else if(descen > ascen){
			cout << a[descen-1] << " " << "3" << "\n";
		}
		else if(ascen > descen){
			cout << a[ascen-1] << " " << "4" << "\n";
		}
*/
	}
    return 0;
}

