#define STACKSIZE 100
#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"
static void title(void);
static void end(void);
char * GetInput(char []);
void ToTree(BinaryTree, char []);

int main(void)
{
	char stack[STACKSIZE];
	BinaryTree tree;

	title();
	while (GetInput(stack) != NULL)
	{
		ToTree(tree, stack);
		printf("result: %.3lf\n", Conclusion(tree));
	}
	end();
	return 0;
}
char * GetInput(char []);
static void Starbar(void)
{
	const int Stars = 80;
	for (int i = 0; i < Stars, ++i)
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
