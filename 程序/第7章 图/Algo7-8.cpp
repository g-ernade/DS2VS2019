 // algo7-8.cpp ��ؼ�·����ʵ���㷨7.13��7.14�ĳ���
 #include"c1.h"
 #include"func7-6.cpp" // ����������Ϣ���͵Ķ��弰�����Ĳ���
 #include"func7-7.cpp" // ���������Ϣ���͵Ķ��弰�����Ĳ���
 #include"c7-2'.h" // ͼ���ڽӱ�洢�ṹ(�뵥����ı������ͽ�����ϵ)
 #include"bo7-2.cpp" // ͼ���ڽӱ�洢�ṹ�Ļ�������
 #include"func7-5.cpp" // �󶥵���ȵĺ���
 typedef int SElemType; // ����ջԪ������Ϊ����(�洢�������)
 #include"c3-1.h" // ˳��ջ�Ĵ洢�ṹ
 #include"bo3-1.cpp" // ˳��ջ�Ļ�������
 Status TopologicalOrder(ALGraph &G,SqStack &T)
 { // ������G�����ڽӱ�洢�ṹ����������¼������緢��ʱ��ve(�洢��G��)���޸��㷨7.13
   // TΪ�������ж���ջ��SΪ����ȶ���ջ����G�޻�·������ջT����G��һ���������У�
   // �Һ���ֵΪOK������ΪERROR
   int i,k,count=0; // ����ջ����������ֵΪ0
   int indegree[MAX_VERTEX_NUM]; // ������飬��Ÿ����㵱ǰ�����
   SqStack S;
   ArcNode *p;
   FindInDegree(G,indegree); // �Ը����������indegree[]����func7-5.cpp��
   InitStack(S); // ��ʼ������ȶ���ջS
   printf("�������У�");
   for(i=0;i<G.vexnum;++i) // �����ж���i
     if(!indegree[i]) // �������Ϊ0
       Push(S,i); // ��i������ȶ���ջS
   InitStack(T); // ��ʼ���������ж���ջ
   for(i=0;i<G.vexnum;++i) // ��ʼ��ve=0(��Сֵ���ȼٶ�ÿ���¼������������¼�Լ��)
     G.vertices[i].data.ve=0;
   while(!StackEmpty(S)) // ������ȶ���ջS����
   { Pop(S,i); // ��ջS������������Ķ��㵯����������i
     Visit(G.vertices[i].data); // ����ö��������
     Push(T,i); // j�Ŷ���������������ջT(ջ��Ԫ��Ϊ��������ĵ�1��Ԫ��)
     ++count; // ����ջT�Ķ������
     for(p=G.vertices[i].firstarc;p;p=p->nextarc)
     { // ��i�Ŷ����ÿ���ڽӶ���
       k=p->data.adjvex; // �����Ϊk
       if(--indegree[k]==0) // k����ȼ�1������Ϊ0����k��ջS
         Push(S,k);
       if(G.vertices[i].data.ve+p->data.info->weight>G.vertices[k].data.ve)
       // ����i�¼������緢��ʱ��+<i,k>��Ȩֵ>����k�¼������緢��ʱ��
         G.vertices[k].data.ve=G.vertices[i].data.ve+p->data.info->weight;
         // ����k�¼������緢��ʱ��=����i�¼������緢��ʱ��+<i,k>��Ȩֵ
     }   // ����i���������򣬹�G.vertices[i].data.ve���ٸı�
   }
   if(count<G.vexnum)
   { printf("���������л�·\n");
     return ERROR;
   }
   else
     return OK;
 }

 Status CriticalPath(ALGraph &G)
 { // GΪ�����������G�ĸ���ؼ�����޸��㷨7.14
   SqStack T;
   int i,j,k;
   ArcNode *p;
   if(!TopologicalOrder(G,T)) // ��������
     return ERROR;
   j=G.vertices[0].data.ve; // j�ĳ�ֵ
   for(i=1;i<G.vexnum;i++) // �����ж����У���ve�����ֵ
     if(G.vertices[i].data.ve>j)
       j=G.vertices[i].data.ve; // j=Max(ve) ��ɵ�����緢��ʱ��
   for(i=0;i<G.vexnum;i++) // ��ʼ�������¼�����ٷ���ʱ��
     G.vertices[i].data.vl=j; // Ϊ��ɵ�����緢��ʱ��(���ֵ)
   while(!StackEmpty(T)) // ������������������vlֵ
     for(Pop(T,j),p=G.vertices[j].firstarc;p;p=p->nextarc)
     { // ����ջT��Ԫ�أ�����j��pָ�򶥵�j�ĺ���¼�(����)����k��
       // �¼�k����ٷ���ʱ����ȷ��(��Ϊ������������)
       k=p->data.adjvex; // ����¼���������
       if(G.vertices[k].data.vl-p->data.info->weight<G.vertices[j].data.vl)
       // �¼�j����ٷ���ʱ��>��ֱ�Ӻ���¼�k����ٷ���ʱ��-<j,k>��Ȩֵ
         G.vertices[j].data.vl=G.vertices[k].data.vl-p->data.info->weight;
         // �¼�j����ٷ���ʱ��=�¼�k����ٷ���ʱ��-<j,k>��Ȩֵ
     }   // ����k�����������򣬹�G.vertices[k].data.vl���ٸı�
   printf("\ni  ve  vl\n");
   for(i=0;i<G.vexnum;i++) // ����ÿ������
   { printf("%d ",i); // ������
     Visitel(G.vertices[i].data); // ���ve��vlֵ����func7-6.cpp��
     if(G.vertices[i].data.ve==G.vertices[i].data.vl)
     // �¼�(����)�����緢��ʱ��=��ٷ���ʱ��
       printf(" �ؼ�·�������Ķ���");
     printf("\n");
   }
   printf("j   k  Ȩֵ  ee  el\n"); // ������ee��el�͹ؼ��
   for(j=0;j<G.vexnum;++j) // ����ÿ������j
     for(p=G.vertices[j].firstarc;p;p=p->nextarc)
     { // p����ָ�����ڽӶ���(ֱ�Ӻ���¼�)
       k=p->data.adjvex; // �ڽӶ���(ֱ�Ӻ���¼�)���
       p->data.info->ee=G.vertices[j].data.ve;
       // ee(�<j,k>�����翪ʼʱ��)=(����j)�¼����緢��ʱ��
       p->data.info->el=G.vertices[k].data.vl-p->data.info->weight;
       // el(�<j,k>����ٿ�ʼʱ��)=(����k)�¼���ٷ���ʱ��-<j,k>��Ȩֵ
       printf("%s��%s",G.vertices[j].data.name,G.vertices[k].data.name); // �����
       OutputArcwel(p->data.info); // �������Ȩֵ��ee��el����func7-7.cpp��
       if(p->data.info->ee==p->data.info->el)
       // �(��)�����翪ʼʱ��=�����ٿ�ʼʱ��
         printf("�ؼ��");
       printf("\n");
     }
   return OK;
 }

 void main()
 {
   ALGraph h;
   printf("��ѡ��������\n");
   CreateGraph(h); // ����������h����bo7-2.cpp��
   Display(h); // ���������h����bo7-2.cpp��
   CriticalPath(h); // ��h�Ĺؼ�·��
 }
