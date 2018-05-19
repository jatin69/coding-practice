#include <iostream>
using namespace std;

int main() {
	char *a = "abcd";
	char str[] = "abcde";
	cout<< sizeof(a) << sizeof(str) << sizeof("abcde");
	int aa=5;
	int *b=&aa;
	cout<<"\n"<<sizeof(aa)<<sizeof(b);
	return 0;
}