/*
 * Author : Jatin Rohilla
 * Date   : 25/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Objective : Given a sorted array with possibly duplicate elements,
 * the task is to find indexes of first and last occurrences
 * of an element x in the given array.
 *
 * Test case :
    1
    9
    1 3 5 5 5 5 67 123 125
    5
 *
 */
 
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;++i){
	        cin>>arr[i];
	    }
	    int x;
	    cin>>x;
        int low=0;
        int high=n-1;
        int middle;
        int first;
        bool found=false;
	    // binary search to find 1st occurence of element
	    while(low<=high){
	        middle=(low+high)/2;
            if(arr[middle]==x){
	            first=middle;
	            found=true;
	            break;
            }
            else if(x < arr[middle]){
                high=middle-1;
            }
            else if(arr[middle]<x){
                low=middle+1;
            }
	    }
        if(found){
            while(arr[first]==arr[first-1]){
	        first--;
            }

    	    int last=first;
    	    while(arr[last]==arr[last+1]){
                last++;
            }
            cout<<first<<" "<<last<<"\n";
        }
        else{
            cout<<"-1\n";
        }
	    
	}
	return 0;
}
