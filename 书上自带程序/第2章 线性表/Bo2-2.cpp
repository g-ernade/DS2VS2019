 // bo2-2.cpp ����ͷ���ĵ�����(�洢�ṹ��c2-2.h����)�Ļ�������(12��)��
 // �����㷨2.8��2.10
 void InitList(LinkList &L)
 { // �������������һ���յ����Ա�L
   L=(LinkList)malloc(sizeof(LNode)); // ����ͷ��㣬��ʹLָ���ͷ���
   if(!L) // �洢����ʧ��
     exit(OVERFLOW);
   L->next=NULL; // ͷ����ָ����Ϊ��
 }

 void DestroyList(LinkList &L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L
   LinkList q;
   while(L) // Lָ����(�ǿ�)
   { q=L->next; // qָ����Ԫ���
     free(L); // �ͷ�ͷ���
     L=q; // Lָ��ԭ��Ԫ��㣬��ͷ���
   }
 }

 void ClearList(LinkList L) // ���ı�L
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   LinkList p=L->next; // pָ���1�����
   L->next=NULL; // ͷ���ָ����Ϊ��
   DestroyList(p); // ����p��ָ�ĵ�����
 }

 Status ListEmpty(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
   if(L->next) // �ǿ�
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�صĸ���
   int i=0; // ��������ֵΪ0
   LinkList p=L->next; // pָ���1�����
   while(p) // δ����β
   { i++; // ������+1
     p=p->next; // pָ����һ�����
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType &e) // �㷨2.8
 { // LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
   int j=1; // ��������ֵΪ1
   LinkList p=L->next; // pָ���1�����
   while(p&&j<i) // ˳ָ�������ң�ֱ��pָ���i������pΪ��(��i����㲻����)
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   if(!p||j>i) // ��i����㲻����
     return ERROR;
   e=p->data; // ȡ��i��Ԫ�ص�ֵ����e
   return OK;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
   int i=0; // ��������ֵΪ0
   LinkList p=L->next; // pָ���1�����
   while(p) // δ����β
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
   LinkList q,p=L->next; // pָ���1�����
   while(p->next) // p��ָ����к��
   { q=p->next; // qָ��p�ĺ��
     if(q->data==cur_e) // p�ĺ��Ϊcur_e
     { pre_e=p->data; // ��p��ָԪ�ص�ֵ����pre_e
       return OK; // �ɹ�����OK
     }
     p=q; // p�ĺ�̲�Ϊcur_e��p�����
   }
   return ERROR; // ����ʧ�ܣ�����ERROR
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
 { // ��ʼ���������Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK��
   //           �������ʧ�ܣ�next_e�޶��壬����ERROR
   LinkList p=L->next; // pָ���1�����
   while(p->next) // p��ָ����к��
   { if(p->data==cur_e) // p��ָ����ֵΪcur_e
     { next_e=p->next->data; // ��p��ָ���ĺ�̽���ֵ����next_e
       return OK; // �ɹ�����OK
     }
     p=p->next; // pָ����һ�����
   }
   return ERROR; // ����ʧ�ܣ�����ERROR
 }

 Status ListInsert(LinkList L,int i,ElemType e) // �㷨2.9�����ı�L
 { // �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
   int j=0; // ��������ֵΪ0
   LinkList s,p=L; // pָ��ͷ���
   while(p&&j<i-1) // Ѱ�ҵ�i-1�����
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   if(!p||j>i-1) // iС��1���ߴ��ڱ�
     return ERROR; // ����ʧ��
   s=(LinkList)malloc(sizeof(LNode)); // �����½�㣬���½������L��
   s->data=e; // ��e�����½��
   s->next=p->next; // �½��ָ��ԭ��i�����
   p->next=s; // ԭ��i-1�����ָ���½��
   return OK; // ����ɹ�
 }

 Status ListDelete(LinkList L,int i,ElemType &e) // �㷨2.10�����ı�L
 { // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
   int j=0; // ��������ֵΪ0
   LinkList q,p=L; // pָ��ͷ���
   while(p->next&&j<i-1) // Ѱ�ҵ�i����㣬����pָ����ǰ��
   { j++; // ������+1
     p=p->next; // pָ����һ�����
   }
   if(!p->next||j>i-1) // ɾ��λ�ò�����
     return ERROR; // ɾ��ʧ��
   q=p->next; // qָ���ɾ�����
   p->next=q->next; // ��ɾ����ǰ��ָ���ɾ���ĺ��
   e=q->data; // ����ɾ����ֵ����e
   free(q); // �ͷŴ�ɾ���
   return OK; // ɾ���ɹ�
 }

 void ListTraverse(LinkList L,void(*visit)(ElemType))
 // visit���β�����ΪElemType����bo2-1.cpp����Ӧ�������β�����ElemType&��ͬ
 { // ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���visit()
   LinkList p=L->next; // pָ���1�����
   while(p) // p��ָ������
   { visit(p->data); // ��p��ָ�����ú���visit()
     p=p->next; // pָ����һ�����
   }
   printf("\n");
 }
