 // algo8-7.cpp ����bo8-5.cpp�ĳ���
 #include"c1.h"
 #define N 20 // ��������ɵ�����Ԫ�ظ���
 struct Others // ��¼����������
 { int order; // ���ͱ�����˳��
 };
 #define Nil '$' // ���������Ϊ$
 #include"c8-7.h" // ������¼�Ĵ洢�ṹ
 #include"c8-4.h" // ��¼����
 #include"c8-8.h" // ˫�������Ĵ洢�ṹ
 #include"bo8-5.cpp" // ˫�������Ļ�������
 #include"func8-7.cpp" // �����Լ����������������

 void main()
 {
   DLTree t;
   int i,j=0; // ���ݸ�������ʼΪ0
   KeyType k;
   Record *p,r[N]; // ��¼����
   FILE *f; // �ļ�ָ������
   InitDSTable(t); // ����յ�˫������t
   f=fopen("f8-5.txt","r"); // �������ļ�f8-5.txt
   do // �������ļ��еļ�¼���ζ���r��������t
   { i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order); // ���ļ��������ݸ�r[j]
     if(i!=-1) // �������ݳɹ�
     { r[j].key.num=strlen(r[j].key.ch); // ��r[j].key.num��ֵ
       p=SearchDLTree(t,r[j].key); // ��˫������t�в��ҹؼ��ִ�����r[j].key�ļ�¼
       if(!p) // t�в����ڹؼ���Ϊr[j].key����
       { InsertDSTable(t,&r[j]); // ��r[j]�ĵ�ַ���ؼ��ִ�����t��
         j++; // ��¼��������ݸ���+1
       }
       else // ����t���Ѵ��ڹؼ���Ϊr[j].key����
         printf("��t���Ѵ��ڹؼ���Ϊ%s�ļ�¼����(%s,%d)�޷����롣\n",
         r[j].key.ch,r[j].key.ch,r[j].others.order);
     }
   }while(!feof(f)&&j<N); // δ�������ļ��Ľ�β�Ҽ�¼����δ��
   fclose(f); // �ر������ļ�
   printf("���ؼ��ַ�����˳�������t��\n");
   TraverseDSTable(t,Visit); // ����˫������t
   printf("\n����������Ҽ�¼�Ĺؼ��ַ�����");
   InputKey(k.ch); // ��������Ҽ�¼�Ĺؼ��ַ�����k.ch
   k.num=strlen(k.ch); // ��ùؼ��ַ����ĳ��ȸ���k.num
   p=SearchDLTree(t,k); // ��˫������t�в��ҹؼ��ִ�����k�ļ�¼
   if(p) // ���ڸü�¼
     Visit(p); // ����ü�¼
   else // �����ڸü�¼
     printf("δ�ҵ�"); // ���δ�ҵ���Ϣ
   printf("\n");
   DestroyDSTable(t); // ����˫������t
 }
