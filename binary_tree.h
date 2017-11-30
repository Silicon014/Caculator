typedef union elem {
	char ch;
	double d;
	} Elem;
struct root {
	Elem element;
	struct root * left;
	struct root * right;
	};
typedef struct root Root;
typedef Root * BinaryTree;
BinaryTree Create(void);	//创建一个空二叉树
BinaryTree Delete(BinaryTree);	//删除一个二叉树
void AddLeft(BinaryTree, Elem);	//添加一个左节点
void AddRight(BinaryTree, Elem);	//添加一个右节点
int Depth(BinaryTree);		//计算树的深度
int Count(BinaryTree);		//计算节点的个数
void Print(BinaryTree);		//打印二叉树的所有节点
BinaryTree Find(BinaryTree, Elem);	//查找
BinaryTree Union(BinaryTree, BinaryTree);//拼接
