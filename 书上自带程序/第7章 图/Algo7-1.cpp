 // algo7-1.cpp ����2�ֽṹ�����㷨7.4��7.6(������Ⱥ͹������)���������ĳ���
 // �������ALGraph����Ϊͼ�Ĵ洢�ṹ����������Ϊע��
 #define MG // ͼ�Ĵ洢�ṹΪMGraph����3��
 #include"c1.h"
 #include"func7-1.cpp" // ����������Ϣ���͵Ķ��弰�����Ĳ���
 #ifdef MG // ͼ�Ĵ洢�ṹΪMGraph
   #include"func7-2.cpp" // ������(��)�������Ϣ���͵Ķ��弰�����Ĳ���
   #include"c7-1.h" // ͼ������(�ڽӾ���)�洢�ṹ
   #include"bo7-1.cpp" // ͼ������(�ڽӾ���)�洢�ṹ�Ļ�������
   typedef MGraph Graph; // ����ͼ�Ĵ洢�ṹΪ�ڽӾ���
 #else // ͼ�Ĵ洢�ṹΪALGraph
   #include"func7-4.cpp" // ��(��)�������Ϣ���͵Ķ��弰�����Ĳ���
   #include"c7-2'.h" // ͼ���ڽӱ�洢�ṹ(�뵥����ı������ͽ�����ϵ)
   #include"bo7-2.cpp" // �ڽӱ�洢�ṹ�Ļ�������
   typedef ALGraph Graph; // ����ͼ�Ĵ洢�ṹΪ�ڽӱ�
 #endif
 #include"bo7-3.cpp" // �㷨7.4��7.6

 void main()
 {
   Graph g; // �����ͼ����g
   char filename[13]; // �洢�����ļ���(����·��)
   printf("�����������ļ�����");
   scanf("%s",filename);
  #ifdef MG // ͼ������(�ڽӾ���)�洢�ṹ
   CreateFromFile(g,filename,0); // �����������Ϣ��ͼ
  #else // ͼ���ڽӱ�洢�ṹ
   CreateFromFile(g,filename); // �����������Ϣ��ͼ
  #endif
   printf("����������������Ľ����\n");
   DFSTraverse(g,Visit);
   printf("����������������Ľ����\n");
   BFSTraverse(g,Visit);
 }
