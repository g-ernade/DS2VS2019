 // func5-4.cpp ��������������main5-4.cpp��main5-5.cpp����
 void main()
 {
   char p[80];
   SString t;
   GList n,m;
   InitGList(n); // ��ʼ�������n��nΪ�ձ�
   printf("�չ����n�����=%d��n�Ƿ�գ�%d(1:�� 0:��)\n",GListDepth(n),
   GListEmpty(n));
   printf("����������n(��д��ʽ���ձ�:()����ԭ��:(a)������:(a,(b),c))��\n");
   gets(p); // �����������n���ַ�������p
   StrAssign(t,p); // ��pת��ΪSString���͵�t
   CreateGList(n,t); // ����t���������n
   printf("�����n�ĳ���=%d��",GListLength(n));
   printf("���=%d��n�Ƿ�գ�%d(1:�� 0:��)\n",GListDepth(n),GListEmpty(n));
   printf("���������n��");
   Traverse_GL(n,print2); // ���������n
   CopyGList(m,n); // ���ƹ����m=n
   printf("\n���ƹ����m=n��m�ĳ���=%d��",GListLength(m));
   printf("m�����=%d\n���������m��",GListDepth(m));
   Traverse_GL(m,print2); // ���������m
   DestroyGList(m); // ���ٹ����m���ͷŴ洢�ռ�
   m=GetHead(n); // ���ɹ����n�ı�ͷԪ�أ�����mָ��
   printf("\nm��n�ı�ͷԪ�أ�����m��");
   Traverse_GL(m,print2); // ���������m
   DestroyGList(m); // ���ٹ����m���ͷŴ洢�ռ�
   m=GetTail(n); // �������n�ı�β(����ͷ֮��Ĳ���)����Ϊ���������mָ����
   printf("\nm����n�ı�β�γɵĹ�������������m��");
   Traverse_GL(m,print2); // ���������m
   InsertFirst_GL(m,n); // �������n�嵽�����m�У�����Ϊm�ĵ�1��Ԫ��(��ͷ)
   printf("\n��������nΪm�ı�ͷ�����������m��");
   Traverse_GL(m,print2); // ���������m
   DeleteFirst_GL(m,n); // ɾ�������m�ı�ͷ������nָ��ɾ���ı�ͷ
   printf("\nɾ��m�ı�ͷ������nָ��m�ı�ͷ�����������m��");
   Traverse_GL(m,print2); // ���������m
   printf("\n���������n(�����m��ԭ��ͷ)��");
   Traverse_GL(n,print2); // ���������n
   printf("\n");
   DestroyGList(m); // ���ٹ����m��n�����ͷŴ洢�ռ�
   DestroyGList(n);
 }
