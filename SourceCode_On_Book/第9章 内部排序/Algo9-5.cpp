 // algo9-5.cpp �����㷨10.7��10.8��10.6(a)��10.6(b)�ĳ���
 #include<stdio.h>
 typedef int KeyType; // ����ؼ��ֵ�����Ϊ����
 typedef int InfoType; // �������������������Ϊ����
 #include"c9-1.h" // ��¼����������
 #include"c9-2.h" // ˳������͵Ĵ洢�ṹ
 #include"func9-1.cpp" // ���׵������������
 #include"func9-3.cpp" // �㷨10.6(a)������Partition()����2����ȡ1�У����н����ͬ
 //#include"func9-4.cpp" // �㷨10.6(b)������Partition()
 #include"bo9-2.cpp" // ��������ĺ����������㷨10.7��10.8

 void main()
 {
   FILE *f; // �ļ�ָ������
   SqList m; // ˳������
   int i;
   f=fopen("f9-1.txt","r"); // �������ļ�f9-1.txt
   fscanf(f,"%d",&m.length); // �������ļ���������Ԫ�ظ�����m.length
   for(i=1;i<=m.length;i++) // ��m.r��ֵ
     InputFromFile(f,m.r[i]); // �������ļ���������Ԫ�ص�ֵ������m.r[i]
   fclose(f); // �ر������ļ�
   printf("����ǰ��\n");
   Print(m); // �������ǰ��˳���m
   QuickSort(m); // ��m���ÿ�������
   printf("�����\n");
   Print(m); // ���������˳���m
 }
