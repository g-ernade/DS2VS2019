 // bo8-5.cpp ˫�������Ļ��������������㷨9.15
 void InitDSTable(DLTree &DT)
 { // �������������һ���յ�˫������DT
   DT=NULL;
 }

 void DestroyDSTable(DLTree &DT)
 { // ��ʼ������˫������DT���ڡ��������������DT
   if(DT) // �ǿ���
   { if(DT->kind==BRANCH) // *DT�Ƿ�֧���
       DestroyDSTable(DT->first); // �ݹ����ٺ�������
     DestroyDSTable(DT->next); // �ݹ������ֵ�����
     free(DT); // �ͷŸ����
     DT=NULL; // ��ָ�븳0
   }
 }

 Record* SearchDLTree(DLTree T,KeyType K)
 { // ��˫������T�в��ҹؼ��ִ�����K�ļ�¼�������ڣ�
   // �򷵻�ָ��ü�¼��ָ�룻���򷵻ؿ�ָ�롣�޸��㷨9.15
   DLTree p=T; // ��ʼ��
   int i=0;
   if(T) // ������
   { while(p&&i<K.num) // *p������δ�����һ���ַ�
     { while(p&&p->symbol!=K.ch[i]) // ���ҹؼ��ֵĵ�iλ
         p=p->next; // ˳�������ֵܽ���в���
       if(p&&i<K.num) // ׼��������һλ
         p=p->first; // pָ���ӽ��
       ++i; // �ؼ��������һλ
     } // ���ҽ���
     if(!p) // ���Ҳ��ɹ�
       return NULL;
     else // ���ҳɹ�
       return p->infoptr; // ����ָ��ü�¼��ָ��
   }
   else // ����
     return NULL;
 }

 void InsertDSTable(DLTree &DT,Record* r)
 { // ��ʼ������˫������DT���ڣ�rΪ�����������Ԫ�ص�ָ��
   // �����������DT�в�������ؼ��ִ�����(*r).key.ch������Ԫ�أ��򰴹ؼ���˳���r��DT��
   DLTree p=NULL,q,ap;
   int i=0;
   KeyType K=r->key;
   if(!DT&&K.num) // �����ҹؼ��ַ����ǿ�
   { DT=ap=(DLTree)malloc(sizeof(DLTNode)); // ��̬���ɸ����
     for(;i<K.num;i++) // �����֧���
     { if(p) // p����(���ǵ�һ�����ɽ��)
         p->first=ap; // p�ĺ���ָ��ָ�������ɵĽ��
       ap->next=NULL; // ���ֵ�Ϊ��
       ap->symbol=K.ch[i]; // �ؼ��ַ�Ϊ��ǰλ�ؼ���
       ap->kind=BRANCH; // �������Ϊ��֧
       p=ap; // pָ��ap
       ap=(DLTree)malloc(sizeof(DLTNode)); // ��̬���ɺ��ӽ��
     }
     p->first=ap; // ����Ҷ�ӽ��
     ap->next=NULL; // Ҷ�ӽ������ֵ�Ϊ��
     ap->symbol=Nil; // Ҷ�ӽ��Ĺؼ��ַ�Ϊ��
     ap->kind=LEAF; // �������ΪҶ��
     ap->infoptr=r; // ��¼ָ��ָ��ؼ��ִ����ڼ�¼
   }
   else // �ǿ���
   { p=DT; // ָ������
     while(p&&i<K.num) // *p������iС�ڹؼ��ִ��ĳ���
     { while(p&&p->symbol<K.ch[i]) // �����ֵܽ����ҵ�ǰ�ؼ��ַ�
       { q=p; // qָ��ǰ���
         p=p->next; // pָ��ǰ�������ֵܽ��
       }
       if(p&&p->symbol==K.ch[i]) // �ҵ���K.ch[i]����Ľ��
       { q=p; // qָ��ǰ���
         p=p->first; // pָ����K.ch[i+1]�ȽϵĽ��(���ӽ��)
         ++i; // �ؼ��������һλ
       }
       else // δ�ҵ���K.ch[i]����Ľ�㣬����ؼ���
       { ap=(DLTree)malloc(sizeof(DLTNode)); // ��̬���ɽ��
         if(q->first==p)
           q->first=ap; // �ڳ��ӵ�λ�ò���
         else // q->next==p
           q->next=ap; // �����ֵܵ�λ�ò���
         ap->next=p; // ���ֵ�Ϊp
         ap->symbol=K.ch[i]; // �ؼ��ַ�Ϊ��ǰλ�ؼ���
         ap->kind=BRANCH; // �������Ϊ��֧
         p=ap; // pָ��ap
         ap=(DLTree)malloc(sizeof(DLTNode)); // ��̬���ɽ��
         i++; // �ؼ��������һλ
         for(;i<K.num;i++) // �����֧���
         { p->first=ap; // �ڳ��ӵ�λ�ò���
           ap->next=NULL; // ���ֵ�Ϊ��
           ap->symbol=K.ch[i]; // �ؼ��ַ�Ϊ��ǰλ�ؼ���
           ap->kind=BRANCH; // �������Ϊ��֧
           p=ap; // pָ��ap
           ap=(DLTree)malloc(sizeof(DLTNode)); // ��̬���ɺ��ӽ��
         }
         p->first=ap; // ����Ҷ�ӽ��
         ap->next=NULL; // Ҷ�ӽ������ֵ�Ϊ��
         ap->symbol=Nil; // Ҷ�ӽ��Ĺؼ��ַ�Ϊ��
         ap->kind=LEAF; // �������ΪҶ��
         ap->infoptr=r; // ��¼ָ��ָ��ؼ��ִ����ڼ�¼
       }
     }
   }
 }

 struct SElemType // ����ջԪ������
 { char ch;
   DLTree p;
 };
 #include"c3-1.h" // ˳��ջ
 #include"bo3-1.cpp" // ˳��ջ�Ļ�������
 void TraverseDSTable(DLTree DT,void(*Visit)(Record*))
 { // ��ʼ������˫������DT���ڣ�Visit�ǶԼ�¼������Ӧ�ú���
   // ������������ؼ��ֵ�˳������ؼ��ּ����Ӧ�ļ�¼
   SqStack s;
   SElemType e;
   DLTree p;
   int i=0,n=9; // ���n��Ԫ�غ���
   if(DT) // ���ǿ�
   { InitStack(s); // ��ʼ��ջ
     e.p=DT; // ����������Ϣ����e
     e.ch=DT->symbol;
     Push(s,e); // ��e��ջ
     p=DT->first; // pָ������ĳ���
     while(p->kind==BRANCH) // p�Ƿ�֧���
     { e.p=p; // �����p����Ϣ����e
       e.ch=p->symbol;
       Push(s,e); // ��e��ջ
       p=p->first; // pָ��p�ĳ���
     }
     e.p=p; // �����p����Ϣ����e
     e.ch=p->symbol;
     Push(s,e); // ��e��ջ
     Visit(p->infoptr); // ����Ҷ�ӽ��ļ�¼
     i++; // ������+1
     while(!StackEmpty(s)) // ջ����
     { Pop(s,e); // ����ջ��Ԫ��
       p=e.p; // ջԪ��ָ�븳p
       if(p->next) // p�����ֵܽ��
       { p=p->next; // pָ��p�����ֵ�
         while(p->kind==BRANCH) // p�Ƿ�֧���
         { e.p=p; // �����p����Ϣ����e
           e.ch=p->symbol;
           Push(s,e); // ��e��ջ
           p=p->first; // pָ��p�ĳ���
         }
         e.p=p; // �����p����Ϣ����e
         e.ch=p->symbol;
         Push(s,e); // ��e��ջ
         Visit(p->infoptr); // ����Ҷ�ӽ��ļ�¼
         i++; // ������+1
         if(i%n==0)
           printf("\n"); // ���n��Ԫ�غ���
       }
     }
   }
 }
