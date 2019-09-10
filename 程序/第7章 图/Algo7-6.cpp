 // algo7-6.cpp ʵ���㷨7.10��7.11�ĳ���
 #include"c1.h"
 #include"func7-1.cpp" // ����������Ϣ���͵Ķ��弰�����Ĳ���
 #include"func7-4.cpp" // ��(��)�������Ϣ���͵Ķ��弰�����Ĳ���
 #include"c7-2'.h" // ͼ���ڽӱ�洢�ṹ(�뵥����ı������ͽ�����ϵ)
 #include"bo7-2.cpp" // ͼ���ڽӱ�洢�ṹ�Ļ�������

 int count,lowcount=1; // ȫ����count�Է���˳�����,lowcount�����lowֵ��˳�����
 int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];
 // ȫ�����飬low[]�涥���lowֵ��lowOrder�涥�����lowֵ��˳��
 int visited[MAX_VERTEX_NUM]; // ���ʱ�־����(ȫ����)

 void DFSArticul(ALGraph G,int v0)
 { // �ӵ�v0���������������ȱ���ͼG�����Ҳ�����ؽڵ㡣�㷨7.11
   int min,w;
   ArcNode *p;
   visited[v0]=min=++count; // v0�ǵ�count�����ʵĶ��㣬min�ĳ�ֵΪv0�ķ���˳��
   for(p=G.vertices[v0].firstarc;p;p=p->nextarc) // ���ζ�v0��ÿ���ڽӶ�����
   { w=p->data.adjvex; // wΪv0���ڽӶ���λ��
     if(visited[w]==0) // wδ�����ʣ���v0�ĺ���
     { DFSArticul(G,w);
       // �ӵ�w���������������ȱ���ͼG�����Ҳ�����ؽڵ㡣����ǰ���low[w]
       if(low[w]<min) // ���v0�ĺ��ӽ��w��low[]С����˵�����ӽ�㻹���������(����)����
         min=low[w]; // ȡminֵΪ���ӽ���low[]����v0���ǹؽڵ�
       else if(low[w]>=visited[v0]) // v0�ĺ��ӽ��wֻ��v0��������v0�ǹؽڵ�
         printf("%d %s\n",v0,G.vertices[v0].data.name); // ����ؽڵ�v0
     }
     else if(visited[w]<min) // w�ѷ��ʣ���w��v0���������ϵ����ȣ����ķ���˳���С��min
       min=visited[w]; // ��ȡminΪvisited[w]
   }
   low[v0]=min; // v0��low[]ֵΪ�����е���Сֵ
   lowOrder[v0]=lowcount++;
   // ��¼v0���low[]ֵ��˳�������ڷ�����������֮ǰ���low[]������
 }

 void FindArticul(ALGraph G)
 { // ��ͨͼG���ڽӱ����洢�ṹ�����Ҳ����G��ȫ���ؽڵ㡣ȫ����count�Է��ʼ������㷨7.10
   int i,v;
   ArcNode *p;
   count=1; // ����˳��
   visited[0]=count; // �趨�ڽӱ���0�Ŷ���Ϊ�������ĸ�����1��������
   for(i=1;i<G.vexnum;++i) // �������ඥ��
     visited[i]=0; // ���ඥ����δ���ʣ����ֵΪ0
   p=G.vertices[0].firstarc; // pָ������ĵ�1���ڽӶ���
   v=p->data.adjvex; // v�Ǹ����ĵ�1���ڽӶ�������
   DFSArticul(G,v); // �ӵ�v�������������Ȳ��ҹؽڵ�
   if(count<G.vexnum) // �ɸ����ĵ�1���ڽӶ���������ȱ���G�����ʵĶ���������G�Ķ�����
   { // ˵���������ĸ���������������������ǹؽڵ�
     printf("%d %s\n",0,G.vertices[0].data.name); // ���ǹؽڵ㣬�����
     while(p->nextarc) // ������һ���ڽӵ�
     { p=p->nextarc; // pָ�������һ���ڽӵ�
       v=p->data.adjvex;
       if(visited[v]==0) // ���ڽӵ�δ������
         DFSArticul(G,v); // �Ӵ˶������������Ȳ��ҹؽڵ�
     }
   }
 }

 void main()
 {
   int i;
   ALGraph g;
   char filename[13]; // �洢�����ļ���(����·��)
   printf("�����������ļ�����");
   scanf("%s",filename);
   CreateFromFile(g,filename); // ���ļ���������ͼg
   Display(g); // �������ͼg
   printf("����ؽڵ㣺\n");
   FindArticul(g); // ����ͨͼg�Ĺؽڵ�
   printf(" i G.vertices[i].data visited[i] low[i] lowOrder[i]\n"); // �����������
   for(i=0;i<g.vexnum;++i)
     printf("%2d %9s %14d %8d %8d\n",i,g.vertices[i].data.name,
     visited[i],low[i],lowOrder[i]);
 }
