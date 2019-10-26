
#include "Utils_SqStack.h"

void conversion()
{ // �������������һ���Ǹ�ʮ������������ӡ��������ֵ��ʮ��������
	SqStack s;
	unsigned n; // �Ǹ�����
	SElemType e;
	InitStack(s); // ��ʼ��ջ
	printf("��ʮ��������nת��Ϊʮ���������������룺n(��0)=");
	scanf("%u", &n); // ����Ǹ�ʮ��������n
	while (n) // ��n������0
	{
		Push(s, n % 16); // ��ջn����16������(ʮ�����Ƶĵ�λ)
		n = n / 16;
	}
	while (!StackEmpty(s)) // ��ջ����
	{
		Pop(s, e); // ����ջ��Ԫ���Ҹ�ֵ��e
		if (e <= 9)
			printf("%d", e); // С�ڵ���9��������ֱ�����
		else
			printf("%c", e + 55); // ����9�������������Ӧ���ַ�
	}
	printf("\n");
}

void main()
{
	conversion();
}