 // algo9-3.cpp ϣ�����򣬰����㷨10.4��10.5
 #include<stdio.h>
 #include"c8-2.h" // ��������ֵ�͹ؼ��ֱȽϵ�Լ��
 typedef int KeyType; // ����ؼ��ֵ�����Ϊ����
 typedef int InfoType; // �������������������Ϊ����
 #include"c9-1.h" // ��¼����������
 #include"c9-2.h" // ˳������͵Ĵ洢�ṹ
 #include"func9-1.cpp" // ���׵������������

 void Print1(SqList L) // ���˳���L�Ĺؼ���
 { int i;
   for(i=1;i<=L.length;i++)
     printf("%d ",L.r[i].key);
   printf("\n");
 }

 void ShellInsert(SqList &L,int dk)
 { // ��˳���L��һ��ϣ���������򡣱��㷨��һ��ֱ�Ӳ���������ȣ����������޸ģ�
   // 1.ǰ���¼λ�õ�������dk��������1;
   // 2.r[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ�����ҵ����㷨10.4
   int i,j;
   for(i=dk+1;i<=L.length;++i) // �����1����¼�������dk�ļ�¼����β
     if LT(L.r[i].key,L.r[i-dk].key) // �ؼ���С��ǰ���¼��(������)
     { // ���½�L.r[i]�������������ӱ�
       L.r[0]=L.r[i]; // ��ǰ��¼�ݴ���L.r[0]
       for(j=i-dk;j>0&&LT(L.r[0].key,L.r[j].key);j-=dk)
         L.r[j+dk]=L.r[j]; // ��¼���ƣ����Ҳ���λ��
       L.r[j+dk]=L.r[0]; // ����
     }
 }

 void ShellSort(SqList &L,int dlta[],int t)
 { // ����������dlta[0..t-1]��˳���L��ϣ�������㷨10.5
   int k;
   for(k=0;k<t;++k) // ��������������
   { ShellInsert(L,dlta[k]); // һ������Ϊdlta[k]��ϣ����������
     printf("dlta[%d]=%d����%d��������(������ؼ���)��",k,dlta[k],k+1);
     Print1(L); // ���˳���L�Ĺؼ���
   }
 }

 #define N 10 // ��¼���鳤��
 #define T 3 // �����������鳤��
 void main()
 {
   RedType d[N]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},
   {55,9},{4,10}}; // ��¼����
   SqList m; // ˳���
   int i,dt[T]={5,3,1}; // ������������(�ɴ�С�����һ���ֵ��Ϊ1)
   for(i=0;i<N;i++) // ������d����˳���m
     m.r[i+1]=d[i];
   m.length=N;
   printf("ϣ������ǰ��");
   Print(m); // �������ǰ��˳���m
   ShellSort(m,dt,T); // ����������dt[0..T-1]��˳���m��ϣ������
   printf("ϣ�������");
   Print(m); // ���������˳���m
 }
