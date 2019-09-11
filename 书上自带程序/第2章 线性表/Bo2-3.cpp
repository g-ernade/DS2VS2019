 // bo2-3.cpp ����ͷ���ĵ�����(�洢�ṹ��c2-2.h����)�Ĳ��ֻ�������(9��)
 #define DestroyList ClearList // DestroyList()��ClearList()�Ĳ�����һ����
 void InitList(LinkList &L)
 { // �������������һ���յ����Ա�L
   L=NULL; // ָ��Ϊ��
 }

 void ClearList(LinkList &L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   LinkList p;
   while(L) // L����
   { p=L; // pָ����Ԫ���
     L=L->next; // Lָ���2�����(����Ԫ���)
     free(p); // �ͷ���Ԫ���
   }
 }

 Status ListEmpty(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
   if(L)
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�صĸ���
   int i=0; // ��������ֵΪ0
   LinkList p=L; // pָ���1�����
   while(p) // pָ����(δ����β)
   { i++; // ������+1
     p=p->next; // pָ����һ�����
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType &e)
 { // LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK��
   // ���򷵻�ERROR
   int j=1; // ��������ֵΪ1
   LinkList p=L; // pָ���1�����
   if(i<1) // iֵ���Ϸ�
     return ERROR;
   while(j<i&&p) // δ����i��Ԫ�أ�Ҳδ����β
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   if(j==i&&p) // ���ڵ�i��Ԫ��
   { e=p->data; // ȡ��i��Ԫ�ص�ֵ����e
     return OK; // �ɹ�����OK
   }
   return ERROR; // �����ڵ�i��Ԫ�أ�ʧ�ܷ���ERROR
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
   int i=0; // ��������ֵΪ0
   LinkList p=L; // pָ���1�����
   while(p) // δ����β
   { i++; // ������+1
     if(compare(p->data,e)) // �ҵ�����������Ԫ��
       return i; // ������λ��
     p=p->next; // pָ����һ�����
   }
   return 0; // �����ϵ������Ԫ�ز�����
 }

 Status ListInsert(LinkList &L,int i,ElemType e)
 { // �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
   int j=1; // ��������ֵΪ1
   LinkList s,p=L; // pָ���1�����
   if(i<1) // iֵ���Ϸ�
     return ERROR;
   s=(LinkList)malloc(sizeof(LNode)); // �����½�㣬���½������L��
   s->data=e; // ��s��data��ֵe
   if(i==1) // ���ڱ�ͷ
   { s->next=L; // �½��ָ��ԭ��1�����
     L=s; // Lָ���½��(�ı�L)
   }
   else
   { // ���ڱ�����ദ
     while(p&&j<i-1) // Ѱ�ҵ�i-1�����
     { j++; // ������+1
       p=p->next; // pָ����һ�����
     }
     if(!p) // i���ڱ�+1
       return ERROR; // ����ʧ��
     s->next=p->next; // �½��ָ��ԭ��i�����
     p->next=s; // ԭ��i-1�����ָ���½��
   }
   return OK; // ����ɹ�
 }

 Status ListDelete(LinkList &L,int i,ElemType &e)
 { // �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
   int j=1; // ��������ֵΪ1
   LinkList q,p=L; // pָ���1�����
   if(!L) // ��L��
     return ERROR; // ɾ��ʧ��
   else if(i==1) // ɾ����1�����
   { L=p->next; // L�ɵ�2����㿪ʼ(�ı�L)
     e=p->data; // ����ɾ����ֵ����e
     free(p); // ɾ�����ͷŵ�1�����
   }
   else
   { while(p->next&&j<i-1) // Ѱ�ҵ�i����㣬����pָ����ǰ��
     { j++; // ������+1
       p=p->next; // pָ����һ�����
     }
     if(!p->next||j>i-1) // ɾ��λ�ò�����
       return ERROR; // ɾ��ʧ��
     q=p->next; // qָ���ɾ�����
     p->next=q->next; // ��ɾ����ǰ��ָ���ɾ���ĺ��
     e=q->data; // ����ɾ����ֵ����e
     free(q); // �ͷŴ�ɾ���
   }
   return OK; // ɾ���ɹ�
 }

 void ListTraverse(LinkList L,void(*vi)(ElemType))
 { // ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()
   LinkList p=L; // pָ���1�����
   while(p) // p��ָ������
   { vi(p->data); // ��p��ָ�����ú���vi()
     p=p->next; // pָ����һ�����
   }
   printf("\n");
 }
