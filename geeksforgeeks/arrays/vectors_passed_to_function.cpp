/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<iostream>
#include <vector>
using namespace std;

// This would create a COPY of the vector
// that would be local to this function's scope
void by_value(std::vector<int> arr) { cout << sizeof(arr) << '\n'; }

// This would use a reference to the vector
// this reference could be modified in the
// tester function
// This does NOT involve a second copy of the vector
void by_ref(std::vector<int>&arr) { cout << sizeof(arr) << '\n'; }

// This would use a const-reference to the vector
// this reference could NOT be modified in the
// tester function
// This does NOT involve a second copy of the vector
void by_const_ref(const std::vector<int>&arr){
    cout << "\n"<< sizeof(arr) << "\t";
    for(int i=0;i<arr.size();++i){ cout<<arr.at(i)<<" "; }
}

// This would use a pointer to the vector
// This does NOT involve a second copy of the vector
// caveat:  use of raw pointers can be dangerous and
// should be avoided for non-trivial cases if possible
// when using pointer. -> must be used.
void by_pointer(std::vector<int>*arr){
    cout << "\n" << sizeof(arr) << '\t';
    for(int i=0;i<arr->size();++i){ cout<<arr->at(i)<<" "; }
}




int main(){

	vector<int> arr({1,2,3,4,5,6,7,8,9,10});
	
	by_value(arr);
    by_ref(arr);
    by_const_ref(arr);
    by_pointer(&arr);

    return 0;
}

