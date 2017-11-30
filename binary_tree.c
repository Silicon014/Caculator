#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"
static void eprint(Elem e)
{
	fprintf(stderr, "warning: Elem type changed\n");
	printf("%.2f", e.d);
}
static int ecompare(Elem e1, Elem e2)
{
	return e1.d == e2.d;
}
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
		return 1 + ((l > r)? l: r);
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
	if (ecompare(tree->element, e))
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
