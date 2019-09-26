
#define ElemType SElemType 
typedef int SElemType;
#include "Utils_PrivateFunc.h"
#include"Utils_SqStack.h"
void main()
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s); // ��ʼ��ջs
	for (j = 1; j <= 12; j++)
		Push(s, j); // ��ֵΪj��ջԪ����ջs��
	printf("ջ��Ԫ������Ϊ");
	StackTraverse(s, print); // ��ջ�׵�ջ�����ζ�ջs��ÿ��Ԫ�ص���print()����
	Pop(s, e); // ����ջ��Ԫ�أ���ֵ����e
	printf("������ջ��Ԫ��e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)��", StackEmpty(s));
	GetTop(s, e); // ���µ�ջ��Ԫ�ظ���e
	printf("ջ��Ԫ��e=%d��ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(s); // ���ջs
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	DestroyStack(s); // ����ջs
	printf("����ջ��s.top=%u��s.base=%u��s.stacksize=%d\n", s.top, s.base, s.stacksize);
}