 // algo10-3.cpp ����bo10-1.cpp�ĳ���(����algo10-2.cpp�����д˳���)
 #include"c1.h"
 typedef int KeyType; // ����ؼ��ֵ�����Ϊ����
 typedef int InfoType; // �������������������Ϊ����
 #include"c9-1.h" // ��¼����������
 #define k 5 // k(5)·�鲢������2��ȡ1�С���6��
 //#define k 3 // 3·�鲢����7��
 FILE *fp[k+1]; // k+1���ļ�ָ��(fp[k]Ϊ���ļ�ָ��)��ȫ�ֱ���
 typedef int LoserTree[k];
 // [1..k-1]�ǰ������ķ�Ҷ�ӽ�㣬[0]����ʤ�ߣ�����ӦҶ�ӵ����
 RedType b[k+1]; // [0..k-1]�ǰ�������Ҷ��(����)��[k]����С�ؼ���
 #define MIN_KEY INT_MIN // ��С�ؼ���
 #define MAX_KEY INT_MAX // ���ؼ���
 #define M 10 // �����M�����������ݻ���

 void Print(RedType t)
 { printf("(%d,%d)",t.key,t.otherinfo);
 }

 #include"bo10-1.cpp" // k·ƽ��鲢�ĺ���

 void main()
 {
   LoserTree ls; // ������������Ϊk����������
   int i;
   char outfile[10],filename[3]; // ���ļ���,����С�ļ���
   for(i=0;i<k;i++)
   { itoa(i,filename,10); // i��Ϊ��ʱ������С�ļ����ļ���
     fp[i]=fopen(filename,"r"); // �Զ��ķ�ʽ���������С�ļ�0��1������k-1
   }
   printf("�����������Ĵ��ļ�����");
   scanf("%s",outfile); // ���������Ĵ��ļ�����outfile
   fp[k]=fopen(outfile,"w"); // ��д�ķ�ʽ�������Ĵ��ļ�outfile
   printf("������ļ�%s�ļ�¼Ϊ��\n",outfile);
   K_Merge(ls); // ���ð�������k������С�ļ��еļ�¼�鲢Ϊ1��������ļ�
   printf("\n"); // ����
   for(i=0;i<=k;i++)
     fclose(fp[i]); // �ر��ļ�0��1������������Ĵ��ļ�outfile
 }
