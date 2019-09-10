 // bo8-2.cpp �����������Ļ�������(4��)�������㷨9.5(b)���㷨9.6��9.8
 Status SearchBST(BiTree &T,KeyType key,BiTree f,BiTree &p) // �㷨9.5(b)
 { // �ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ������ҳɹ���
   // ��ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ�����·���Ϸ��ʵ����һ�����
   // ������FALSE��ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
   if(!T) // ���Ҳ��ɹ�
   { p=f; // pָ�����·���Ϸ��ʵ����һ�����
     return FALSE;
   }
   else if EQ(key,T->data.key) // ���ҳɹ�
   { p=T; // pָ�������Ԫ�ؽ��
     return TRUE;
   }
   else if LT(key,T->data.key) // keyС��T��ָ���Ĺؼ���
     return SearchBST(T->lchild,key,T,p); // ���������м����ݹ����
   else // key����T��ָ���Ĺؼ���
     return SearchBST(T->rchild,key,T,p); // ���������м����ݹ����
 }

 Status InsertBST(BiTree &T,ElemType e)
 { // ������������T��û�йؼ��ֵ���e.key��Ԫ�أ�����e������TRUE�����򷵻�FALSE���㷨9.6
   BiTree p,s;
   if(!SearchBST(T,e.key,NULL,p)) // ���Ҳ��ɹ���pָ�����·���Ϸ��ʵ����һ��Ҷ�ӽ��
   { s=(BiTree)malloc(sizeof(BiTNode)); // �����½��
     s->data=e; // ���½���������ֵ
     s->lchild=s->rchild=NULL; // ���½������Һ����򸳳�ֵ��
     if(!p) // ��T��
       T=s; // ������*sΪ�µĸ����
     else if LT(e.key,p->data.key) // ��T���գ�*s�Ĺؼ���С��*p�Ĺؼ���
       p->lchild=s; // ������*sΪp��ָ��������
     else // ��T���գ�*s�Ĺؼ��ִ���*p�Ĺؼ���
       p->rchild=s; // ������*sΪp��ָ����Һ���
     return TRUE;
   }
   else
     return FALSE; // �������йؼ�����ͬ�Ľ�㣬���ٲ���
 }

 void Delete(BiTree &p)
 { // �Ӷ�����������ɾ��p��ָ��㣬���ؽ�����������������㷨9.8
   BiTree s,q=p; // qָ���ɾ�����(�ᵽif���֮��)
   if(!p->rchild) // p������������ֻ���ؽ�����������(��ɾ�����Ҷ��Ҳ�ߴ˷�֧)
   { p=p->lchild; // pָ���ɾ����������
     free(q); // �ͷŴ�ɾ�����
   }
   else if(!p->lchild) // p���������գ�ֻ���ؽ�����������
   { p=p->rchild; // pָ���ɾ�������Һ���
     free(q); // �ͷŴ�ɾ�����
   }
   else // p����������������
   { s=p->lchild; // sָ���ɾ����������(s��pת��)
     while(s->rchild) // s���Һ���
     { q=s; // qָ��s
       s=s->rchild; // sָ��s���Һ���
     } // s���ҵ���ͷ(sָ���ɾ����ǰ����㣬qָ��s��˫�׽��)
     p->data=s->data; // ����ɾ���ǰ����ֵȡ����ɾ����ֵ
     if(q!=p) // ����٣���ɾ����������������
       q->rchild=s->lchild; // �ؽ�*q��������
     else // ����ڣ���ɾ��������û��������
       q->lchild=s->lchild; // �ؽ�*q��������
     free(s); // �ͷ�s��ָ���
   }
 }

 Status DeleteBST(BiTree &T,KeyType key)
 { // ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��
   // ������Ԫ�ؽ�㣬������TRUE�����򷵻�FALSE���㷨9.7
   if(!T) // ��T��
     return FALSE;
   else // ��T����
   { if EQ(key,T->data.key) // �ؼ��ֵ�����T�����Ĺؼ���
       Delete(T); // ɾ���ý��
     else if LT(key,T->data.key) // �ؼ���С��T��ָ���Ĺؼ���
       DeleteBST(T->lchild,key); // ��T�������еݹ����
     else // �ؼ��ִ���T��ָ���Ĺؼ���
       DeleteBST(T->rchild,key); // ��T���Һ����еݹ����
     return TRUE;
   }
 }
