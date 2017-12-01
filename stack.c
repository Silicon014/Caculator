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
	{
		Elem e;
		e.d = 0;
		return e;
	}
	else
	{
		Elem e = *(s->top);
		--(s->top);
		return e;
	}
}
Elem Top(Stack s)
{
	if (IsEmpty(s))
	{
		Elem e;
		e.d = 0;
		return e;
	}
	else
	{
		return *(s->top);
	}
}
int IsEmpty(Stack s)
{
	return s->bottom == s->top;
}
void DeleteStack(Stack s)
{
	free(s->bottom);
	free(s);
}
