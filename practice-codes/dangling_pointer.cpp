/*
 * Author : Jatin Rohilla
 * Date   : 23/11/2017 - 9/12/17
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Objective : Understanding dangling pointer
 * ref- gfg and stackoverflow
 */

/*
Memory leak: When there is a memory area in a heap but no variable in the stack pointing
to that memory.
Dangling pointer: When a pointer variable in a stack but no memory in heap.
for ref - memory map in C - http://www.geeksforgeeks.org/?p=14268
*/

#include <iostream>
using namespace std;

int* call();

int main() {
	cout << " ****** Pointer to integer Case ******** \n\n";
	cout << "Creating a normal pointer *p without initialisation.";
	int* p;
	cout << "\ncontent of p : " << p;
	cout << "\n\nwhen we try to access this random content. we get error.";
	cout << "\nThis is also a kind of dangling pointer";
	// cout<< *p;

	cout << "\n\nTo prevent this, always initialise pointer with NULL";
	p = NULL;
	cout << "\nAfter NULL assignment : " << p << "\n";


	cout << "\n ****** Pointer to integer array Case ******** \n\n";

	int n = 3;
	int* a = new int[n];

	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}

	cout << "original : ";
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";


	cout << "\nPointer content is : " << a;
	cout << "\nAccess array using pointer : ";
	cout << *a << " " << *(a + 1) << *(a + 2) << "\n";


	cout << "\nDeleting pointer .. \n";
	delete a;

	cout << "\nPointer content is : " << a;
	cout << "\nAccess array using pointer : ";
	cout << *a << " " << *(a + 1) << *(a + 2) << "\n";
	cout << "\na is now a dangling pointer. ";
	cout << "\nThe memory originally pointer by a is now de-allocated.";

	cout << "\nTo remove this dangling state. Point it to null after deletion. \n";
	a = NULL;

	cout << "\nPointer address is : " << a;
	cout << "\nAccess array using pointer : Not possible. Program will crash.\n";
	// cout<< *a << " " << *(a+1) << *(a+2) << "\n";


	cout << "\n *** Most common use case is in functions returning address of variable";

	cout << "\nCause : The address of temp var returned from function no longer exists "
			"outside of function\n";

	int* ptr;
	cout << "\nFunction called and received garbage.";
	ptr = call();
	cout << "\nExtracting it will cause segmentation fault."
		// cout<<*ptr;

		return 0;
}


int* call() {
	// x is local here
	int x = 25;
	x++;

	// address of local returned
	return &x;

	// but as soon as the function ends. This memory is de allocated.
	// so the returned pointer points to a unallocated space. Thus dangling.
}
