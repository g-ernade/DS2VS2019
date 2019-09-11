 // bo2-6.cpp ����βָ��ĵ�ѭ������(�洢�ṹ��c2-2.h����)��12����������
 void InitList(LinkList &L)
 { // �������������һ���յ����Ա�L
   L=(LinkList)malloc(sizeof(LNode)); // ����ͷ��㣬��ʹLָ���ͷ���
   if(!L) // �洢����ʧ��
     exit(OVERFLOW);
   L->next=L; // ͷ����ָ����ָ��ͷ���
 }

 void ClearList(LinkList &L) // �ı�L
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   LinkList p,q;
   L=L->next; // Lָ��ͷ���
   p=L->next; // pָ���1�����
   while(p!=L) // δ����β
   { q=p->next; // qָ��p�ĺ�̽��
     free(p); // �ͷ�p��ָ���
     p=q; // pָ��q��ָ���
   }
   L->next=L; // ͷ���ָ����ָ������(ͷ���)
 }

 void DestroyList(LinkList &L)
 { // ����������������Ա�L
   ClearList(L); // ����L����Ϊ�ձ�
   free(L); // �ͷ�L��ָ���(ͷ���)
   L=NULL; // L��ָ���κδ洢��Ԫ
 }

 Status ListEmpty(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
   if(L->next==L) // ��
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(LinkList L)
 { // ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ���
   int i=0;
   LinkList p=L->next; // pָ��ͷ���
   while(p!=L) // δ����β
   { i++; // ������+1
     p=p->next; // pָ����һ�����
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType &e)
 { // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
   int j=1; // ��ʼ����jΪ����������ֵΪ1
   LinkList p=L->next->next; // pָ���1�����
   if(i<=0||i>ListLength(L)) // ��i��Ԫ�ز�����
     return ERROR;
   while(j<i) // ˳ָ�������ң�ֱ��pָ���i��Ԫ��
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   e=p->data; // ��i��Ԫ�ظ���e
   return OK;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
   int i=0; // ��������ֵΪ0
   LinkList p=L->next->next; // pָ���1�����
   while(p!=L->next) // pδָ��ͷ���
   { i++; // ������+1
     if(compare(p->data,e)) // �ҵ�����������Ԫ��
       return i; // ������λ��
     p=p->next; // pָ����һ�����
   }
   return 0; // �����ϵ������Ԫ�ز�����
 }

 Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
 { // ��ʼ���������Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��������OK��
   //           �������ʧ�ܣ�pre_e�޶��壬����ERROR
   LinkList q,p=L->next->next; // pָ���1�����
   q=p->next; // qָ��p�ĺ��
   while(q!=L->next) // pδ����β(qδָ��ͷ���)
   { if(q->data==cur_e) // p�ĺ��Ϊcur_e
     { pre_e=p->data; // ��p��ָԪ�ص�ֵ����pre_e
       return OK; // �ɹ�����OK
     }
     p=q; // p�ĺ�̲�Ϊcur_e��p�����
     q=q->next; // qָ��p�ĺ��
   }
   return ERROR; // ����ʧ�ܣ�����ERROR
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
 { // ��ʼ���������Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK��
   //           �������ʧ�ܣ�next_e�޶��壬����ERROR
   LinkList p=L->next->next; // pָ���1�����
   while(p!=L) // pδ����β
   { if(p->data==cur_e) // p��ָ����ֵΪcur_e
     { next_e=p->next->data; // ��p��ָ���ĺ�̽���ֵ����next_e
       return OK; // �ɹ�����OK
     }
     p=p->next; // pָ����һ�����
   }
   return ERROR; // ����ʧ�ܣ�����ERROR
 }

 Status ListInsert(LinkList &L,int i,ElemType e)
 { // ��L�ĵ�i��λ��֮ǰ����Ԫ��e(�ı�L)
   LinkList p=L->next,s; // pָ��ͷ���
   int j=0; // ��������ֵΪ0
   if(i<=0||i>ListLength(L)+1) // iֵ���Ϸ�
     return ERROR; // ����ʧ��
   while(j<i-1) // Ѱ�ҵ�i-1�����
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   s=(LinkList)malloc(sizeof(LNode)); // �����½�㣬���½������L��
   s->data=e; // ��e�����½��
   s->next=p->next; // �½��ָ��ԭ��i�����
   p->next=s; // ԭ��i-1�����ָ���½��
   if(p==L) // ���ڱ�β
     L=s; // Lָ���µ�β���
   return OK; // ����ɹ�
 }

 Status ListDelete(LinkList &L,int i,ElemType &e)
 { // ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ(�ı�L)
   LinkList q,p=L->next; // pָ��ͷ���
   int j=0; // ��������ֵΪ0
   if(i<=0||i>ListLength(L)) // ��i��Ԫ�ز�����
     return ERROR; // ɾ��ʧ��
   while(j<i-1) // Ѱ�ҵ�i-1�����
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   q=p->next; // qָ���ɾ����㣬p�ĺ��
   p->next=q->next; // ��ɾ����ǰ��ָ���ɾ���ĺ��
   e=q->data; // ����ɾ����ֵ����e
   if(L==q) // ɾ�����Ǳ�βԪ��
     L=p; // Lָ���µı�βԪ��
   free(q); // �ͷŴ�ɾ�����
   return OK; // ɾ���ɹ�
 }

 void ListTraverse(LinkList L,void(*vi)(ElemType))
 { // ��ʼ������L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()
   LinkList p=L->next->next; // pָ����Ԫ���
   while(p!=L->next) // p��ָ��ͷ���
   { vi(p->data); // ��p��ָ�����ú���vi()
     p=p->next; // pָ����һ�����
   }
   printf("\n");
 }
