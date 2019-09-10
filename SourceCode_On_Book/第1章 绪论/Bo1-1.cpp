 // bo1-1.cpp ������������Triplet��ElemType(��c1-1.h����)�Ļ�������(8��)
 Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
 { // ���������������Ԫ��T��������T��3��Ԫ�صĳ�ֵΪv1��v2��v3���ڽ̿����12ҳ
   T=(ElemType*)malloc(3*sizeof(ElemType)); // ����3��Ԫ�صĴ洢�ռ�
   if(!T)
     exit(OVERFLOW); // ����ʧ�����˳�
   T[0]=v1,T[1]=v2,T[2]=v3;
   return OK;
 }

 Status DestroyTriplet(Triplet &T)
 { // �����������Ԫ��T�����١��ڽ̿����12ҳ
   free(T); // �ͷ�T��ָ����Ԫ��洢�ռ�
   T=NULL; // T����ָ���κδ洢��Ԫ
   return OK;
 }

 Status Get(Triplet T,int i,ElemType &e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڣ�1��i��3�������������e����T�ĵ�iԪ��ֵ���ڽ̿����12ҳ
   if(i<1||i>3) // i������Ԫ��ķ�Χ֮��
     return ERROR;
   e=T[i-1]; // ����Ԫ��T�ĵ�i��Ԫ�ص�ֵ����e
   return OK;
 }

 Status Put(Triplet T,int i,ElemType e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڣ�1��i��3������������ı�T�ĵ�iԪ��ֵΪe���ڽ̿����12ҳ
   if(i<1||i>3) // i������Ԫ��ķ�Χ֮��
     return ERROR;
   T[i-1]=e; // ��e��ֵ������Ԫ��T�ĵ�i��Ԫ��
   return OK;
 }

 Status IsAscending(Triplet T) // �ڽ̿����13ҳ
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ�������������T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0
   return(T[0]<=T[1]&&T[1]<=T[2]); // ֻ��T[0]������T[1]��T[1]������T[2]ʱ������
 }

 Status IsDescending(Triplet T) // �ڽ̿����13ҳ
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ�������������T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0
   return(T[0]>=T[1]&&T[1]>=T[2]); // ֻ��T[0]��С��T[1]��T[1]��С��T[2]ʱ������
 }

 Status Max(Triplet T,ElemType &e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ������������e����ָ��T�����Ԫ�ص�ֵ���ڽ̿����13ҳ
   e=(T[0]>=T[1])?(T[0]>=T[2]?T[0]:T[2]):(T[1]>=T[2]?T[1]:T[2]); // Ƕ�׵����������
   return OK;
 }

 Status Min(Triplet T,ElemType &e)
 { // ��ʼ��������Ԫ��T�Ѵ��ڡ������������e����ָ��T����СԪ�ص�ֵ���ڽ̿����13ҳ
   e=(T[0]<=T[1])?(T[0]<=T[2]?T[0]:T[2]):(T[1]<=T[2]?T[1]:T[2]); // Ƕ�׵����������
   return OK;
 }
