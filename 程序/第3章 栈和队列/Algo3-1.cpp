 // algo3-1.cpp �����㷨3.1�ĳ���
 #define N 8 // �����ת���Ľ���N(2��9)
 typedef int SElemType; // ����ջԪ������Ϊ����
 #include"c1.h"
 #include"c3-1.h" // ����˳��ջ
 #include"bo3-1.cpp" // ����˳��ջ�Ļ�������

 void conversion() // �㷨3.1
 { // �������������һ���Ǹ�ʮ������������ӡ��������ֵ��N������
   SqStack s;
   unsigned n; // �Ǹ�����
   SElemType e;
   InitStack(s); // ��ʼ��ջ
   printf("��ʮ��������nת��Ϊ%d�������������룺n(��0)=",N);
   scanf("%u",&n); // ����Ǹ�ʮ��������n
   while(n) // ��n������0
   { Push(s,n%N); // ��ջn����N������(N���Ƶĵ�λ)
     n=n/N;
   }
   while(!StackEmpty(s)) // ��ջ����
   { Pop(s,e); // ����ջ��Ԫ���Ҹ�ֵ��e
     printf("%d",e); // ���e
   }
   printf("\n");
 }

 void main()
 {
   conversion();
 }
