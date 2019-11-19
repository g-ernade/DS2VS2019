#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//ʵ��ջ�Ļ����ṹ
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}sqstack;
//��ʼ��ջ
int initstack(sqstack* s)
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return 0;
}
//��ջ
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
//�ж��Ƿ��
int stackempty(sqstack* s)
{
	if (s->top == s->base)
		return 1;
	else return 0;
}
//��ջ
int pop(sqstack* s, int* e)
{
	if (s->top == s->base)
		return 1;
	*e = *--s->top;
	return 0;
}
//ת������
void conversion(int n)
{
	sqstack s;
	int e;
	int IsNegative;
	IsNegative = 0;
	initstack(&s);
	printf("������һ��ʮ��������\n");
	scanf_s("%d", &n);

	if (n < 0) {
		IsNegative = 1;
		n = -n;//��������Ǹ�������ת����������ת��������Isnegative��¼�Ƿ�Ϊ����
	}

	while (n) {
		push(&s, n % 8);
		n = n / 8;
		//������mod8��ȥ��Ȼ���ڰ����һλȥ��
	}
	printf("\n");
	printf("�����İ˽�����Ϊ��\n");

	if (IsNegative == 1) {
		printf("-");//�Ѹ��żӻ�ȥ
	}

	while (!stackempty(&s)) {
		pop(&s, &e);
		printf("%d", e);
	}



	printf("\n");
	scanf_s("%d", &n);//Ϊ�˷�ֹ��������
}

int main()
{
	int n;
	n = 1;
	conversion(n);
	return 0;
