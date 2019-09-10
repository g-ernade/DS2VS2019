 // algo8-8.cpp ����bo8-6.cpp�ĳ���
 #include"c1.h"
 #define N 20 // ��������ɵ�����Ԫ�ظ���
 #define LENGTH 27 // ��������(0+��дӢ����ĸ)
 struct Others // ��¼����������
 { int order; // ���ͱ�����˳��
 };
 #define Nil 0 // ���崮������Ϊ0
 static int count=0; // ����TraverseDSTable()�Ĵ�������ʼΪ0
 #include"c8-7.h" // ������¼�Ĵ洢�ṹ
 #include"c8-4.h" // ��¼����
 #include"c8-9.h" // Trie�����Ĵ洢�ṹ
 #include"c8-10.h" // �������ַ����͹ؼ��ֵıȽ�Լ��

 int ord(char c)
 { if(c==Nil)
     return 0; // ���ַ�������������0
   else
     return toupper(c)-'A'+1; // Ӣ����ĸ����������ĸ���е����(�˴����ִ�Сд)
 }

 #include"bo8-6.cpp" // Trie���Ļ��������������㷨9.16
 #include"func8-7.cpp" // �����Լ����������������

 void main()
 {
   TrieTree t;
   int i,j=0; // ���ݸ�������ʼΪ0
   KeyType k;
   Record *p,r[N]; // ��¼����
   FILE *f; // �ļ�ָ������
   InitDSTable(t); // ����յ�Trie��t
   f=fopen("f8-5.txt","r"); // �������ļ�f8-5.txt
   do // �������ļ��еļ�¼���ζ���r������Trie��t��
   { i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order); // ���ļ��������ݸ�r[j]
     if(i!=-1) // �������ݳɹ�
     { r[j].key.num=strlen(r[j].key.ch); // ��r[j].key.num��ֵ
       p=SearchTrie(t,r[j].key); // ��Trie��t�в��ҹؼ��ִ�����r[j].key�ļ�¼
       if(!p) // t�в����ڹؼ���Ϊr[j].key����
         InsertTrie(t,&r[j++]);
         // ��r[j]�ĵ�ַ���ؼ��ִ�����Trie��t�У���¼��������ݸ���+1
       else // ����t���Ѵ��ڹؼ���Ϊr[j].key����
         printf("��t���Ѵ��ڹؼ���Ϊ%s�ļ�¼����(%s,%d)�޷����롣\n",
         r[j].key.ch,r[j].key.ch,r[j].others.order);
     }
   }while(!feof(f)&&j<N); // δ�������ļ��Ľ�β�Ҽ�¼����δ��
   fclose(f); // �ر������ļ�
   printf("���ؼ��ַ�����˳�������t��\n");
   TraverseDSTable(t,Visit); // ���ؼ��ַ�����˳�����Trie��t
   printf("\n����������Ҽ�¼�Ĺؼ��ַ�����");
   InputKey(k.ch); // ��������Ҽ�¼�Ĺؼ��ַ�����k.ch
   k.num=strlen(k.ch); // ��k.num��ֵ
   p=SearchTrie(t,k); // ��Trie��t���ҹؼ��ֵ���k�ļ�¼
   if(p) // ���ڸü�¼
     Visit(p); // ����ü�¼
   else // �����ڸü�¼
     printf("δ�ҵ�"); // ���δ�ҵ���Ϣ
   printf("\n");
   DestroyDSTable(t); // ����Trie��t
 }
