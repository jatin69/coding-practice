#include<stdio.h>
#include <iostream>
using namespace std;
/**
Answer is (B) -- both can be used
*/

struct A{
	char* name;
	union
	{
		char* sval;
	}u;
}symtab[10];

int main(void)
{
	int i=0;
	//char* z = "hello";
	//symtab[i].u.sval=new char[2];
	*symtab[i].u.sval='z';
	printf("%c",*symtab[i].u.sval);
}
