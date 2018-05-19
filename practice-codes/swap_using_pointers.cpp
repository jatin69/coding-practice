/*
 * Author : Jatin Rohilla
 * Date   : 23/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Objective : Swap using pointers.
 * Analyse what happens where we use p instead of *p
 */


#include<iostream>
using namespace std;


/* Function : swap_value(int *x, int *y)
 * Approach : pointers are appointed to hold the coming addresses.
 * Using these pointers, values are replaced in actual memory locations of
 * variables. As the changes in value occur directly in variable locations,
 * changes are reflected back in the main function.
 */
void swap_value(int *x, int* y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

/* Function : swap_pointer(int *x, int *y)
 * Approach : pointers are appointed to hold the coming addresses.
 * Then we swap the contents of these two pointers.
 * As soon as the function ends, these pointers go out of scope.
 * No changes really occur in variables.
 * SO, values are not swapped, as wanted.
 */
void swap_pointer(int *x, int* y){
    int *temp;
    temp=x;
    x=y;
    y=temp;
}

int main(){

	int i=100;
	int j=200;
	
	cout<<"Original :\t i = "<<i<<" and j = "<<j<<"\n";
	
	//swap_pointer(&i, &j);
	swap_value(&i, &j);
	

    cout<<"\nUpdated  :\t i = "<<i<<" and j = "<<j<<"\n";
    return 0;
}

