/*
 * Author : Jatin Rohilla
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

Benefit of `at` over `[]`
`at` throws exception when non existent element is accessed
`[]` shows undefined behaviour

 */


#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

// driver code
int main()
{
	// marks in different subjects
	unordered_map<string,int> my_marks = {
					{"Maths", 90},
					{"Physics", 87},
					{"Chemistry", 98},
					{"Computer Application", 94}
					};


		my_marks.at("Physics") = 97;
		my_marks.at("Maths") += 10;
		my_marks.at("Computer Application") += 6;

		for (auto& i: my_marks)
		{
			cout<<i.first<<": "<<i.second<<endl;
		}



	return 0;
}

