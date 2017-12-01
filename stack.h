typedef union node {
	char ch;
	double d;
	} Node;
typedef Node Elem;
struct stack {
	int size;
	Node * bottom;
	Node * top;
	};
typedef struct stack * Stack;
Stack CreateStack(int);
void MakEmpty(Stack);
void Push(Stack, Elem);
Elem Pop(Stack);
Elem Top(Stack);
int IsEmpty(Stack);
void DeleteStack(Stack);
