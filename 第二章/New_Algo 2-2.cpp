 // algo2-2.cpp ��SqList���ͺ�LinkList���ͷֱ�ʵ���㷨2.1��2.2�ĳ���
 #include"Basic.h"
 typedef int ElemType; // ����ElemTypeΪ����
 #define Sq // (��SqList����ѡ���У���LinkList���ͽ�������Ϊע��)
 #ifdef Sq
   #include"Utils_SqList.h" // �������Ա�Ķ�̬����˳��洢�ṹ
   typedef SqList List; // ���������������ListΪSqList����
   #define printer print1 // ListTraverse()�õ���ͬ���͵��������
 #else
   #include"Utils_LNode.h" // �������Ա�ĵ�����洢�ṹ
   typedef LinkList List; // ���������������ListΪLinkList����
   #define printer print // ListTraverse()�õ���ͬ���͵��������
 #endif
 #include"Utils_PrivateFunc.cpp" // ����equal()��comp()��print()��print1()��print2()����
 #include"Utils_List.cpp" // �����㷨2.1��2.2

 void main()
 {
   List La,Lb,Lc;
   int j,b[7]={2,6,8,9,11,15,20};
   InitList(La); // �����ձ�La���粻�ɹ�������˳����������
   for(j=1;j<=5;j++) // �ڱ�La�в���5��Ԫ�أ�����Ϊ1��2��3��4��5
     ListInsert(La,j,j);
   printf("La= ");
   ListTraverse(La,printer); // �����La������
   InitList(Lb); // �����ձ�Lb
   for(j=1;j<=5;j++) // �ڱ�Lb�в���5��Ԫ�أ�����Ϊ2��4��6��8��10
     ListInsert(Lb,j,2*j);
   printf("Lb= ");
   ListTraverse(Lb,printer); // �����Lb������
   Union(La,Lb); // �����㷨2.1����Lb������������Ԫ�ز���La(���ı�Lb)
   printf("new La= ");
   ListTraverse(La,printer); // ����±�La������
   ClearList(Lb); // ��ձ�Lb
   for(j=1;j<=7;j++) // �ڱ�Lb���������β�������b[]��7��Ԫ��
     ListInsert(Lb,j,b[j-1]);
   printf("Lb= ");
   ListTraverse(Lb,printer); // �����Lb������
   MergeList(La,Lb,Lc); // �����㷨2.2�������±�Lc(���ı��La�ͱ�Lb)
   printf("Lc= ");
   ListTraverse(Lc,printer); // �����Lc������
 }
