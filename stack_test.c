#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"

int main(void)
{
	Stack test;

	test = CreateStack(100);
	MakeEmpty(test);
	
	Elem element = (Elem)malloc(sizeof(Node));

	element->d = 1.0;
	Push (test, element);
	printf("%lf -> %lf\n", element->d, Top(test)->d);
	Pop(test);
	assert(IsEmpty(test));
	DeleteStack(test);
	free(element);
	return 0;
}
