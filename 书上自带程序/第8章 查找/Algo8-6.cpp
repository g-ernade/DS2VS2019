 // algo8-6.cpp ����bo8-4.cpp�ĳ���
 #include"c1.h"
 #define m 3 // B_���Ľף�����Ϊ3
 int s=(m+1)/2; // sΪ���ѽ�����ֵ
 typedef int KeyType; // ��ؼ�����Ϊ����
 struct Others // ��¼����������
 { int order; // ���ͱ�����˳��
 };
 #include"c8-2.h" // ��������ֵ�͹ؼ��ֱȽϵ�Լ��
 #define N 12 // ��¼���������Ԫ�ظ���
 #include"c8-4.h" // ��¼����
 #include"c8-5.h" // B_���Ľ������
 #include"c8-6.h" // B_���Ĳ��ҽ������
 #include"bo8-4.cpp" // B_���Ļ��������������㷨9.13��9.14
 #include"func8-6.cpp" // ������B_���������������

 void main()
 {
   Record r[N]={{24,1},{45,2},{53,3},{12,4},{37,5},{50,6},{61,7},{90,8},
   {100,9},{70,10},{3,11},{37,12}}; // (��¼Ԫ�ش��������У��Խ̿�����ͼ9.16(a)Ϊ��)
   BTree t;
   Result u;
   KeyType j;
   int i;
   InitDSTable(t); // ����յ�B_��t
   for(i=0;i<N;i++) // ����¼����r[N]���������β�����t��
   { u=SearchBTree(t,r[i].key); // ����t�в����Ƿ��Ѵ��ڹؼ���Ϊr[i].key�ļ�¼
     if(u.tag) // ����t���Ѵ��ڹؼ���Ϊr[i].key�ļ�¼
       printf("��t���Ѵ��ڹؼ���Ϊ%d�ļ�¼����(%d,%d)�޷����롣\n",r[i].key,
       r[i].key,r[i].others.order);
     else // ����t�в����ڹؼ���Ϊr[i].key�ļ�¼
       InsertBTree(t,&r[i],u.pt,u.i);
       // ��r[i]�Ĺؼ��ֺ͵�ַ���뵽t�н��u.pt��[u.i]��[u.i+1]֮��
   }
   printf("���ؼ��ֵ�˳�����B_��t��\n");
   TraverseDSTable(t,Visit); // ���ؼ��ֵ�˳�����B_��t
   for(i=1;i<=4;i++) // 4������t�в��Ҹ����ؼ��ֵ�����
   { printf("\n����������Ҽ�¼�Ĺؼ��֣�");
     InputKey(j); // ����ؼ���j
     u=SearchBTree(t,j); // ����t�в��ҹؼ���Ϊj������
     if(u.tag) // �ҵ�
       Visit(*(u.pt),u.i); // ������ҵ��ļ�¼
     else // δ�ҵ�
       printf("δ�ҵ�");
   }
   printf("\n");
   DestroyDSTable(t); // ������t
 }
