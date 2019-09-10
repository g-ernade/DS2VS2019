 // bo5-6.cpp ��������չ��������洢(�洢�ṹ��c5-5.h����)�Ļ�������(12��)
 #include"func5-3.cpp" // �㷨5.8

 void InitGList(GList1 &L)
 { // �����յĹ����L
   L=(GList1)malloc(sizeof(GLNode1)); // ����ͷ���
   L->tag=LIST; // ����ͷ���ı�־��ֵ
   L->hp=L->tp=NULL; // ����ͷ����ָ����ֵ
 }

 void Create(GList1 &L,SString S)
 { // �ɹ�������д��ʽ��S�����ӱ�L��CreateGList()����
   SString emp,sub,hsub;
   GList1 p;
   StrAssign(emp,"()"); // ��emp="()"
   if(!(L=(GList1)malloc(sizeof(GLNode1)))) // �����㲻�ɹ�
     exit(OVERFLOW);
   if(!StrCompare(S,emp)) // �����ձ�
   { L->tag=LIST; // ��Ȼ�Ǳ�
     L->hp=NULL; // �ǿձ�
   }
   else if(StrLength(S)==1) // ������ԭ�ӹ����
   { L->tag=ATOM; // �����ı�־��ֵ
     L->atom=S[1]; // ������ֵ��ֵ
   }
   else // �ݹ鴴���ӱ�
   { L->tag=LIST; // �Ǳ�
     SubString(sub,S,2,StrLength(S)-2);
     // ���������(ȥ����1���ַ�(������)�����1���ַ�(������))����sub
     sever(sub,hsub); // ��sub�з������ͷ��hsub(��㶺��֮ǰ��)����β������sub
     Create(L->hp,hsub); // �����ӱ�ı�ͷԪ��
     p=L->hp; // pָ���ӱ�ı�ͷԪ��
     while(!StrEmpty(sub)) // ��β���գ����ظ���n���ӱ�
     { sever(sub,hsub); // ��sub�з������ͷ��hsub
       Create(p->tp,hsub); // ���δ����ӱ�
       p=p->tp; // p�����
     }
   }
   L->tp=NULL; // βָ��Ϊ��
 }

 void CreateGList(GList1 &L,SString S) // �޸��㷨5.7
 { // ������չ��������洢�ṹ���ɹ�������д��ʽ��S���������L��L���Ϊ�յĹ����
   SString emp,sub,hsub;
   GList1 p;
   StrAssign(emp,"()"); // ��emp="()"
   if(!StrCompare(S,emp)) // S="()"
     InitGList(L); // �����ձ�
   else // S���ǿմ�
   { SubString(sub,S,2,StrLength(S)-2);
     // ���������(ȥ����1���ַ�(������)�����һ���ַ�(������))����sub
     sever(sub,hsub); // ��sub�з������ͷ��hsub(��㶺��֮ǰ��)����β������sub
     Create(L->hp,hsub); // ������ͷԪ��
     p=L->hp; // pָ���1��Ԫ��
     while(!StrEmpty(sub)) // ��β���գ�����������ӱ�
     { sever(sub,hsub); // ��sub�з������ǰ��Ĵ���hsub�����ಿ�ָ���sub
       Create(p->tp,hsub); // ���δ����ӱ�
       p=p->tp; // p�����
     }
     p->tp=NULL; // ���һ��Ԫ�ص�βָ��Ϊ��
   }
 }

 void DestroyGList(GList1 &L)
 { // ��ʼ�����������L���ڡ�������������ٹ����L
   GList1 ph,pt;
   if(L) // L����
   { // ��ph��pt����L������ָ��
     if(L->tag) // ���ӱ�
       ph=L->hp;
     else // ��ԭ��
       ph=NULL;
     pt=L->tp;
     DestroyGList(ph); // �ݹ����ٱ�ph
     DestroyGList(pt); // �ݹ����ٱ�pt
     free(L); // �ͷ�L��ָ���
     L=NULL; // ��LΪ��
   }
 }

 void CopyGList(GList1 &T,GList1 L)
 { // ��ʼ�����������L���ڡ�����������ɹ����L���Ƶõ������T
   T=NULL;
   if(L) // L����
   { T=(GList1)malloc(sizeof(GLNode1));
     if(!T)
       exit(OVERFLOW);
     T->tag=L->tag; // ����ö�ٱ���
     if(L->tag==ATOM) // ���ƹ����岿��
       T->atom=L->atom; // ���Ƶ�ԭ��
     else
       CopyGList(T->hp,L->hp); // �����ӱ�
     if(L->tp==NULL) // ����β
       T->tp=L->tp;
     else
       CopyGList(T->tp,L->tp); // �����ӱ�
   }
 }

 int GListLength(GList1 L)
 { // ��ʼ�����������L���ڡ����������������L�ĳ��ȣ���Ԫ�ظ���
   int len=0;
   GList1 p=L->hp; // pָ���1��Ԫ��
   while(p)
   { len++;
     p=p->tp;
   };
   return len;
 }

 int GListDepth(GList1 L)
 { // ��ʼ�����������L���ڡ����������������L�����
   int max=0,dep;
   GList1 p;
   if(L->tag==LIST&&!L->hp)
     return 1; // �ձ����Ϊ1
   else if(L->tag==ATOM)
     return 0; // ��ԭ�ӱ����Ϊ0��ֻ������ڵݹ������
   else // ��һ�������
     for(p=L->hp;p;p=p->tp)
     { dep=GListDepth(p); // ����pΪͷָ����ӱ����
       if(dep>max)
         max=dep;
     }
   return max+1; // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
 }

 Status GListEmpty(GList1 L)
 { // ��ʼ�����������L���ڡ�����������ж������L�Ƿ�Ϊ��
   if(!L->hp)
     return OK;
   else
     return ERROR;
 }

 GList1 GetHead(GList1 L)
 { // ��ʼ�����������L���ڡ�������������ɹ����L�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
   GList1 h,p;
   if(!L->hp) // �ձ��ޱ�ͷ
     return NULL;
   p=L->hp->tp; // pָ��L�ı�β
   L->hp->tp=NULL; // ��ȥL�ı�β����
   CopyGList(h,L->hp); // ����ͷԪ�ظ��Ƹ�h
   L->hp->tp=p; // �ָ�L�ı�β(����ԭL����)
   return h;
 }

 GList1 GetTail(GList1 L)
 { // ��ʼ�����������L���ڡ������������L�ı�β����Ϊ���������ָ������¹�����ָ��
   GList1 t;
   InitGList(t); // �����յĹ����t
   if(L->hp) // L�ǿ�
     CopyGList(t->hp,L->hp->tp); // ��L�ı�β���Ƹ�t�ı�ͷ
   return t;
 }

 void InsertFirst_GL(GList1 &L,GList1 e)
 { // ��ʼ�����������L���ڡ��������������Ԫ��e(Ҳ�������ӱ�)��ΪL�ĵ�1��Ԫ��(��ͷ)
   GList1 p=L->hp; // pָ������L�ĵ�1��Ԫ��
   L->hp=e; // �����L��ͷָ��ָ��e
   e->tp=p; // e(ֻ��1��Ԫ�أ���βָ���ΪNULL)��βָ��ָ��Lԭ���ĵ�1��Ԫ��
 }

 void DeleteFirst_GL(GList1 &L,GList1 &e)
 { // ��ʼ�����������L���ڡ����������ɾ�������L�ĵ�1��Ԫ�أ�����e������ָ��
   e=L->hp; // eָ��L�ĵ�1��Ԫ��
   if(L->hp) // L�ǿ�
   { L->hp=e->tp; // L��ͷָ��ָ��ԭ��2��Ԫ��
     e->tp=NULL; // e��βָ����Ϊ��
   }
 }

 void Traverse_GL(GList1 L,void(*visit)(AtomType))
 { // ���õݹ��㷨���������L
   if(L) // L����
   { if(L->tag==ATOM) // LΪ��ԭ��
       visit(L->atom); // ���ʵ�ԭ��
     else // LΪ�ӱ�
       Traverse_GL(L->hp,visit); // ����L->hp�ӱ�
     Traverse_GL(L->tp,visit); // ����L->tp�ӱ�
   }
 }
