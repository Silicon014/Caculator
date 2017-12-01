typedef union node {
	char ch;
	double d;
	} Node;
typedef Node * Elem;
struct stack {
	int size;
	Elem bottom;
	Elem top;
	};
typedef struct stack * Stack;
Stack CreateStack(int);
void MakeEmpty(Stack);
void Push(Stack, Elem);
Elem Pop(Stack);
Elem Top(Stack);
int IsEmpty(Stack);
void DeleteStack(Stack);
