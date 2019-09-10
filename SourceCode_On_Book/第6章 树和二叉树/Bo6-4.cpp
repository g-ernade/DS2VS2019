 // bo6-4.cpp ����������������11�����������������㷨6.5��6.7
 void CreateBiThrTree(BiThrTree &T)
 { // ���������������������н���ֵ����������������T��0(����)/�ո�(�ַ���)��ʾ�ս��
   TElemType ch;
   scanf(form,&ch); // �������ֵ
   if(ch==Nil) // ����ֵΪ��
     T=NULL;
   else // ����ֵ��Ϊ��
   { T=(BiThrTree)malloc(sizeof(BiThrNode)); // ���ɸ����(����)
     if(!T)
       exit(OVERFLOW);
     T->data=ch; // ��ֵ����T��ָ���
     CreateBiThrTree(T->lchild); // �ݹ鹹��������
     if(T->lchild) // ������
       T->LTag=Link; // �����־��ֵ(ָ��)
     CreateBiThrTree(T->rchild); // �ݹ鹹��������
     if(T->rchild) // ���Һ���
       T->RTag=Link; // ���ұ�־��ֵ(ָ��)
   }
 }

 BiThrTree pre; // ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
 void InThreading(BiThrTree p)
 { // ͨ�������������������������������֮��preָ�����һ����㡣�㷨6.7
   if(p) // ��������������
   { InThreading(p->lchild); // �ݹ�������������
     if(!p->lchild) // û������
     { p->LTag=Thread; // ���־Ϊ����(ǰ��)
       p->lchild=pre; // ����ָ��ָ��ǰ��
     }
     if(!pre->rchild) // ǰ��û���Һ���
     { pre->RTag=Thread; // ǰ�����ұ�־Ϊ����(���)
       pre->rchild=p; // ǰ���Һ���ָ��ָ������(��ǰ���p)
     }
     pre=p; // ����preָ��p��ǰ��
     InThreading(p->rchild); // �ݹ�������������
   }
 }

 void InOrderThreading(BiThrTree &Thrt,BiThrTree T)
 { // �������������T��������������������Thrtָ��ͷ��㡣�㷨6.6
   if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) // ����ͷ��㲻�ɹ�
     exit(OVERFLOW);
   Thrt->LTag=Link; // ��ͷ��㣬���־Ϊָ��
   Thrt->RTag=Thread; // �ұ�־Ϊ����
   Thrt->rchild=Thrt; // �Һ���ָ���ָ
   if(!T) // ��������T�գ�������ָ���ָ
     Thrt->lchild=Thrt;
   else // ������T�ǿ�
   { Thrt->lchild=T; // ͷ��������ָ��ָ������
     pre=Thrt; // pre(ǰ��)�ĳ�ֵָ��ͷ���
     InThreading(T); // �����������������������preָ��������������һ�����
     pre->rchild=Thrt; // ���һ�������Һ���ָ��ָ��ͷ���
     pre->RTag=Thread; // ���һ�������ұ�־Ϊ����
     Thrt->rchild=pre; // ͷ�����Һ���ָ��ָ��������������һ�����
   }
 }

 void InOrderTraverse_Thr(BiThrTree T,void(*Visit)(TElemType))
 { // �����������������T(ͷ���)�ķǵݹ��㷨���㷨6.5
   BiThrTree p;
   p=T->lchild; // pָ������
   while(p!=T)
   { // �������������ʱ��p==T
     while(p->LTag==Link) // �ɸ����һֱ�ҵ���������������
       p=p->lchild; // pָ��������
     Visit(p->data); // ���ʴ˽��
     while(p->RTag==Thread&&p->rchild!=T)
     { // p->rchild������(���)���Ҳ��Ǳ��������һ�����
       p=p->rchild; // pָ������
       Visit(p->data); // ���ʺ�̽��
     }
     // ��p->rchild��������(���Һ���)��pָ���Һ��ӣ�����ѭ���������������������ĵ�1�����
     p=p->rchild;
   }
 }

 void PreThreading(BiThrTree p)
 { // PreOrderThreading()���õĵݹ麯��
   if(!pre->rchild) // p��ǰ��û���Һ���
   { pre->RTag=Thread; // pre���Һ���ָ��Ϊ����
     pre->rchild=p; // pǰ���ĺ��ָ��p
   }
   if(!p->lchild) // pû������
   { p->LTag=Thread; // p������ָ��Ϊ����
     p->lchild=pre; // p������ָ��ָ��ǰ��
   }
   pre=p; // �ƶ�ǰ��
   if(p->LTag==Link) // p������
     PreThreading(p->lchild); // ��p�����ӵݹ����preThreading()
   if(p->RTag==Link) // p���Һ���
     PreThreading(p->rchild); // ��p���Һ��ӵݹ����preThreading()
 }

 void PreOrderThreading(BiThrTree &Thrt,BiThrTree T)
 { // ����������������T��ͷ�����Һ���ָ��ָ��������������1�����
   if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) // ����ͷ���
     exit(OVERFLOW);
   Thrt->LTag=Link; // ͷ��������ָ��Ϊ����
   Thrt->RTag=Thread; // ͷ�����Һ���ָ��Ϊ����
   Thrt->rchild=Thrt; // ͷ�����Һ���ָ��ָ������
   if(!T) // ����
     Thrt->lchild=Thrt; // ͷ��������ָ��Ҳָ������
   else // �ǿ���
   { Thrt->lchild=T; // ͷ��������ָ��ָ������
     pre=Thrt; // ǰ��Ϊͷ���
     PreThreading(T); // ��ͷ��㿪ʼ����ݹ�������
     pre->RTag=Thread; // ���һ�������Һ���ָ��Ϊ����
     pre->rchild=Thrt; // ���һ�����ĺ��ָ��ͷ���
     Thrt->rchild=pre; // ͷ���ĺ��ָ�����һ�����
   }
 }

 void PreOrderTraverse_Thr(BiThrTree T,void(*Visit)(TElemType))
 { // �����������������T(ͷ���)�ķǵݹ��㷨
   BiThrTree p=T->lchild; // pָ������
   while(p!=T) // pδָ��ͷ���(���������1�����ĺ��ָ��ͷ���)
   { Visit(p->data); // ���ʸ����
     if(p->LTag==Link) // p������
       p=p->lchild; // pָ������(���)
     else // p������
       p=p->rchild; // pָ���Һ��ӻ���
   }
 }

 void PostThreading(BiThrTree p)
 { // PostOrderThreading()���õĵݹ麯��
   if(p) // p����
   { PostThreading(p->lchild); // ��p�����ӵݹ����PostThreading()
     PostThreading(p->rchild); // ��p���Һ��ӵݹ����PostThreading()
     if(!p->lchild) // pû������
     { p->LTag=Thread; // p������ָ��Ϊ����
       p->lchild=pre; // p������ָ��ָ��ǰ��
     }
     if(!pre->rchild) // p��ǰ��û���Һ���
     { pre->RTag=Thread; // pǰ�����Һ���ָ��Ϊ����
       pre->rchild=p; // pǰ���ĺ��ָ��p
     }
     pre=p; // �ƶ�ǰ��
   }
 }

 void PostOrderThreading(BiThrTree &Thrt,BiThrTree T)
 { // ����ݹ�������������
   if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) // ����ͷ���
     exit(OVERFLOW);
   Thrt->LTag=Link; // ͷ��������ָ��Ϊ����
   Thrt->RTag=Thread; // ͷ�����Һ���ָ��Ϊ����
   if(!T) // ����
     Thrt->lchild=Thrt->rchild=Thrt; // ͷ�������Һ���ָ��ָ������
   else // �ǿ���
   { Thrt->lchild=Thrt->rchild=T; // ͷ�������Һ���ָ��ָ������(���һ�����)
     pre=Thrt; // ǰ��Ϊͷ���
     PostThreading(T); // ��ͷ��㿪ʼ����ݹ�������
     if(pre->RTag!=Link) // ���һ�����û���Һ���
     { pre->RTag=Thread; // ���һ�������Һ���ָ��Ϊ����
       pre->rchild=Thrt; // ���һ�����ĺ��ָ��ͷ���
     }
   }
 }

 void DestroyBiTree(BiThrTree &T)
 { // DestroyBiThrTree���õĵݹ麯����Tָ������
   if(T) // �ǿ���
   { if(T->LTag==0) // ������
       DestroyBiTree(T->lchild); // ����������
     if(T->RTag==0) // ���Һ���
       DestroyBiTree(T->rchild); // ����������
     free(T); // �ͷŸ����
     T=NULL; // ��ָ�븳0
   }
 }

 void DestroyBiThrTree(BiThrTree &Thrt)
 { // ��ʼ����������������Thrt���ڡ������������������������Thrt
   if(Thrt) // ͷ������
   { if(Thrt->lchild) // ��������
       DestroyBiTree(Thrt->lchild); // �ݹ�����ͷ���lchild��ָ������
     free(Thrt); // �ͷ�ͷ���
     Thrt=NULL; // ����������Thrtָ�븳0
   }
 }
