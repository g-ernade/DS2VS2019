 // bo5-5.cpp ������ͷβ����洢�ṹ(��c5-4.h����)�Ļ�������(12��)�������㷨5.5��5.7
 #include"func5-3.cpp" // �㷨5.8
 void InitGList(GList &L)
 { // �����յĹ����L
   L=NULL;
 }

 void CreateGList(GList &L,SString S) // �㷨5.7
 { // ����ͷβ����洢�ṹ���ɹ�������д��ʽ��S���������L����emp="()"
   SString sub,hsub,emp;
   GList p,q;
   StrAssign(emp,"()"); // �մ�emp="()"
   if(!StrCompare(S,emp)) // S="()"
     L=NULL; // �����ձ�
   else // S���ǿմ�
   { if(!(L=(GList)malloc(sizeof(GLNode)))) // ������
       exit(OVERFLOW);
     if(StrLength(S)==1) // SΪ��ԭ�ӣ��������ֻ������ڵݹ������
     { L->tag=ATOM; // ������ԭ�ӹ����
       L->atom=S[1]; // ��ԭ�ӵ�ֵΪ�ַ���
     }
     else // SΪ��
     { L->tag=LIST; // L���ӱ�
       p=L; // pҲָ���ӱ�
       SubString(sub,S,2,StrLength(S)-2);
       // ���������(ȥ����1���ַ�(������)�����1���ַ�(������))����sub
       do // �ظ���n���ӱ�
       { sever(sub,hsub); // ��sub�з������ͷ����hsub�����ಿ��(��β)��sub
         CreateGList(p->ptr.hp,hsub); // �ݹ鴴����ͷ����ʾ���ӱ�
         q=p; // qָ��p��ָ���
         if(!StrEmpty(sub)) // ��β����
         { if(!(p=(GLNode*)malloc(sizeof(GLNode)))) // ��p��������
             exit(OVERFLOW);
           p->tag=LIST; // p���ӱ�
           q->ptr.tp=p; // p��ָ������q��ָ���֮���γ�q����һ�����
         }
       }while(!StrEmpty(sub)); // ����β����
       q->ptr.tp=NULL; // �������һ����βָ��Ϊ��
     }
   }
 }

 void DestroyGList(GList &L)
 { // ���ٹ����L
   GList q1,q2;
   if(L) // �����L����
   { if(L->tag==LIST) // Ҫɾ�����Ǳ���
     { q1=L->ptr.hp; // q1ָ���ͷ
       q2=L->ptr.tp; // q2ָ���β(����ͷ֮������ಿ��)
       DestroyGList(q1); // �ݹ����ٱ�ͷ
       DestroyGList(q2); // �ݹ����ٱ�β
     }
     free(L); // �ͷ�L��ָ�Ĵ洢�ռ�(����L�Ǳ��㻹��ԭ�ӽ��)
     L=NULL; // L��ָ���κδ洢��Ԫ
   }
 }

 void CopyGList(GList &T,GList L)
 { // ����ͷβ����洢�ṹ���ɹ����L���Ƶõ������T���㷨5.6
   if(!L) // ���ƿձ�
     T=NULL;
   else // �����L����
   { T=(GList)malloc(sizeof(GLNode)); // ������
     if(!T)
       exit(OVERFLOW);
     T->tag=L->tag; // ���Ʊ�־��
     if(L->tag==ATOM) // ��ԭ��
       T->atom=L->atom; // ���Ƶ�ԭ��
     else // �ӱ�
     { CopyGList(T->ptr.hp,L->ptr.hp); // �ݹ鸴�Ʊ�ͷ�ӱ�
       CopyGList(T->ptr.tp,L->ptr.tp); // �ݹ鸴�Ʊ�β(����ͷ֮��Ĳ���)�ӱ�
     }
   }
 }

 int GListLength(GList L)
 { // ���ع����ĳ��ȣ���Ԫ�ظ���
   int len=0; // ���ù�����ȵĳ�ֵΪ0
   while(L) // δ����β
   { L=L->ptr.tp; // Lָ��������������һ��Ԫ��
     len++; // ��+1
   }
   return len;
 }

 int GListDepth(GList L)
 { // ����ͷβ����洢�ṹ��������L����ȡ��㷨5.5
   int dep,max=0;
   GList pp;
   if(!L) // �����LΪ��
     return 1; // �ձ����Ϊ1
   if(L->tag==ATOM) // ��ԭ�ӽ��
     return 0; // ԭ�����Ϊ0��ֻ������ڵݹ������
   for(pp=L;pp;pp=pp->ptr.tp) // �ӱ���ĵ�1��Ԫ�ص����һ��Ԫ��
   { dep=GListDepth(pp->ptr.hp); // �ݹ�����pp->ptr.hpΪͷָ����ӱ����
     if(dep>max)
       max=dep; // max�汾���ӱ���ȵ����ֵ
   }
   return max+1; // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
 }

 Status GListEmpty(GList L)
 { // �ж�������Ƿ�Ϊ��
   if(!L)
     return TRUE;
   else
     return FALSE;
 }

 GList GetHead(GList L)
 { // ���ɹ����L�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
   GList h;
   if(!L) // �ձ��ޱ�ͷ
     return NULL;
   CopyGList(h,L->ptr.hp); // ��L�ı�ͷԪ�ظ��Ƹ�h
   return h;
 }

 GList GetTail(GList L)
 { // �������L�ı�β(����ͷ֮��Ĳ���)����Ϊ���������ָ������¹�����ָ��
   GList t;
   if(!L) // �ձ��ޱ�β
     return NULL;
   CopyGList(t,L->ptr.tp); // ��L�ı�βԪ�ظ��Ƹ�t
   return t;
 }

 void InsertFirst_GL(GList &L,GList e)
 { // ��ʼ�����������L���ڡ��������������Ԫ��e(Ҳ�������ӱ�)��Ϊ�����L�ĵ�1��Ԫ��(��ͷ)
   GList p=(GList)malloc(sizeof(GLNode)); // �����µı�ͷ���
   if(!p)
     exit(OVERFLOW);
   p->tag=LIST; // �����L�������Ǳ�
   p->ptr.hp=e; // L�ı�ͷָ��ָ��e
   p->ptr.tp=L; // L�ı�βָ��ָ��ԭ��L
   L=p; // Lָ���µı�ͷ���
 }

 void DeleteFirst_GL(GList &L,GList &e)
 { // ��ʼ�����������L���ڡ����������ɾ�������L�ĵ�1��Ԫ��(��ͷ)������e������ֵ
   GList p=L; // pָ���1������
   e=L->ptr.hp; // eָ��L�ı�ͷԪ��
   L=L->ptr.tp; // Lָ��ԭL�ı�β(����ͷ֮��Ĳ���)
   free(p); // �ͷ�p��ָ�ı���
 }

 void Traverse_GL(GList L,void(*visit)(AtomType))
 { // ���õݹ��㷨���������L
   if(L) // L����
     if(L->tag==ATOM) // LΪ��ԭ��
       visit(L->atom);
     else // LΪ�����
     { Traverse_GL(L->ptr.hp,visit); // �ݹ����L�ı�ͷ
       Traverse_GL(L->ptr.tp,visit); // �ݹ����L�ı�β
     }
 }

