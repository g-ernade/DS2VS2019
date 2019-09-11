 // bo6-5.cpp ���Ķ�������(����-�ֵ�)�洢(�洢�ṹ��c6-4.h����)�Ļ�������(16��)
 #define ClearTree DestroyTree // ���߲�����ͬ
 void InitTree(CSTree &T)
 { // ����������������T
   T=NULL;
 }

 void DestroyTree(CSTree &T)
 { // ��ʼ��������T���ڡ����������������T
   if(T) // �ǿ���
   { DestroyTree(T->firstchild); // �ݹ�����T�ĳ���Ϊ����������
     DestroyTree(T->nextsibling); // �ݹ�����T����һ���ֵ�Ϊ����������
     free(T); // �ͷŸ����
     T=NULL; // ��ָ�븳0
   }
 }

 typedef CSTree QElemType; // �������Ԫ������Ϊ����-�ֵܶ��������ָ������
 #include"c3-2.h" // ����LinkQueue����(������)
 #include"bo3-2.cpp" // LinkQueue���͵Ļ�������
 void CreateTree(CSTree &T)
 { // ������T
   char c[20]; // ��ʱ��ź��ӽ��(�費����20��)��ֵ
   CSTree p,p1;
   LinkQueue q;
   int i,m;
   InitQueue(q); // ��ʼ������q
   printf("����������(�ַ��ͣ��ո�Ϊ��)��");
   scanf("%c%*c",&c[0]); // ���������ֵ
   if(c[0]!=Nil) // �ǿ���
   { T=(CSTree)malloc(sizeof(CSNode)); // ���������
     T->data=c[0]; // ������㸳ֵ
     T->nextsibling=NULL; // �����û����һ���ֵ�
     EnQueue(q,T); // ��Ӹ�����ָ��
     while(!QueueEmpty(q)) // �Ӳ���
     { DeQueue(q,p); // ����һ������ָ��
       printf("�밴����˳��������%c�����к��ӣ�",p->data);
       gets(c); // ���������к�����Ϊ�ַ�������
       m=strlen(c);
       if(m>0) // �к���
       { p1=p->firstchild=(CSTree)malloc(sizeof(CSNode)); // �������ӽ��
         p1->data=c[0]; // �����ӽ�㸳ֵ
         EnQueue(q,p1); // ���p1����ָ��
         for(i=1;i<m;i++) // ���ڳ�����֮�����������
         { p1->nextsibling=(CSTree)malloc(sizeof(CSNode)); // ������һ���ֵܽ��
           p1=p1->nextsibling; // p1ָ����һ���ֵܽ��
           p1->data=c[i]; // ��p1��ָ��㸳ֵ
           EnQueue(q,p1); // ���p1����ָ��
         }
         p1->nextsibling=NULL; // ���һ�����û����һ���ֵ�
       }
       else // �޺���
         p->firstchild=NULL; // ����ָ��Ϊ��
     }
   }
   else
     T=NULL; // ����
 }

 Status TreeEmpty(CSTree T)
 { // ��ʼ��������T���ڡ������������TΪ�������򷵻�TURE�����򷵻�FALSE
   if(T) // T����
     return FALSE;
   else
     return TRUE;
 }

 int TreeDepth(CSTree T)
 { // ��ʼ��������T���ڡ��������������T�����
   CSTree p;
   int depth,max=0;
   if(!T) // ����
     return 0;
   for(p=T->firstchild;p;p=p->nextsibling) // ������T���������к��ӽ��(��pָ��)
   { // ��������ȵ����ֵ
     depth=TreeDepth(p); // �ݹ����ӽ������depth
     if(depth>max) // ����ӽ�����ȴ�max
       max=depth;
   }
   return max+1; // �������=����������ֵ+1
 }

 TElemType Value(CSTree p)
 { // ����p��ָ����ֵ
   return p->data;
 }

 TElemType Root(CSTree T)
 { // ��ʼ��������T���ڡ��������������T�ĸ�
   if(T)
     return Value(T);
   else
     return Nil;
 }

 CSTree Point(CSTree T,TElemType s)
 { // ���ض�������(����-�ֵ�)��T��ָ��Ԫ��ֵΪs�Ľ���ָ�롣����
   LinkQueue q;
   QElemType a;
   if(T) // �ǿ���
   { InitQueue(q); // ��ʼ������
     EnQueue(q,T); // ��������
     while(!QueueEmpty(q)) // �Ӳ���
     { DeQueue(q,a); // ���ӣ�����Ԫ�ظ���a
       if(a->data==s) // �ҵ�Ԫ��ֵΪs�Ľ��
         return a; // ����ָ�����ָ��
       if(a->firstchild) // �г���
         EnQueue(q,a->firstchild); // ��ӳ���
       if(a->nextsibling) // ����һ���ֵ�
         EnQueue(q,a->nextsibling); // �����һ���ֵ�
     }
   }
   return NULL;
 }

 Status Assign(CSTree &T,TElemType cur_e,TElemType value)
 { // ��ʼ��������T���ڣ�cur_e����T�н���ֵ�������������cur_eΪvalue
   CSTree p;
   if(T) // �ǿ���
   { p=Point(T,cur_e); // pΪcur_e��ָ��
     if(p) // �ҵ�cur_e
     { p->data=value; // ����ֵ
       return OK;
     }
   }
   return ERROR; // ���ջ�δ�ҵ�
 }

 TElemType Parent(CSTree T,TElemType cur_e)
 { // ��ʼ��������T���ڣ�cur_e��T��ĳ�����
   // �����������cur_e��T�ķǸ���㣬�򷵻�����˫�ף�������ֵΪ���ա�
   CSTree p,t;
   LinkQueue q;
   InitQueue(q); // ��ʼ������q
   if(T) // ���ǿ�
   { if(Value(T)==cur_e) // �����ֵΪcur_e
       return Nil;
     EnQueue(q,T); // ��������
     while(!QueueEmpty(q)) // ���в���
     { DeQueue(q,p); // ����Ԫ��(ָ��)����p
       if(p->firstchild) // p�г���
       { if(p->firstchild->data==cur_e) // ����Ϊcur_e
           return Value(p); // ����˫�׵�ֵ
         t=p; // ˫��ָ�븳��t
         p=p->firstchild; // pָ����
         EnQueue(q,p); // ��ӳ���
         while(p->nextsibling) // ����һ���ֵ�
         { p=p->nextsibling; // pָ����һ���ֵ�
           if(Value(p)==cur_e) // ��һ���ֵ�Ϊcur_e
             return Value(t); // ����˫�׵�ֵ
           EnQueue(q,p); // �����һ���ֵ�
         }
       }
     }
   }
   return Nil; // ���ջ�δ�ҵ�cur_e
 }

 TElemType LeftChild(CSTree T,TElemType cur_e)
 { // ��ʼ��������T���ڣ�cur_e��T��ĳ�����
   // �����������cur_e��T�ķ�Ҷ�ӽ�㣬�򷵻����������ӣ����򷵻ء��ա�
   CSTree f;
   f=Point(T,cur_e); // fָ����cur_e
   if(f&&f->firstchild) // �ҵ����cur_e�ҽ��cur_e�г���
     return f->firstchild->data; // ���ؽ��cur_e�ĳ��ӵ�ֵ
   else
     return Nil; // ���ؿ�
 }

 TElemType RightSibling(CSTree T,TElemType cur_e)
 { // ��ʼ��������T���ڣ�cur_e��T��ĳ�����
   // �����������cur_e�����ֵܣ��򷵻��������ֵܣ����򷵻ء��ա�
   CSTree f;
   f=Point(T,cur_e); // fָ����cur_e
   if(f&&f->nextsibling) // �ҵ����cur_e�ҽ��cur_e�����ֵ�
     return f->nextsibling->data; // ���ؽ��cur_e�����ֵܵ�ֵ
   else
     return Nil; // ���ؿ�
 }

 Status InsertChild(CSTree &T,CSTree p,int i,CSTree c)
 { // ��ʼ��������T���ڣ�pָ��T��ĳ����㣬1��i��p��ָ���Ķ�+1���ǿ���c��T���ཻ
   // �������������cΪT��p���ĵ�i����������Ϊp��ָ���ĵ�ַ����ı䣬
   //           ��p����Ҫ����������
   int j;
   CSTree q;
   if(T) // T����
   { if(i==1) // ����cΪp�ĳ���
     { c->nextsibling=p->firstchild; // p��ԭ��������c����һ���ֵ�(c�����ֵ�)
       p->firstchild=c; // p�ĳ���ָ��ָ��c(c��Ϊp�ĳ���)
     }
     else // c����p�ĳ���
     { q=p->firstchild; // qָ��p�ĳ��ӽ��
       j=2;
       while(q&&j<i) // ��c�Ĳ���㣬����qָ��
       { q=q->nextsibling; // qָ����һ���ֵܽ��
         j++; // ����+1
       }
       if(j==i) // �ҵ�����λ��
       { c->nextsibling=q->nextsibling; // c����һ���ֵ�ָ��p��ԭ��i������
         q->nextsibling=c; // ��p�в���c��Ϊp�ĵ�i������
       }
       else // pԭ�к�����С��i-1
         return ERROR;
     }
     return OK;
   }
   else // T��
     return ERROR;
 }

 Status DeleteChild(CSTree &T,CSTree p,int i)
 { // ��ʼ��������T���ڣ�pָ��T��ĳ����㣬1��i��p��ָ���Ķ�
   // ���������ɾ��T��p��ָ���ĵ�i��������
   //           ��Ϊp��ָ���ĵ�ַ����ı䣬��p����Ҫ����������
   CSTree b,q;
   int j;
   if(T) // T����
   { if(i==1) // ɾ������
     { // �ѳ��ӽ��������p�з������
       b=p->firstchild; // bָ��p�ĳ��ӽ��
       p->firstchild=b->nextsibling; // p��ԭ�������ǳ���
       b->nextsibling=NULL; // p�ĳ��ӽ���Ϊ��ɾ�������ĸ���㣬����һ���ֵ�ָ��Ϊ��
       DestroyTree(b); // ������bָ���p�ĳ��ӽ������
     }
     else // ɾ���ǳ���
     { q=p->firstchild; // qָ��p�ĳ��ӽ��
       j=2;
       while(q&&j<i) // �ҵ�i������
       { q=q->nextsibling; // qָ����һ���ֵܽ��
         j++; // ����+1
       }
       if(j==i) // �ҵ���i������
       { b=q->nextsibling; // bָ���ɾ������
         q->nextsibling=b->nextsibling; // ����p��ɾ���������
         b->nextsibling=NULL; // ��ɾ�������ĸ�������һ���ֵ�ָ��Ϊ��
         DestroyTree(b); // ������bָ���p�ĳ��ӽ������
       }
       else // pԭ�к�����С��i
         return ERROR;
     }
     return OK;
   }
   else
     return ERROR;
 }

 void PostOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { // �����������-�ֵܶ�������ṹ����T
   CSTree p;
   if(T)
   { if(T->firstchild) // �г���
     { PostOrderTraverse(T->firstchild,Visit); // ���������������
       p=T->firstchild->nextsibling; // pָ���ӵ���һ���ֵ�
       while(p) // ������һ���ֵ�
       { PostOrderTraverse(p,Visit); // ���������һ���ֵ�����
         p=p->nextsibling; // pָ������һ���ֵ�
       }
     }
     Visit(Value(T)); // �����ʸ����
   }
 }

 void LevelOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { // �����������-�ֵܶ�������ṹ����T
   CSTree p;
   LinkQueue q;
   InitQueue(q); // ��ʼ������q
   if(T) // ���ǿ�
   { Visit(Value(T)); // �ȷ��ʸ����
     EnQueue(q,T); // ��Ӹ�����ָ��
     while(!QueueEmpty(q)) // �Ӳ���
     { DeQueue(q,p); // ����һ������ָ��
       if(p->firstchild) // �г���
       { p=p->firstchild; // pָ���ӽ��
         Visit(Value(p)); // ���ʳ��ӽ��
         EnQueue(q,p); // ��ӳ��ӽ���ָ��
         while(p->nextsibling) // ����һ���ֵ�
         { p=p->nextsibling; // pָ����һ���ֵܽ��
           Visit(Value(p)); // ������һ���ֵ�
           EnQueue(q,p); // ����ֵܽ���ָ��
         }
       }
     }
   }
   printf("\n");
 }
