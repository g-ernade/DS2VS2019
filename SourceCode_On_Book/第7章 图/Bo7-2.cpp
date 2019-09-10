 // bo7-2.cpp ͼ���ڽӱ�洢(�洢�ṹ��c7-21.h����)�Ļ�������(14��)
 #include"bo2-3.cpp" // ����ͷ���ĵ������������
 #include"func2-4.cpp" // ����ͷ���ĵ�������չ����
 int LocateVex(ALGraph G,VertexType u)
 { // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����(����������ͬ)
   // �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ��(���)�����򷵻�-1
   int i;
   for(i=0;i<G.vexnum;++i) // �������ж������β���
     if(strcmp(u.name,G.vertices[i].data.name)==0) // �����������u�Ķ���������ͬ
       return i; // ���ض������
   return -1; // ͼG�в������붥��u����ͬ���ƵĶ���
 }

 void CreateGraph(ALGraph &G)
 { // �����ڽӱ�洢�ṹ������ͼ����G(��һ����������4��ͼ)
   int i,j,k;
   VertexType v1,v2; // ��������
   ElemType e; // �����Ԫ������(�洢������Ϣ)
   char s[3]="��";
   printf("������ͼ������(����ͼ��0 ��������1 ����ͼ��2 ��������3)��");
   scanf("%d",&G.kind);
   if(G.kind<2) // ����
     strcpy(s,"��");
   printf("������ͼ�Ķ�����,������");
   scanf("%d,%d",&G.vexnum,&G.arcnum);
   printf("������%d�������ֵ(����<%d���ַ�)��\n",G.vexnum,MAX_NAME);
   for(i=0;i<G.vexnum;++i) // ���춥������
   { Input(G.vertices[i].data); // ���붥����Ϣ
     G.vertices[i].firstarc=NULL; // ��ʼ����ö����йصĳ�������
   }
   printf("������%d��%s��",G.arcnum,s);
   switch(G.kind)
   { case  DG:printf("��β ��ͷ��\n"); // ��ͼû�л�(��)��Ϣ
              break;
     case  DN:printf("��β ��ͷ ������Ϣ��\n");
              break;
     case UDG:printf("����1 ����2��\n"); // ��ͼû�л�(��)��Ϣ
              break;
     case UDN:printf("����1 ����2 �ߵ���Ϣ��\n");
   }
   for(k=0;k<G.arcnum;++k) // ������ػ�����
   { scanf("%s%s",v1.name,v2.name); // ����2��������
     i=LocateVex(G,v1); // ��β
     j=LocateVex(G,v2); // ��ͷ
     e.info=NULL; // ���������e��ֵ����ͼ�޻�(��)��Ϣ
     if(G.kind%2) // ��
       InputArc(e.info); // ��̬���ɴ洢�ռ䣬���뻡�������Ϣ����func7-4.cpp��
     e.adjvex=j; // ��ͷ
     ListInsert(G.vertices[i].firstarc,1,e);
     // ��e���ڵ�i��Ԫ��(����)�ı�ͷ����bo2-3.cpp��
     if(G.kind>=2) // ����ͼ������������2�����㣬�����ڵ�j��Ԫ��(�뻡)�ı�ͷ
     { e.adjvex=i; // e.info���䣬�����ٸ�ֵ
       ListInsert(G.vertices[j].firstarc,1,e); // ���ڵ�j��Ԫ�صı�ͷ����bo2-3.cpp��
     }
   }
 }

 void CreateFromFile(ALGraph &G,char* filename)
 { // �����ڽӱ�洢�ṹ�����ļ�����ͼ����G(��һ����������4��ͼ)
   int i,j,k;
   VertexType v1,v2; // ��������
   ElemType e; // �����Ԫ������(�洢������Ϣ)
   FILE *f; // �ļ�ָ������
   f=fopen(filename,"r"); // �Զ��ķ�ʽ�������ļ�������f��ʾ
   fscanf(f,"%d",&G.kind); // ���ļ�����G������
   fscanf(f,"%d",&G.vexnum); // ���ļ�����G�Ķ�����
   for(i=0;i<G.vexnum;++i) // ���춥������
   { InputFromFile(f,G.vertices[i].data); // ���ļ����붥����Ϣ
     G.vertices[i].firstarc=NULL; // ��ʼ����ö����йصĳ�������
   }
   fscanf(f,"%d",&G.arcnum); // ���ļ�����G�Ļ�(��)��
   for(k=0;k<G.arcnum;++k) // ������ػ�����
   { fscanf(f,"%s%s",v1.name,v2.name); // ���ļ�����2��������
     i=LocateVex(G,v1); // ��β
     j=LocateVex(G,v2); // ��ͷ
     e.info=NULL; // ���������e��ֵ����ͼ�޻�(��)��Ϣ
     if(G.kind%2) // ��
       InputArcFromFile(f,e.info);
       // ��̬���ɴ洢�ռ䣬���ļ����뻡�������Ϣ����func7-4.cpp��
     e.adjvex=j; // ��ͷ
     ListInsert(G.vertices[i].firstarc,1,e);
     // ��e���ڵ�i��Ԫ��(����)�ı�ͷ����bo2-3.cpp��
     if(G.kind>=2) // ����ͼ������������2�����㣬�����ڵ�j��Ԫ��(�뻡)�ı�ͷ
     { e.adjvex=i; // e.info���䣬�����ٸ�ֵ
       ListInsert(G.vertices[j].firstarc,1,e); // ���ڵ�j��Ԫ�صı�ͷ����bo2-3.cpp��
     }
   }
   fclose(f); // �ر������ļ�
 }

 VertexType GetVex(ALGraph G,int v)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ���������š��������������v��ֵ
   if(v>=G.vexnum||v<0) // ͼG�в��������Ϊv�Ķ���
     exit(OVERFLOW);
   return G.vertices[v].data; // ���ظö������Ϣ
 }

 Status PutVex(ALGraph &G,VertexType v,VertexType value)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ�����㡣�����������v����ֵvalue
   int k=LocateVex(G,v); // kΪ����v��ͼG�е����
   if(k!=-1) // v��G�Ķ���
   { G.vertices[k].data=value; // ����ֵ��������v(�����Ϊk)
     return OK;
   }
   return ERROR; // v����G�Ķ���
 }

 int FirstAdjVex(ALGraph G,int v)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ����������
   // �������������v�ĵ�1���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1
   ArcNode *p=G.vertices[v].firstarc; // pָ�򶥵�v�ĵ�1���ڽӶ���
   if(p) // ����v���ڽӶ���
     return p->data.adjvex; // ����v�ĵ�1���ڽӶ�������
   else
     return -1; // ����vû���ڽӶ���
 }

 Status equalvex(ElemType a,ElemType b)
 { // DeleteArc()��DeleteVex()��NextAdjVex()Ҫ���õĺ���
   if(a.adjvex==b.adjvex) // ����Ķ�λ��(���)��ͬ
     return OK;
   else
     return ERROR;
 }

 int NextAdjVex(ALGraph G,int v,int w)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ���������ţ�w��v���ڽӶ�������
   // �������������v��(�����w��)��һ���ڽӶ������š�
   //           ��w��v�����һ���ڽӶ��㣬�򷵻�-1
   LinkList p,p1; // p1��Point()����������ָ�룬Point()��func2-4.cpp��
   ElemType e; // �����Ԫ������(�洢������Ϣ)
   e.adjvex=w;
   p=Point(G.vertices[v].firstarc,e,equalvex,p1);
   // pָ�򶥵�v���������ڽӶ���Ϊw�Ľ��
   if(!p||!p->next) // δ�ҵ�w��w�����һ���ڽӵ�
     return -1;
   else // p->data.adjvex==w
     return p->next->data.adjvex; // ����v��(�����w��)��һ���ڽӶ�������
 }

 void InsertVex(ALGraph &G,VertexType v)
 { // ��ʼ������ͼG���ڣ�v��ͼ�ж�������ͬ����
   // �����������ͼG�������¶���v(�������붥����صĻ�������InsertArc()ȥ��)
   G.vertices[G.vexnum].data=v; // �����¶�������
   G.vertices[G.vexnum].firstarc=NULL; // û���붥����صĻ�
   G.vexnum++; // ͼG�Ķ�������1
 }

 Status InsertArc(ALGraph &G,VertexType v,VertexType w)
 { // ��ʼ������ͼG���ڣ�v��w��G����������
   // �����������G������<v,w>����G������ģ�������Գƻ�<w,v>
   ElemType e; // �����Ԫ������(�洢������Ϣ)
   int i,j;
   char s1[3]="��",s2[3]="��"; // ��������
   if(G.kind<2) // ����
   { strcpy(s1,"��");
     strcpy(s2,"��");
   }
   i=LocateVex(G,v); // ��β��ߵ����
   j=LocateVex(G,w); // ��ͷ��ߵ����
   if(i<0||j<0) // v��w������1������G�еĶ���
     return ERROR;
   G.arcnum++; // ͼG�Ļ���ߵ���Ŀ��1
   e.adjvex=j; // ��ͷ�����ֵ
   e.info=NULL; // ��ֵ����ͼ�޻�(��)��Ϣ
   if(G.kind%2) // ��
   { printf("������%s%s%s%s����Ϣ��",s1,v.name,s2,w.name);
     InputArc(e.info); // ��̬���ɴ洢�ռ䣬���뻡�������Ϣ����func7-4.cpp��
   }
   ListInsert(G.vertices[i].firstarc,1,e); // ��e���ڻ�β�ı�ͷ����bo2-3.cpp��
   if(G.kind>=2) // ����������һ������
   { e.adjvex=i; // ��β�����ֵ��e.info����
     ListInsert(G.vertices[j].firstarc,1,e); // ��e���ڻ�ͷ�ı�ͷ
   }
   return OK;
 }

 Status DeleteArc(ALGraph &G,VertexType v,VertexType w)
 { // ��ʼ������ͼG���ڣ�v��w��G����������
   // �����������G��ɾ����<v,w>����G������ģ���ɾ���Գƻ�<w,v>
   int i,j,n;
   ElemType e; // �����Ԫ������(�洢������Ϣ)
   i=LocateVex(G,v); // i�Ƕ���v(��β)�����
   j=LocateVex(G,w); // j�Ƕ���w(��ͷ)�����
   if(i<0||j<0||i==j) // v��w������1������G�еĶ��㣬��v��w��G�е�ͬһ������
     return ERROR;
   e.adjvex=j; // ��ͷ�����ֵ
   n=LocateElem(G.vertices[i].firstarc,e,equalvex);
   // �ڻ�β�������һ�ͷ���㣬�����������е�λ�򸳸�n
   if(n) // ���ڸû�
   { ListDelete(G.vertices[i].firstarc,n,e); // �ڻ�β������ɾ����ͷ���㣬����e������ֵ
     G.arcnum--; // ���������1
     if(G.kind%2) // ������ͼ�޻�(��)��Ϣ
       free(e.info); // �ͷŶ�̬���ɵĻ�(��)��Ϣ�ռ�
     if(G.kind>=2) // ����ɾ���Գƻ�<w,v>
     { e.adjvex=i; // ��β�����ֵ
       n=LocateElem(G.vertices[j].firstarc,e,equalvex);
       // �ڻ�ͷ�������һ�β���㣬�����������е�λ�򸳸�n
       ListDelete(G.vertices[j].firstarc,n,e);
       // �ڻ�ͷ������ɾ����β���㣬����e������ֵ
     }
     return OK;
   }
   else // δ�ҵ���ɾ���Ļ�
     return ERROR;
 }

 Status DeleteVex(ALGraph &G,VertexType v)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ�����㡣���������ɾ��G�ж���v������صĻ�(��)
   int i,k;
   LinkList p; // �����ָ������
   k=LocateVex(G,v); // kΪ��ɾ������v�����
   if(k<0) // v����ͼG�Ķ���
     return ERROR;
   for(i=0;i<G.vexnum;i++)
     DeleteArc(G,v,G.vertices[i].data); // ɾ���ɶ���v���������л�
   if(G.kind<2) // ����
     for(i=0;i<G.vexnum;i++)
       DeleteArc(G,G.vertices[i].data,v); // ɾ�����򶥵�v�����л�
   for(i=0;i<G.vexnum;i++) // ����adjvex��>k�Ľ�㣬�����-1
   { p=G.vertices[i].firstarc; // pָ�򻡽��ĵ�����
     while(p) // δ����β
     { if(p->data.adjvex>k) // adjvex��>k
         p->data.adjvex--; // ���-1(��Ϊǰ��)
       p=p->next; // pָ����һ�����
     }
   }
   for(i=k+1;i<G.vexnum;i++)
     G.vertices[i-1]=G.vertices[i]; // ����v����Ķ�������ǰ��
   G.vexnum--; // ��������1
   return OK;
 }

 void DestroyGraph(ALGraph &G)
 { // ��ʼ������ͼG���ڡ��������������ͼG
   int i;
   for(i=G.vexnum-1;i>=0;i--) // �ɴ�С��һɾ�����㼰������صĻ�(��)
     DeleteVex(G,G.vertices[i].data);
 }
 
 void Display(ALGraph G)
 { // ���ͼ���ڽӾ���G
   int i;
   ArcNode *p;
   char s1[3]="��",s2[3]="��"; // ��������
   if(G.kind<2) // ����
   { strcpy(s1,"��");
     strcpy(s2,"��");
   }
   switch(G.kind)
   { case  DG:printf("����ͼ\n");
              break;
     case  DN:printf("������\n");
              break;
     case UDG:printf("����ͼ\n");
              break;
     case UDN:printf("������\n");
   }
   printf("%d�����㣬�����ǣ�",G.vexnum);
   for(i=0;i<G.vexnum;++i)
     Visit(GetVex(G,i)); // ���ݶ�����Ϣ�����ͣ����ʵ�i�����㣬��func7-1.cpp��
   printf("\n%d��%s��\n",G.arcnum,s1);
   for(i=0;i<G.vexnum;i++)
   { p=G.vertices[i].firstarc; // pָ�����Ϊi�Ķ���ĵ�1����(��)
     while(p) // p��Ϊ��
     { if(G.kind<=1||i<p->data.adjvex) // ��������������е�һ��
       { printf(" %s%s%s",G.vertices[i].data.name,s2,
         G.vertices[p->data.adjvex].data.name);
         if(G.kind%2) // ��
           OutputArc(p->data.info); // �����(��)��Ϣ(����Ȩֵ)����func7-4.cpp��
       }
       p=p->nextarc; // pָ����һ������
     }
     printf("\n");
   }
 }
