 // bo9-1.cpp ˳����������ĺ���(3��)�������㷨10.1���㷨10.2
 void InsertSort(SqList &L)
 { // ��˳���L��ֱ�Ӳ��������㷨10.1
   int i,j;
   for(i=2;i<=L.length;++i) // �ӵ�2����¼�����һ����¼
     if LT(L.r[i].key,L.r[i-1].key) // ��ǰ��¼<ǰһ����¼
     { // ��L.r[i]����[1..i-1]�������ӱ���
       L.r[0]=L.r[i]; // ����ǰ��¼����Ϊ�ڱ�(����[0]��)
       for(j=i-1;LT(L.r[0].key,L.r[j].key);--j) // �����ӱ�Ӻ�ǰ�����ڱ�С�ڼ�¼
         L.r[j+1]=L.r[j]; // ��¼����1����Ԫ
       L.r[j+1]=L.r[0]; // ���ڱ�(��ǰ��¼)���뵽��ȷλ��
     }
 }

 void BInsertSort(SqList &L)
 { // ��˳���L���۰���������޸��㷨10.2
   int i,j,m,low,high;
   for(i=2;i<=L.length;++i) // �ӵ�2����¼�����һ����¼
     if LT(L.r[i].key,L.r[i-1].key) // ��ǰ��¼<ǰһ����¼���Ӵ˾�
     { // ��L.r[i]����[1..i-1]�������ӱ���
       L.r[0]=L.r[i]; // ��L.r[i]�ݴ浽L.r[0]
       low=1; // ��������ĵͶ�
       high=i-1; // ��������ĸ߶�
       while(low<=high) // ��r[low..high]���۰������������λ��
       { m=(low+high)/2; // �۰�(�е�λ��m)
         if LT(L.r[0].key,L.r[m].key) // �ؼ���С���е�ؼ���
           high=m-1; // ������ڵͰ���
         else // �ؼ��ִ��ڵ����е�ؼ���
           low=m+1; // ������ڸ߰���
       } // low>high���˳�whileѭ����[high+1]�ǲ���λ��
       for(j=i-1;j>=high+1;--j) // �����ӱ�Ӻ�ǰ
         L.r[j+1]=L.r[j]; // ��¼����
       L.r[high+1]=L.r[0]; // ���뵽[high+1]
     }
 }

 void P2_InsertSort(SqList &L,int flag)
 { // 2-·��������(flag=0)�͸Ľ���2-·��������(flag=1����L.r[1]�Ǵ������¼�йؼ���
   // ��С�����ļ�¼ʱ��������Խ��)
   int i,j,first,final,mid=0;
   RedType *d;
   d=(RedType*)malloc(L.length*sizeof(RedType)); // ����L.length����¼����ʱ�ռ�
   d[0]=L.r[1]; // ��L�ĵ�1����¼Ϊd���ź���ļ�¼(��λ��[0])
   first=final=0; // first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������1����¼��λ��
   for(i=2;i<=L.length;++i) // ���ν�L�ĵ�2�������1����¼����d��
   { if(flag) // �Ľ���2-·��������ÿ�β���ǰ����mid
     { if(first>final)
         j=L.length; // j�ǵ���ϵ��
       else
         j=0;
       mid=(first+final+j)/2%L.length; // d���м��¼��λ��
     }
     if(L.r[i].key<d[mid].key) // �����¼������d��ǰ�벿����(flag=0ʱ��mid=0)
     { j=first; // jָ��d�ĵ�1����¼
       first=(first-1+L.length)%L.length; // firstǰ��
       while(L.r[i].key>d[j].key) // �����¼����j��ָ��¼
       { d[(j-1+L.length)%L.length]=d[j]; // j��ָ��¼ǰ��
         j=(j+1)%L.length; // jָ����1����¼
       }
       d[(j-1+L.length)%L.length]=L.r[i]; // �ƶ������������¼����[j]ǰ
     }
     else // �����¼�����ں�벿����
     { j=final++; // jָ��ǰ�����1����¼��finalָ����������1����¼
       while(L.r[i].key<d[j].key) // �����¼С��j��ָ��¼
       { d[(j+1)%L.length]=d[j]; // j��ָ��¼���ƣ�flag=0ʱ��������
         j=(j-1+L.length)%L.length; // jָ����1����¼��flag=0ʱ��������
       }
       d[(j+1)%L.length]=L.r[i];
       // �����¼��С��j��ָ��¼������j��flag=0ʱ��������
     }
   }
   for(i=1;i<=L.length;i++) // ����d���ź���ļ�¼���θ���L.r
     L.r[i]=d[(first+i-1)%L.length]; // ���Թ�ϵ
   free(d); // �ͷ�d��ָ�Ĵ洢�ռ�
 }
