 // bo2-5.cpp ��̬����(���ݽṹ��c2-3.h����)�Ļ�������(13��)
 // �����㷨2.13��2.15��2.16
 #define DestroyList ClearList // DestroyList()��ClearList()�Ĳ�����һ����
 int Malloc(SLinkList space) // �㷨2.15
 { // ����������ǿգ��򷵻ط���Ľ���±�(��������ĵ�1�����)�����򷵻�0
   int i=space[0].cur; // ���������1������λ��
   if(i) // ��������ǿ�
     space[0].cur=space[i].cur; // ���������ͷ���ָ��ԭ��������ĵ�2�����
   return i; // �����¿��ٽ�������
 }

 void Free(SLinkList space,int k) // �㷨2.16
 { // ���±�Ϊk�Ŀ��н����յ�����������(��Ϊ��������ĵ�1�����)
   space[k].cur=space[0].cur; // ���ս��ġ��αꡱָ��������ĵ�1�����
   space[0].cur=k; // ���������ͷ���ָ���»��յĽ��
 }

 void InitList(SLinkList L)
 { // ����һ���յ�����L����ͷΪL�����һ����ԪL[MAX_SIZE-1]�����൥Ԫ����
   // һ������������ͷΪL�ĵ�һ����ԪL[0]����0����ʾ��ָ��
   int i;
   L[MAX_SIZE-1].cur=0; // L�����һ����ԪΪ������ı�ͷ
   for(i=0;i<MAX_SIZE-2;i++) // �����൥Ԫ���ӳ���L[0]Ϊ��ͷ�ı�������
     L[i].cur=i+1;
   L[MAX_SIZE-2].cur=0;
 }

 void ClearList(SLinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   int j,k,i=L[MAX_SIZE-1].cur; // iָʾ�����1������λ��
   L[MAX_SIZE-1].cur=0; // �����
   k=L[0].cur; // ���������1������λ��
   L[0].cur=i; // ������Ľ��������������ı�ͷ
   while(i) // δ������β
   { j=i; // jָʾ��ǰ����λ��
     i=L[i].cur; // iָ����һ������λ��
   }
   L[j].cur=k; // ��������ĵ�1�����ӵ������β��
 }

 Status ListEmpty(SLinkList L)
 { // ��L�ǿձ�����TRUE�����򷵻�FALSE
   if(L[MAX_SIZE-1].cur==0) // �ձ�(��ͷ����cur��Ϊ0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SLinkList L)
 { // ����L������Ԫ�ظ���
   int j=0,i=L[MAX_SIZE-1].cur; // iָʾ����ĵ�1������λ��
   while(i) // δ����̬����β
   { i=L[i].cur; // iָ����һ�����
     j++; // ������+1
   }
   return j;
 }

 Status GetElem(SLinkList L,int i,ElemType &e)
 { // ��e����L�е�i��Ԫ�ص�ֵ
   int m,k=MAX_SIZE-1; // kָʾ��ͷ����λ��
   if(i<1||i>ListLength(L)) // �����ڵ�i��Ԫ��
     return ERROR;
   for(m=1;m<=i;m++) // k����ƶ�����i��Ԫ�ش�
     k=L[k].cur; // ָ����һ��Ԫ��
   e=L[k].data; // ����i��Ԫ�ص�ֵ����e
   return OK;
 }

 int LocateElem(SLinkList L,ElemType e) // �㷨2.13(�иĶ�)
 { // �ھ�̬�������Ա�L�в��ҵ�1��ֵΪe��Ԫ�ء����ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
   // (������LocateElem()�Ķ��岻ͬ)
   int i=L[MAX_SIZE-1].cur; // iָʾ���е�1������λ��
   while(i&&L[i].data!=e) // �ڱ���˳������(e�������ַ���)���ҵ����ѵ���β������ѭ��
     i=L[i].cur; // ָ����һ��Ԫ��
   return i;
 }

 Status PriorElem(SLinkList L,ElemType cur_e,ElemType &pre_e)
 { // ��ʼ���������Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
   //           �������ʧ�ܣ�pre_e�޶���
   int j,i=L[MAX_SIZE-1].cur; // iָʾ�����1������λ��
   do // ����ƶ����
   { j=i; // jָ��i��ָԪ��
     i=L[i].cur; // iָ����һ��Ԫ��
   }while(i&&cur_e!=L[i].data); // i��ָԪ�ش�������ֵ����cur_e������ѭ��
   if(i) // �ҵ���Ԫ��
   { pre_e=L[j].data; // j��ָԪ����i��ָԪ�ص�ǰ��Ԫ�أ�����pre_e
     return OK;
   }
   return ERROR; // δ�ҵ���Ԫ�أ�������ǰ��
 }

 Status NextElem(SLinkList L,ElemType cur_e,ElemType &next_e)
 { // ��ʼ���������Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
   //           �������ʧ�ܣ�next_e�޶���
   int j,i=LocateElem(L,cur_e); // ��L�в��ҵ�1��ֵΪcur_e��Ԫ�ص�λ��
   if(i) // L�д���Ԫ��cur_e
   { j=L[i].cur; // jָʾcur_e�ĺ�̵�λ��
     if(j) // cur_e�к��
     { next_e=L[j].data; // ��cur_e�ĺ�̸���next_e
       return OK; // cur_eԪ���к��
     }
   }
   return ERROR; // L������cur_eԪ�أ���cur_eԪ���޺��
 }

 Status ListInsert(SLinkList L,int i,ElemType e)
 { // ��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
   int m,j,k=MAX_SIZE-1; // kָʾ��ͷ����λ��
   if(i<1||i>ListLength(L)+1) // iֵ���Ϸ�
     return ERROR;
   j=Malloc(L); // �����µ�Ԫ
   if(j) // ����ɹ�
   { L[j].data=e; // ��e��ֵ���µ�Ԫ
     for(m=1;m<i;m++) // k����ƶ�i-1����㣬ʹkָʾ��i-1�����
       k=L[k].cur; // ָ����һ�����
     L[j].cur=L[k].cur; // �µ�Ԫָ���i-1��Ԫ�غ����Ԫ��(��i��Ԫ��)
     L[k].cur=j; // ��i-1��Ԫ��ָ���µ�Ԫ
     return OK;
   }
   return ERROR;
 }

 Status ListDelete(SLinkList L,int i,ElemType &e)
 { // ɾ����L�е�i������Ԫ��e����������ֵ
   int j,k=MAX_SIZE-1; // kָʾ��ͷ����λ��
   if(i<1||i>ListLength(L)) // iֵ���Ϸ�
     return ERROR;
   for(j=1;j<i;j++) // �ƶ�i-1��Ԫ�أ�ʹkָ���i-1��Ԫ��
     k=L[k].cur; // ָ����һ��Ԫ��
   j=L[k].cur; // ��ɾ��Ԫ��(��i��Ԫ��)��λ�ø���j
   L[k].cur=L[j].cur; // ʹ��i-1��Ԫ��ָ���ɾ��Ԫ�صĺ��Ԫ��
   e=L[j].data; // ��ɾ��Ԫ�ص�ֵ����e
   Free(L,j); // �ͷŴ�ɾ�����(���յ�����������)
   return OK;
 }

 void ListTraverse(SLinkList L,void(*visit)(ElemType))
 { // ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���visit()
   int i=L[MAX_SIZE-1].cur; // iָʾ��1��Ԫ�ص�λ��
   while(i) // δ����̬����β
   { visit(L[i].data); // �Ե�ǰԪ�ص���visit()
     i=L[i].cur; // ָ����һ��Ԫ��
   }
   printf("\n");
 }
