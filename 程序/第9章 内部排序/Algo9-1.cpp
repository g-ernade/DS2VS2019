 // algo9-1.cpp ����bo9-1.cpp�ĳ���
 #include"c1.h"
 #include"c8-2.h" // ��������ֵ�͹ؼ��ֱȽϵ�Լ��
 typedef int KeyType; // ����ؼ��ֵ�����Ϊ����
 typedef int InfoType; // �������������������Ϊ����
 #include"c9-1.h" // ��¼����������
 #include"c9-2.h" // ˳������͵Ĵ洢�ṹ
 #include"bo9-1.cpp" // 3��˳����������ĺ����������㷨10.1��10.2
 #include"func9-1.cpp" // ���׵������������

 void main()
 {
   FILE *f; // �ļ�ָ������
   SqList m1,m2,m3,m4; // 4��˳������
   int i;
   f=fopen("f9-1.txt","r"); // �������ļ�f9-1.txt
   fscanf(f,"%d",&m1.length); // �������ļ���������Ԫ�ظ�����m1.length
   for(i=1;i<=m1.length;i++) // ��m1.r��ֵ
     InputFromFile(f,m1.r[i]); // �������ļ���������Ԫ�ص�ֵ������m1.r[i]
   fclose(f); // �ر������ļ�
   m2=m3=m4=m1; // ����˳���m1��m2��m3��m4��ʹ֮��m1��ͬ
   printf("����ǰ��\n");
   Print(m1); // �������ǰ��˳���
   InsertSort(m1); // ��m1����ֱ�Ӳ�������
   printf("ֱ�Ӳ��������\n");
   Print(m1); // ���������m1
   BInsertSort(m2); // ��m2�����۰��������
   printf("�۰���������\n");
   Print(m2); // ���������m2
   P2_InsertSort(m3,0); // ��m3����2-·��������
   printf("2-·���������\n");
   Print(m3); // ���������m3
   P2_InsertSort(m4,1); // ��m4���øĽ���2-·��������
   printf("�Ľ���2-·���������\n");
   Print(m4); // ���������m4
 }
