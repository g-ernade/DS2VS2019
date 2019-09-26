
#define ElemType SElemType 
typedef int SElemType;
#include "Utils_PrivateFunc.h"
#include"Utils_SqStack.h"
void main()
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s); // 初始化栈s
	for (j = 1; j <= 12; j++)
		Push(s, j); // 将值为j的栈元素入栈s中
	printf("栈中元素依次为");
	StackTraverse(s, print); // 从栈底到栈顶依次对栈s中每个元素调用print()函数
	Pop(s, e); // 弹出栈顶元素，其值赋给e
	printf("弹出的栈顶元素e=%d\n", e);
	printf("栈空否？%d(1:空 0:否)，", StackEmpty(s));
	GetTop(s, e); // 将新的栈顶元素赋给e
	printf("栈顶元素e=%d，栈的长度为%d\n", e, StackLength(s));
	ClearStack(s); // 清空栈s
	printf("清空栈后，栈空否？%d(1:空 0:否)\n", StackEmpty(s));
	DestroyStack(s); // 销毁栈s
	printf("销毁栈后，s.top=%u，s.base=%u，s.stacksize=%d\n", s.top, s.base, s.stacksize);
}