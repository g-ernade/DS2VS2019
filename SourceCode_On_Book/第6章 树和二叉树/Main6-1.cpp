 // main6-1.cpp ����bo6-1.cpp��������������������ѡ����������Ϊchar��int
 // #define CHAR 1 // �ַ��͡���2��
 #define CHAR 0 // ����(����ѡһ)����3��
 #include"func6-1.cpp" // �����������룬����������ѡ��������ͣ����������ĺ���
 #include"c6-1.h" // ��������˳��洢�ṹ
 #include"bo6-1.cpp" // ������˳��洢�ṹ�Ļ������� 

 void main()
 {
   Status i;
   int j;
   position p;
   TElemType e;
   SqBiTree T,s;
   InitBiTree(T); // ��ʼ��������T
   CreateBiTree(T); // ����������T
   printf("���������������շ�%d(1���� 0����)���������=%d��\n",BiTreeEmpty(T),
   BiTreeDepth(T));
   i=Root(T,e); // ��������T�ĸ���ֵ����e
   if(i) // ������T�ǿ�
     printf("�������ĸ�Ϊ"form"��\n",e);
   else
     printf("���գ��޸���\n");
   printf("���������������\n");
   LevelOrderTraverse(T,visit); // �������������T
   printf("���������������\n");
   InOrderTraverse(T,visit); // �������������T
   printf("���������������\n");
   PostOrderTraverse(T,visit); // �������������T
   printf("��������޸Ľ��Ĳ�� ������ţ�");
   scanf("%d%d",&p.level,&p.order);
   e=Value(T,p); // ��������T��λ��p�Ľ���ֵ����e
   printf("���޸Ľ���ԭֵΪ"form"����������ֵ��",e);
   scanf("%*c"form"%*c",&e);
   Assign(T,p,e); // ��e��ֵ����������T��λ��p�Ľ��
   printf("���������������\n");
   PreOrderTraverse(T,visit); // �������������T
   printf("���"form"��˫��Ϊ"form"�����Һ��ӷֱ�Ϊ",e,Parent(T,e));
   printf(form"��"form"�������ֱֵܷ�Ϊ",LeftChild(T,e),RightChild(T,e));
   printf(form"��"form"��\n",LeftSibling(T,e),RightSibling(T,e));
   InitBiTree(s); // ��ʼ��������s
   printf("����������Ϊ�յ���s��\n");
   CreateBiTree(s); // ����������s
   printf("��s�嵽��T�У���������T����s��˫�׽�� sΪ��(0)����(1)������");
   scanf(form"%d",&e,&j);
   InsertChild(T,e,j,s);
   // ����s�嵽��T�У����e��Ϊ��s��˫�׽�㣬����j��ֵȷ����s��e�����������
   Print(T); // ��㡢������������������T
   printf("ɾ���������������������˫�׵Ĳ�� ������� ��Ϊ˫�׵���(0)����(1)������");
   scanf("%d%d%d",&p.level,&p.order,&j);
   DeleteChild(T,p,j); // ɾ��������T��λ��p������(j=0)����(j=1)����
   Print(T); // ��㡢������������������T
   ClearBiTree(T); // ��ն�����T
   printf("��ն����������շ�%d(1���� 0����)���������=%d��\n",BiTreeEmpty(T),
   BiTreeDepth(T));
   i=Root(T,e); // ��������T�ĸ���ֵ����e
   if(i) // ������T�ǿ�
     printf("�������ĸ�Ϊ"form"��\n",e);
   else // ������TΪ��
     printf("���գ��޸���\n");
 }
