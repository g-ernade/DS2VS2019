#define N 8 // 定义待转换的进制N(2～9)
#include "Utils_SqStack.h"
void conversion() // 算法3.1
{ // 对于输入的任意一个非负十进制整数，打印输出与其等值的N进制数
	SqStack s;
	unsigned n; // 非负整数
	SElemType e;
	InitStack(s); // 初始化栈
	printf("将十进制整数n转换为%d进制数，请输入：n(≥0)=", N);
	scanf("%u", &n); // 输入非负十进制整数n
	while (n) // 当n不等于0
	{
		Push(s, n % N); // 入栈n除以N的余数(N进制的低位)
		n = n / N;//n=n div N (n除完8之后取整，赋给n)
	}
	while (!StackEmpty(s)) // 当栈不空
	{
		Pop(s, e); // 弹出栈顶元素且赋值给e
		printf("%d", e); // 输出e
	}
	printf("\n");
}

void main()
{
	conversion();
}