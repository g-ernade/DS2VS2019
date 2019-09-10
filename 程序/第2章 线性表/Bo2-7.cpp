 // bo2-7.cpp ��ͷ����˫��ѭ������(�洢�ṹ��c2-4.h����)�Ļ�������(14��)
 // �����㷨2.18��2.19
 void InitList(DuLinkList &L)
 { // �����յ�˫��ѭ������L
   L=(DuLinkList)malloc(sizeof(DuLNode));
   if(L)
     L->next=L->prior=L;
   else
     exit(OVERFLOW);
 }

 void ClearList(DuLinkList L) // ���ı�L
 { // ��ʼ������L�Ѵ��ڡ������������L����Ϊ�ձ�
   DuLinkList p=L->next; // pָ���1�����
   while(p!=L) // pδָ��ͷ���
   { p=p->next; // pָ����һ�����
     free(p->prior); // �ͷ�p��ǰ�����
   }
   L->next=L->prior=L; // ͷ��������ָ�����ָ������
 }

 void DestroyList(DuLinkList &L)
 { // �������������˫��ѭ������L
   ClearList(L); // ��L����Ϊ�ձ�
   free(L); // �ͷ�ͷ���
   L=NULL; // L��ָ���κδ洢��Ԫ
 }

 Status ListEmpty(DuLinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
   if(L->next==L&&L->prior==L)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(DuLinkList L)
 { // ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ���
   int i=0; // ��������ֵΪ0
   DuLinkList p=L->next; // pָ���1�����
   while(p!=L) // pδָ��ͷ���
   { i++; // ������+1
     p=p->next; // pָ����һ�����
   }
   return i;
 }

 Status GetElem(DuLinkList L,int i,ElemType &e)
 { // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
   int j=1; // ��������ֵΪ1
   DuLinkList p=L->next; // pָ���1�����
   while(p!=L&&j<i) // ˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pָ��ͷ���
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   if(p==L||j>i) // ��i��Ԫ�ز�����
     return ERROR; // ����ʧ��
   e=p->data; // ȡ��i��Ԫ�ظ���e
   return OK; // ���ҳɹ�
 }

 int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ������L�Ѵ��ڣ�compare()������Ԫ���ж�����
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
   int i=0; // ��������ֵΪ0
   DuLinkList p=L->next; // pָ���1��Ԫ��
   while(p!=L) // pδָ��ͷ���
   { i++; // ������+1
     if(compare(p->data,e)) // �ҵ�����������Ԫ��
       return i; // ������λ��
     p=p->next; // pָ����һ�����
   }
   return 0; // �����ϵ������Ԫ�ز�����
 }

 Status PriorElem(DuLinkList L,ElemType cur_e,ElemType &pre_e)
 { // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��������OK��
   //           �������ʧ�ܣ�pre_e�޶��壬����ERROR
   DuLinkList p=L->next->next; // pָ���2��Ԫ��
   while(p!=L) // pδָ��ͷ���
   { if(p->data==cur_e) // pָ��ֵΪcur_e�Ľ��
     { pre_e=p->prior->data; // ��p��ǰ������ֵ����pre_e
       return OK; // �ɹ�����OK
     }
     p=p->next; // pָ����һ�����
   }
   return ERROR; // ����ʧ�ܣ�����ERROR
 }

 Status NextElem(DuLinkList L,ElemType cur_e,ElemType &next_e)
 { // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK��
   //           �������ʧ�ܣ�next_e�޶��壬����ERROR
   DuLinkList p=L->next->next; // pָ���2��Ԫ��
   while(p!=L) // pδָ��ͷ���
   { if(p->prior->data==cur_e) // p��ָ����ǰ����ֵΪcur_e
     { next_e=p->data; // ��p��ָ���(cur_e�ĺ��)��ֵ����next_e
       return OK; // �ɹ�����OK
     }
     p=p->next; // pָ����һ�����
   }
   return ERROR; // ����ʧ�ܣ�����ERROR
 }

 DuLinkList GetElemP(DuLinkList L,int i) // ����
 { // ��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ������i��Ԫ�ز����ڣ�
   // ����NULL(�㷨2.18��2.19Ҫ���õĺ���)
   int j;
   DuLinkList p=L; // pָ��ͷ���
   if(i<0||i>ListLength(L)) // iֵ���Ϸ�
     return NULL;
   for(j=1;j<=i;j++) // pָ���i�����
     p=p->next; // pָ����һ�����
   return p;
 }

 Status ListInsert(DuLinkList L,int i,ElemType e)
 { // �ڴ�ͷ����˫��ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1��i�ܱ�+1
   // �Ľ��㷨2.18�������޷��ڵڱ�+1�����֮ǰ����Ԫ��
   DuLinkList p,s;
   if(i<1||i>ListLength(L)+1) // iֵ���Ϸ�
     return ERROR; // ʧ�ܷ���ERROR
   p=GetElemP(L,i-1); // ��L��ȷ����i�����ǰ����λ��ָ��p
   if(!p) // p=NULL������i������ǰ��������(��ͷ���Ϊ��1������ǰ��)
     return ERROR; // ʧ�ܷ���ERROR
   s=(DuLinkList)malloc(sizeof(DuLNode)); // �����½��
   if(!s)
     return ERROR; // �����½��ʧ�ܷ���ERROR
   s->data=e; // ��e�����½��
   s->prior=p; // �½���ǰ��Ϊ��i-1�����
   s->next=p->next; // �½��ĺ��Ϊ��i�����
   p->next->prior=s; // ��i������ǰ��ָ���½��
   p->next=s; // ��i-1�����ĺ��ָ���½��
   return OK; // �ɹ�����OK
 }

 Status ListDelete(DuLinkList L,int i,ElemType &e) // �㷨2.19
 { // ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�i�ĺϷ�ֵΪ1��i�ܱ�
   DuLinkList p;
   if(i<1) // iֵ���Ϸ�
     return ERROR; // ɾ��ʧ��
   p=GetElemP(L,i); // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
   if(!p) // p=NULL������i��Ԫ�ز�����
     return ERROR; // ɾ��ʧ��
   e=p->data; // ����i��Ԫ�ص�ֵ����e
   p->prior->next=p->next; // ��i-1�����ĺ��ָ��ԭ��i+1�����
   p->next->prior=p->prior; // ԭ��i+1������ǰ��ָ���i-1�����
   free(p); // �ͷŵ�i�����
   return OK; // ɾ���ɹ�
 }

 void ListTraverse(DuLinkList L,void(*visit)(ElemType))
 { // ��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()
   DuLinkList p=L->next; // pָ����Ԫ���
   while(p!=L) // pδָ��ͷ���
   { visit(p->data); // ��p��ָ�����ú���visit()
     p=p->next; // pָ����һ�����
   }
   printf("\n");
 }

 void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
 { // ��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()������
   DuLinkList p=L->prior; // pָ��β���
   while(p!=L) // pδָ��ͷ���
   { visit(p->data); // ��p��ָ�����ú���visit()
     p=p->prior; // pָ��ǰһ�����
   }
   printf("\n");
 }
