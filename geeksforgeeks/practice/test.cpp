/*
 * Author : Jatin Rohilla
 * Date   : 19/08/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<stdio.h>

struct buffer{
	int n;
	char* name;
};

int main(){

	buffer *obj = new buffer;
	obj->n = 4;
	obj->name = "hello";
	printf("%d\n%s", obj->n, obj->name) ;
    return 0;
}


// In C

//#include<stdio.h>
//#include<stdlib.h>
//
//struct buffer{
//	int n;
//	char* name;
//};
//
//int main(){
//
//	struct buffer *obj = (struct buffer*) malloc(sizeof(struct buffer));
//	obj->n = 4;
//	obj->name = "hello";
//	printf("%d\n%s", obj->n, obj->name) ;
//    return 0;
//}

