#include <iostream>
using namespace std;
 
int main() {
	int i=0,j=1,k=2,l=3,t;
	t= i++&&j++&&k++||l++;
	cout<<i<<j<<k<<l<<t<<"\n";
	/*
	short circuit output - 
	11241
 	*/
	return 0;
}