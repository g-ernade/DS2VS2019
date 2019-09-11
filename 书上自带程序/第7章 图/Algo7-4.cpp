 // algo7-4.cpp ʵ���㷨7.9�ĳ���
 #include"c1.h"
 #include"func7-1.cpp" // ����������Ϣ���͵Ķ��弰�����Ĳ���
 #include"func7-2.cpp" // ������(��)�������Ϣ���͵Ķ��弰�����Ĳ���
 #include"c7-1.h" // ͼ������(�ڽӾ���)�洢�ṹ
 #include"bo7-1.cpp" // ͼ������(�ڽӾ���)�洢�ṹ�Ļ�������

 typedef struct
 { // ��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
   int adjvex; // ���㼯U�е��õ�Ϊ��СȨֵ���Ǹ���������
   VRType lowcost; // �Ǹ����㵽�õ��Ȩֵ(��СȨֵ)
 }minside[MAX_VERTEX_NUM];

 int minimum(minside SZ,MGraph G)
 { // ��SZ.lowcost����С��ֵ������������SZ�е����
   int i=0,j,k,min;
   while(!SZ[i].lowcost) // �ҵ�1��ֵ��Ϊ0��SZ[i].lowcost�����
     i++;
   min=SZ[i].lowcost; // min��ǵ�1����Ϊ0��ֵ
   k=i; // k��Ǹ�ֵ�����
   for(j=i+1;j<G.vexnum;j++) // ���������
     if(SZ[j].lowcost>0&&SZ[j].lowcost<min) // �ҵ��µĸ�С����ֵ
     { min=SZ[j].lowcost; // min��Ǵ���ֵ
       k=j; // k��Ǵ���ֵ�����
     }
   return k; // ���ص�ǰ��С��ֵ��SZ�е����
 }

 void MiniSpanTree_PRIM(MGraph G,VertexType u)
 { // ������ķ�㷨�Ӷ���u����������G����С������T�����T�ĸ����ߡ��㷨7.9
   int i,j,k;
   minside closedge;
   k=LocateVex(G,u); // ����u�����
   for(j=0;j<G.vexnum;++j) // ���������ʼ��
   { closedge[j].adjvex=k; // ����u����Ÿ���closedge[j].adjvex
     closedge[j].lowcost=G.arcs[k][j].adj; // ����u���õ��Ȩֵ
   }
   closedge[k].lowcost=0; // ��ʼ��U={u}��U�еĶ��㵽����U��ȨֵΪ0
   printf("��С�����������ĸ�����Ϊ\n");
   for(i=1;i<G.vexnum;++i) // ѡ������G.vexnum-1������(i������)
   { k=minimum(closedge,G); // �����С������T����һ����㣺��k����
     printf("(%s-%s)\n",G.vexs[closedge[k].adjvex].name,G.vexs[k].name);
     // �����С������T�ı�
     closedge[k].lowcost=0; // ��k���㲢��U��
     for(j=0;j<G.vexnum;++j)
       if(G.arcs[k][j].adj<closedge[j].lowcost) // �¶��㲢��U��������ѡ����С��
       { closedge[j].adjvex=k;
         closedge[j].lowcost=G.arcs[k][j].adj;
       }
   }
 }

 void main()
 {
   MGraph g;
   char filename[13]; // �洢�����ļ���(����·��)
   printf("�����������ļ�����");
   scanf("%s",filename);
   CreateFromFile(g,filename,0); // �����������Ϣ����
   Display(g); // ���������g
   MiniSpanTree_PRIM(g,g.vexs[0]);
   // ������ķ�㷨�ӵ�1������������g����С�������ĸ�����
 }
