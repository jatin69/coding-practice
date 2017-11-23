/*
 * Author : Jatin Rohilla
 * Date   : 23/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 *
 * Objective : cs50 pset mario - A right triangle of stars
 */


#include<iostream>
using namespace std;

int main(){

	int height=10;
	
	for(int i=1;i<=height;++i){
	    for(int j=1;j<=height-i;++j){
             cout<<" ";
        }
        for(int j=1;j<=i;++j){
                cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}

