 // main6-4.cpp ����bo6-5.cpp��bo6-6.cpp�ĳ���
 #define CHAR 1 // ֻ�����ַ���
 #include"func6-1.cpp" // �����������룬����������ѡ��������ͣ����������ĺ���
 #include"c6-4.h" // ���Ķ�������(����-�ֵ�)�洢�ṹ
 #include"bo6-5.cpp" // ���Ķ�������(����-�ֵ�)��������
 #include"bo6-6.cpp" // ����PreOrderTraverse()
 void main()
 {
   int i;
   CSTree T,p,q;
   TElemType e,e1;
   InitTree(T); // �������T
   printf("������������շ�%d(1���� 0����)������Ϊ%c���������Ϊ%d��\n",
   TreeEmpty(T),Root(T),TreeDepth(T));
   CreateTree(T); // ����������T
   printf("������T�����շ�%d(1���� 0����)������Ϊ%c���������Ϊ%d��\n",
   TreeEmpty(T),Root(T),TreeDepth(T));
   printf("���������T��\n");
   LevelOrderTraverse(T,visit); // ���������T
   printf("��������޸ĵĽ���ֵ ��ֵ��");
   scanf("%c%*c%c%*c",&e,&e1);
   Assign(T,e,e1); // ����T�н��ֵΪe���޸�Ϊe1
   printf("��������޸ĺ����T��\n");
   LevelOrderTraverse(T,visit); // ���������T
   printf("%c��˫����%c��������%c����һ���ֵ���%c��\n",e1,Parent(T,e1),
   LeftChild(T,e1),RightSibling(T,e1));
   printf("������p��\n");
   CreateTree(p); // ����������p
   printf("���������p��\n");
   LevelOrderTraverse(p,visit); // ���������p
   printf("����p�嵽��T�У�������T��p��˫�׽�� ������ţ�");
   scanf("%c%d%*c",&e,&i);
   q=Point(T,e); // ��ָ����T�н��e��ָ�븳��q
   InsertChild(T,q,i,p); // ����p������T����Ϊq��ָ���ĵ�i������
   printf("��������޸ĺ����T��\n");
   LevelOrderTraverse(T,visit); // ���������T
   printf("�ȸ�������T��\n");
   PreOrderTraverse(T,visit); // �ȸ�������T
   printf("\n���������T��\n");
   PostOrderTraverse(T,visit); // ���������T
   printf("\nɾ����T�н��e�ĵ�i��������������e i��");
   scanf("%c%d",&e,&i);
   q=Point(T,e); // ��ָ����T�н��e��ָ�븳��q
   DeleteChild(T,q,i); // ɾ����T��q��ָ���ĵ�i������
   printf("��������޸ĺ����T��\n");
   LevelOrderTraverse(T,visit); // ���������T
   DestroyTree(T); // ������T
 }
