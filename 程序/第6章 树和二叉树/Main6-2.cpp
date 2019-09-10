 // main6-2.cpp ��������������������������
 #define CHAR 1 // �ַ��͡���2��
 //#define CHAR 0 // ����(����ѡһ)����3��
 #include"func6-1.cpp" // �����������룬����������ѡ��������ͣ����������ĺ���
 #include"c6-2.h" // �������Ķ�������洢�ṹ
 #include"bo6-2.cpp" // �������Ķ�������洢�ṹ��4������������func8-4.cpp�ȵ���
 #include"bo6-3.cpp" // �������Ķ�������洢�ṹ��18����������

 void main()
 {
   int i;
   BiTree T,p,c;
   TElemType e1,e2;
   InitBiTree(T); // ��ʼ��������T
   printf("����ն����������շ�%d(1���� 0����)���������=%d��\n",BiTreeEmpty(T),
   BiTreeDepth(T));
   e1=Root(T); // e1Ϊ������T�ĸ�����ֵ
   if(e1!=Nil)
     printf("�������ĸ�Ϊ"form"��\n",e1);
   else
     printf("���գ��޸���\n");
 #if CHAR // CHARֵΪ���㣬�������Ϊ�ַ�
   printf("�밴�������������(�磺ab�����ո��ʾaΪ����㣬bΪ�������Ķ�����)��\n");
 #else // CHARֵΪ�㣬�������Ϊ����
   printf("�밴�������������(�磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ�����)��\n");
 #endif
   CreateBiTree(T); // ����������T
   printf("���������������շ�%d(1���� 0����)���������=%d��\n",BiTreeEmpty(T),
   BiTreeDepth(T));
   e1=Root(T); // e1Ϊ������T�ĸ�����ֵ
   if(e1!=Nil)
     printf("�������ĸ�Ϊ"form"��\n",e1);
   else
     printf("���գ��޸���\n");
   printf("����ݹ������������\n");
   InOrderTraverse(T,visit); // ����ݹ����������T
   printf("\n����ݹ������������\n");
   PostOrderTraverse(T,visit); // ����ݹ����������T
   printf("\n������һ������ֵ��");
   scanf("%*c"form,&e1);
   p=Point(T,e1); // pָ��Ϊe1��ָ��
   printf("����ֵΪ"form"��\n",Value(p));
   printf("���ı�˽���ֵ����������ֵ��");
   scanf("%*c"form"%*c",&e2); // ��һ��%*c�Ե��س�����Ϊ����CreateBiTree()��׼��
   Assign(p,e2); // ��e2��ֵ����p��ָ��㣬����e1
   printf("���������������\n");
   LevelOrderTraverse(T,visit); // ����ݹ����������T
   e1=Parent(T,e2); // ��������T�н��e2��˫�׵�ֵ����e1
   if(e1!=Nil)
     printf(form"��˫����"form"��",e2,e1);
   else
     printf(form"û��˫�ף�",e2);
   e1=LeftChild(T,e2); // ��������T�н��e2�����ӵ�ֵ����e1
   if(e1!=Nil)
     printf("������"form"��",e1);
   else
     printf("û�����ӣ�");
   e1=RightChild(T,e2); // ��������T�н��e2���Һ��ӵ�ֵ����e1
   if(e1!=Nil)
     printf("�Һ�����"form"��",e1);
   else
     printf("û���Һ��ӣ�");
   e1=LeftSibling(T,e2); // ��������T�н��e2�����ֵܵ�ֵ����e1
   if(e1!=Nil)
     printf("���ֵ���"form"��",e1);
   else
     printf("û�����ֵܣ�");
   e1=RightSibling(T,e2); // ��������T�н��e2�����ֵܵ�ֵ����e1
   if(e1!=Nil)
     printf("���ֵ���"form"��\n",e1);
   else
     printf("û�����ֵܡ�\n");
   InitBiTree(c); // ��ʼ��������c
   printf("�빹��һ��������Ϊ�յĶ�����c��\n");
 #if CHAR // CHARֵΪ���㣬�������Ϊ�ַ�
   printf("�밴�������������(�磺ab�����ո��ʾaΪ����㣬bΪ�������Ķ�����)��\n");
 #else // CHARֵΪ�㣬�������Ϊ����
   printf("�밴�������������(�磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ�����)��\n");
 #endif
   CreateBiTree(c); // ����������c
   printf("����ݹ����������c��\n");
   InOrderTraverse(c,visit); // ����ݹ����������c
   printf("\n��c�嵽��T�У���������T����c��˫�׽�� cΪ��(0)����(1)������");
   scanf("%*c"form"%d",&e1,&i);
   p=Point(T,e1); // pָ�������T�н���Ϊ������c��˫�׽���e1
   InsertChild(p,i,c); // ����c���뵽������T����Ϊ���e1(p��ָ)����(i=0)����(i=1)����
   printf("����ݹ������������\n");
   PreOrderTraverse(T,visit); // ����ݹ����������T
   printf("\nɾ���������������ɾ��������˫�׽�� ��(0)����(1)������");
   scanf("%*c"form"%d",&e1,&i);
   p=Point(T,e1); // pָ�������T�д�ɾ��������˫�׽��e1
   DeleteChild(p,i); // ɾ��p��ָ���(e1)����(i=0)����(i=1)����
   printf("����ݹ������������\n");
   PreOrderTraverse(T,visit); // ����ݹ����������T
   printf("\n����ǵݹ������������\n");
   InOrderTraverse1(T,visit); // ����ǵݹ����������T
   printf("����ǵݹ����������(��һ�ַ���)��\n");
   InOrderTraverse2(T,visit); // ����ǵݹ����������T(��һ�ַ���)
   DestroyBiTree(T); // ���ٶ�����T
 }
