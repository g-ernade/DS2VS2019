 // algo8-5.cpp ����bo8-3.cpp�ĳ���
 #include"c1.h"
 #include"func8-5.cpp" // ��������Ԫ�����͵Ķ��弰�����Ĳ���
 #include"c8-2.h" // ��������ֵ�͹ؼ��ֱȽϵ�Լ��
 typedef ElemType TElemType; // �����������Ԫ������Ϊ����Ԫ������
 #include"c8-3.h" // ƽ��������Ĵ洢�ṹ
 typedef BSTree BiTree; // �����������ָ������Ϊƽ���������ָ������
 #include"func8-4.cpp" // �����㷨9.5(a)��bo6-11.cpp
 //#define FLAG // �Ӵ˾���bo8-3.cpp��ֱ����RL��LRƽ�⴦����9��
 #include"bo8-3.cpp" // ƽ��������Ļ�������
 void main()
 {
   BSTree dt,p;
   int i,n;
   KeyType j;
   ElemType r;
   Boolean flag;
   Status k;
   FILE *f; // �ļ�ָ������
   f=fopen("f8-4.txt","r"); // �������ļ�f8-4.txt
   fscanf(f,"%d",&n); // �������ļ���������Ԫ�ظ���
   InitDSTable(dt); // ��ʼ����ƽ�������dt
   for(i=0;i<n;i++) // ������ƽ�������dt�в���n������Ԫ��
   { InputFromFile(f,r); // �������ļ���������Ԫ�ص�ֵ������r����func8-5.cpp��
     k=InsertAVL(dt,r,flag); // ��ƽ�������dt�в�������Ԫ��r��ʹ��Ϊƽ�������
     if(k) // ��������Ԫ��r�ɹ�
     { printf("����ؼ���Ϊ%d�Ľ��󣬰��ؼ���˳��(����)����ƽ�������dt\n",r.key);
       TraverseDSTable(dt,Visit); // ���ؼ���˳��(����)����������dt��ȷ��dt�Ƿ�����
       printf("\n�������ƽ�������dt\n");
       PreOrderTraverse(dt,Visit); // �������ƽ�������dt��ȷ��dt����̬
       printf("\n");
     }
     else // ��������Ԫ��rʧ��
       printf("ƽ�������dt���Ѵ��ڹؼ���Ϊ%d�����ݣ���(%d,%d)�޷����뵽dt�С�\n",
       r.key,r.key,r.others);
   }
   fclose(f); // �ر������ļ�
   printf("����������ҵĹؼ��ֵ�ֵ��");
   InputKey(j); // �ɼ�������ؼ���j����func8-5.cpp��
   p=SearchBST(dt,j); // ��ƽ�������dt�еݹ�ز��ҹؼ��ֵ���j�Ľ��
   if(p) // �ҵ���pָ��ý��
    printf("dt�д��ڹؼ���Ϊ%d�Ľ�㣬��ֵΪ(%d,%d)��\n",j,p->data.key,
    p->data.others);
   else
     printf("dt�в����ڹؼ���Ϊ%d�Ľ�㡣\n",j);
   DestroyDSTable(dt); // ����ƽ�������dt
 }
