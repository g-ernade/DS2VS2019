 // main3-1.cpp ����bo3-1.cpp��������
 #include"c1.h"
 typedef int SElemType; // ����ջԪ�����ͣ��˾�Ҫ��c3-1.h��ǰ��
 #include"c3-1.h" // ջ��˳��洢�ṹ
 #include"bo3-1.cpp" // ˳��ջ�洢�ṹ�Ļ�������(9��)
 #define ElemType SElemType // ��func2-2.cpp�е�ElemType���Ͷ���ΪSElemType����
 #include"func2-2.cpp" // ����equal()��comp()��print()��print1()��print2()����

 void main()
 {
   int j;
   SqStack s;
   SElemType e;
   InitStack(s); // ��ʼ��ջs
   for(j=1;j<=12;j++)
     Push(s,j); // ��ֵΪj��ջԪ����ջs��
   printf("ջ��Ԫ������Ϊ");
   StackTraverse(s,print); // ��ջ�׵�ջ�����ζ�ջs��ÿ��Ԫ�ص���print()����
   Pop(s,e); // ����ջ��Ԫ�أ���ֵ����e
   printf("������ջ��Ԫ��e=%d\n",e);
   printf("ջ�շ�%d(1:�� 0:��)��",StackEmpty(s));
   GetTop(s,e); // ���µ�ջ��Ԫ�ظ���e
   printf("ջ��Ԫ��e=%d��ջ�ĳ���Ϊ%d\n",e,StackLength(s));
   ClearStack(s); // ���ջs
   printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
   DestroyStack(s); // ����ջs
   printf("����ջ��s.top=%u��s.base=%u��s.stacksize=%d\n",s.top,s.base,s.stacksize);
 }
