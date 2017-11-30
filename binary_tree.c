#include<stdio.h>
#include<stdlib.h>
typedef union {
	char ch;
	int d;
	double f
	} Elem;
static void eprint(Elem e)
{
	fprintf(stderr, "warning: Elem type changed\n");
	printf("%d", e);
}
struct root {
	Elem element;
	struct root * left;
	struct root * right;
	};
#include"binary_tree.h"

BinaryTree Create(void)
{
	BinaryTree tree;

	tree = (BinaryTree) malloc(sizeof(Root));
	return tree;
}
BinaryTree Delete(BinaryTree tree)
{
	if (tree->left == NULL)
		Delete(tree->left);
	if (tree->right == NULL)
		Delete(tree->right);
	free(tree);
	return NULL;
}
void AddLeft(BinaryTree tree, Elem e)
{
	if (tree->left != NULL)
		fprintf(stderr, "the leftside node is not empty\n");
	else
	{
		tree->left = (BinaryTree)malloc(sizeof(Root));
		tree->left->element = e;
	}
}
void AddRight(BinaryTree tree, Elem e)
{
	if (tree->right!= NULL)
		fprintf(stderr, "the rightside node is not empty\n");
	else
	{
		tree->right= (BinaryTree)malloc(sizeof(Root));
		tree->right->element = e;
	}
}
static int deep(BinaryTree);
int Depth(BinaryTree tree)
{
	return deep(tree);
}
inline int deep(BinaryTree tree)
{
	if (tree == NULL)
		return 0;
	else
	{
		int l = deep(tree->left);
		int r = deep(tree->right);
		return 1 + (l > r)? l: r;
	}
}
int Count(BinaryTree tree)
{
	if (tree == NULL)
		return 0;
	else
		return 1 + Count(tree->left) + Count(tree->right);
}
static void print(BinaryTree, int);
void Print(BinaryTree tree)
{
	print(tree, 0);
}
static void print(BinaryTree tree, int FromTop)
{
	for (int i = 0; i < FromTop; ++i)
		putchar('\t');
	eprint(tree->element);
	putchar('\n');
	if (tree->left != NULL)
		print(tree->left, FromTop + 1);
	if (tree->right != NULL)
		print(tree->right, FromTop + 1);
}
BinaryTree Find(BinaryTree tree, Elem e)
{
	if (tree == NULL)
		return NULL;
	if (tree->element == e)
		return tree;
	else
	{
		BinaryTree re;

		if ((re = Find(tree->left, e)) != NULL)
			return re;
		else
			if ((re = Find(tree->right, e)) != NULL)
				return re;
			else
				return NULL;
	}
}
BinaryTree Union(BinaryTree t1, BinaryTree t2)
{
	BinaryTree tree;

	tree = Create();
	tree->left = t1;
	tree->right = t2;
	return tree;
}
