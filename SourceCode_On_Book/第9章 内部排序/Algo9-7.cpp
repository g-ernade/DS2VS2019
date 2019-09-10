 // alg9-7.cpp �鲢���򣬰����㷨10.12��10.14
 #include"c1.h"
 #include"c8-2.h" // ��������ֵ�͹ؼ��ֱȽϵ�Լ��
 typedef int KeyType; // ����ؼ��ֵ�����Ϊ����
 typedef int InfoType; // �������������������Ϊ����
 #include"c9-1.h" // ��¼����������
 #include"c9-2.h" // ˳������͵Ĵ洢�ṹ
 #include"func9-1.cpp" // ���׵������������

 void Merge(RedType SR[],RedType TR[],int i,int m,int n)
 { // �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]���㷨10.12
   int j,k,p;
   for(j=m+1,k=i;i<=m&&j<=n;++k) // ��SR�м�¼��С����ز���TR
     if LQ(SR[i].key,SR[j].key)
       TR[k]=SR[i++];
     else
       TR[k]=SR[j++];
   if(i<=m)
     for(p=0;p<=m-i;p++)
       TR[k+p]=SR[i+p]; // ��ʣ���SR[i..m]���Ƶ�TR
   if(j<=n)
     for(p=0;p<=n-j;p++)
       TR[k+p]=SR[j+p]; // ��ʣ���SR[j..n]���Ƶ�TR
 }

 void MSort(RedType SR[],RedType TR1[],int s, int t)
 { // ��SR[s..t]�鲢����ΪTR1[s..t]���㷨10.13
   int m;
   RedType TR2[MAX_SIZE+1];
   if(s==t) // ֻ��1��Ԫ�ش��鲢
     TR1[s]=SR[s]; // ֱ�Ӹ�ֵ
   else // �ж��Ԫ�ش��鲢
   { m=(s+t)/2; // ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]
     MSort(SR,TR2,s,m); // �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m]
     MSort(SR,TR2,m+1,t); // �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]
     Merge(TR2,TR1,s,m,t); // ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t]
   }
 }

 void MergeSort(SqList &L)
 { // ��˳���L���鲢�����㷨10.14
   MSort(L.r,L.r,1,L.length);
   // ��˳���L.r[1..L.length]�鲢����Ϊ�����˳���L.r[1..L.length]
 }

 void main()
 {
   FILE *f; // �ļ�ָ������
   SqList m; // ˳������
   int i;
   f=fopen("f9-3.txt","r"); // �������ļ�f9-3.txt
   fscanf(f,"%d",&m.length); // �������ļ���������Ԫ�ظ�����m.length
   for(i=1;i<=m.length;i++) // ��m.r��ֵ
     InputFromFile(f,m.r[i]); // �������ļ���������Ԫ�ص�ֵ������m1.r[i]
   fclose(f); // �ر������ļ�
   printf("����ǰ��\n");
   Print(m); // �������ǰ��˳���m
   MergeSort(m); // ��m���ù鲢����
   printf("�����\n");
   Print(m); // ���������˳���m
 }
