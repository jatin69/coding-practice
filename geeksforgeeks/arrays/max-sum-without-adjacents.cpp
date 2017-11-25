/*
 * Author : Jatin Rohilla
 * Date   : 24/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Question : Given an array of positive numbers, find the maximum sum of a
 * subsequence with the constraint that no 2 numbers in the sequence should be
 * adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or
 * 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
 */
/*

Input:
1
6
5 5 10 40 50 35

Its Correct output is: (optimal)
80

My approach- (greedy approach) (benefit at current iteration)
65
*/

#include<iostream>
using namespace std;

int getmax(int a[], int l, int h, int size){

    cout<<"\ncall: l="<<l<<" and h="<<h<<"\n";
    // base condition
    if(l==h){
        cout<<"base reached\n";
        return a[l];
    }
    
    // checks
    if( l>h || l<0 || l>size-1 || h<0 || h>size-1){
        cout<<"blunder";
        return 0;
    }
    
    int max=l;
    for(int i=l+1;i<=h;++i){
        if(a[i]>a[max]){
            max=i;
        }
    }

    int pivot_max=0, left_max=0, right_max=0;

    pivot_max = a[max];
    cout<<"max index : "<<max<<" and max ele: "<<pivot_max<<"\n";
    left_max= getmax(a,l,max-2,size);
    right_max= getmax(a,max+2,h,size);

    int sum=pivot_max + left_max + right_max;
    cout<<"Finish call : returning sum="<<sum<<"\n";
    return sum;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;++i){
	        cin>>a[i];
	    }
	    int res= getmax(a,0,n-1,n);
	    cout<<res<<"\n";
	}
	return 0;
}
