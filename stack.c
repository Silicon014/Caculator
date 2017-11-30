#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
Stack CreateStack(int i)
{
	Stack s;

	s = (Stack)malloc(sizeof(struct stack));
	s->size = i;
	return s;
}
void MakeEmpty(Stack s)
{
	s->bottom = (Node *)malloc(sizeof(Node * s->size));
	s->top = s->bottom;
}
void Push(Stack s, Elem e)
{
	++(s->top);
	*(s->top) = e;
}
Elem Pop(Stack s)
{
	if (IsEmpty(s))
		;
	else
	{
		Elem e = *(s->top);
		
		

