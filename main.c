#define STACKSIZE 100
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"binary_tree.h"
static void title(void);
static void end(void);
char * GetInput(char []);
void InToPost(char []);
void ToTree(BinaryTree, char []);
double Conclusion(BinaryTree);

int main(void)
{
	char stack[STACKSIZE];
	BinaryTree tree;

	title();
	while (GetInput(stack) != NULL)
	{
		InToPost(stack);
		ToTree(tree, stack);
		printf("result: %.3lf\n", Conclusion(tree));
	}
	end();
	return 0;
}
void InToPost(char stack[])
{
	;
}
void ToTree(BinaryTree tree, char Source[])
{
	double tmp;
	BinaryTree Stack[STACKSIZE];
	BinaryTree * stack = Stack;
	char * source = Source;
	
	while (*source != '\0')
	{
		BinaryTree t;

		if (isdigit(*source))
		{
			tmp = strtod(source, NULL);
			while (isdigit(*source))
				source++;
			t = Create();
			t->element.d = tmp;
			*stack = t;
			stack++;
		}
		else
		{
			t = Union(*(stack - 2), *(stack - 1));
			t->element.ch = *source;
			stack--;
			*(stack - 1) = t;
			source++;
		}
	}
	tree->left = *stack;
	tree->element.ch = '+';
}
static double pow(double x, double y)
{
	double re = 1;

	for (int i = 0; i < (int)y; ++i)
		  re *= x;
	return re;
}
double Conclusion(BinaryTree tree)
{
	if (tree == NULL)
		return 0;
	if (tree->left == NULL && tree->right == NULL)
		return tree->element.d;
	else
	{
		double l = Conclusion(tree->left);
		double r = Conclusion(tree->right);
		
		switch (tree->element.ch)
		{
			case '+':
				return l + r;
			case '-':
				return l - r;
			case '*':
				return l * r;
			case '/':
				if (r == 0.0)
					fprintf(stderr, "Error: division 0\n");
				return l / r;
			case '^':
				return pow(l, r);
			default:
				break;
		}
	}
	return 10000;
}
char * GetInput(char array[])
{
	char ch;
	int i = 0;

	ch = getchar();
	while (ch != '\n' && ch != EOF)
	{
		array[i] = ch;
		++i;
		ch = getchar();
	}
	array[i] = '\0';
	if (ch == EOF)
		return NULL;
	else
		return array;
}
static void Starbar(void)
{
	const int Stars = 80;
	for (int i = 0; i < Stars; ++i)
		putchar('*');
	putchar('\n');
}
static void title(void)
{
	Starbar();
	printf("(EOF to quit)\n");
}
static void end(void)
{
	printf("quit\n");
	Starbar();
}
