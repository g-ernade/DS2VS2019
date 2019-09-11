 // algo5-2.cpp ʵ���㷨5.2�ĳ���
 #include"c1.h"
 typedef int ElemType; // �������Ԫ������ElemTypeΪ����
 #include"c5-2.h" // ϡ��������Ԫ��˳���洢�ṹ
 #include"func5-1.cpp" // comp()����
 #include"bo5-2.cpp" // ��Ԫ��ϡ�����Ļ�������(4��)
 #include"bo5-3.cpp" // Ҳ���������߼����ӽṹ��Ԫ��ϡ�����Ļ�������(4��)

 void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
 { // ������ϡ�����M��ת�þ���T���޸��㷨5.2
   int p,q,col,*num,*cpot;
   num=(int*)malloc((M.nu+1)*sizeof(int)); // ��Mÿ��(Tÿ��)����Ԫ�ظ���([0]����)
   cpot=(int*)malloc((M.nu+1)*sizeof(int)); // ��Tÿ����һ������Ԫ�ص�λ��([0]����)
   T.mu=M.nu; // T������=M������
   T.nu=M.mu; // T������=M������
   T.tu=M.tu; // T�ķ���Ԫ�ظ���=M�ķ���Ԫ�ظ���
   if(T.tu) // T�Ƿ������
   { for(col=1;col<=M.nu;++col) // ��M�ĵ�1�е����һ��
       num[col]=0; // ��������ֵ��Ϊ0
     for(p=1;p<=M.tu;++p) // ����M��ÿһ������Ԫ��
       ++num[M.data[p].j]; // ���������ڵ��н���ͳ��
     cpot[1]=1; // T�ĵ�1�еĵ�1������Ԫ��T.data�е����Ϊ1
     for(col=2;col<=M.nu;++col) // ��M(T)�ĵ�2��(��)�����һ��(��)
       cpot[col]=cpot[col-1]+num[col-1]; // ��T�ĵ�col�е�1������Ԫ��T.data�е����
     for(p=1;p<=M.tu;++p) // ����M��ÿһ������Ԫ��
     { col=M.data[p].j; // ������M�е���������col
       q=cpot[col]; // qָʾM��ǰ��Ԫ����T�е����
       T.data[q].i=M.data[p].j; // ��M��ǰ��Ԫ��ת�ȸ���T
       T.data[q].j=M.data[p].i;
       T.data[q].e=M.data[p].e;
       ++cpot[col]; // T��col�е���1������Ԫ��T.data�е���űȵ�ǰԪ�ص���Ŵ�1
     }
   }
   free(num); // �ͷ�num��cpot��ָ��Ķ�̬�洢�ռ�
   free(cpot);
 }

 void main()
 {
   TSMatrix A,B;
   printf("��������A��");
   CreateSMatrix(A); // ��������A
   PrintSMatrix(A); // �������A
   FastTransposeSMatrix(A,B); // B��A��ת�Ⱦ���
   printf("����B(A�Ŀ���ת��)��\n");
   PrintSMatrix(B); // �������B
 }
