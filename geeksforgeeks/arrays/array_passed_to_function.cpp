/*
 * Author : Jatin Rohilla
 * Date   : 25/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Analysing how arrays are passed around to functions
 *
 * Array decay : Once you convert an array into a pointer
 * (which works without casting, and therefore can happen unexpectedly in some cases)
 * you lose the ability of the sizeof operator to count elements in the array.
 * This lost ability is referred to as "decay".
 *
 */


#include<iostream>
using namespace std;


/* Arrays are always passed around as pointers due to Array Decay*/
void foo1(int *arr) { cout << sizeof(arr) << '\n'; }
void foo2(int arr[]) { cout << sizeof(arr) << '\n'; }
void foo3(int arr[10]) { cout << sizeof(arr) << '\n'; }

void foo4(int (&arr)[10]) { cout << sizeof(arr) << '\n'; }
/* Special case - original array size displayed.
A reference can be bound only to a expression of the exact same type.
For this reason the array doesn't decay,
because a reference to an array can't be bound to a pointer,
it can only be bound to an array of the same type (in this case array of 10 integers)
*/


/* Follows same rules as above */
void by_value(const int arr[]){ cout << sizeof(arr) << '\n'; }
void by_value_also(const int* arr){ cout << sizeof(arr) << '\n'; }

// as pointer here, address should be coming, so calling is a bit different.
void by_pointer(const int (*arr)[10]){ cout << sizeof(arr) << '\n'; }

// references are special. Same name, so array can't decay to pointer.
void by_reference(const int (&arr)[10]){ cout << sizeof(arr) << '\n'; }

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo1(arr);
    foo2(arr);
    foo3(arr);
    foo4(arr);
    cout<<"\n\n";
    
    by_value(arr);
    by_value_also(arr);
    by_pointer(&arr);
    by_reference(arr);
    
    return 0;
}
