#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//实现栈的基本结构
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}sqstack;
//初始化栈
int initstack(sqstack* s)
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return 0;
}
//进栈
int push(sqstack* s, int e)
{
	if ((s->top - s->base) >= s->stacksize)
	{
		s->base = (int*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(int));
		if (!(s->base)) exit(1);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return 0;
}
//判断是否空
int stackempty(sqstack* s)
{
	if (s->top == s->base)
		return 1;
	else return 0;
}
//出栈
int pop(sqstack* s, int* e)
{
	if (s->top == s->base)
		return 1;
	*e = *--s->top;
	return 0;
}
//转换函数
void conversion(int n)
{
	sqstack s;
	int e;
	int IsNegative;
	IsNegative = 0;
	initstack(&s);
	printf("请输入一个十进制数：\n");
	scanf_s("%d", &n);

	if (n < 0) {
		IsNegative = 1;
		n = -n;//如果输入是负数，先转成正数进行转换，并用Isnegative记录是否为正数
	}

	while (n) {
		push(&s, n % 8);
		n = n / 8;
		//把数字mod8进去，然后在把最后一位去掉
	}
	printf("\n");
	printf("该数的八进制数为：\n");

	if (IsNegative == 1) {
		printf("-");//把负号加回去
	}

	while (!stackempty(&s)) {
		pop(&s, &e);
		printf("%d", e);
	}



	printf("\n");
	scanf_s("%d", &n);//为了防止窗口闪退
}

int main()
{
	int n;
	n = 1;
	conversion(n);
	return 0;
