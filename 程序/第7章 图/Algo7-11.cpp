 // algo7-11.cpp ʵ�ֽ̿���ͼ7.33�ĳ���(������������̨��)
 #include"c1.h"
 #include"func7-1.cpp" // ����������Ϣ���͵Ķ��弰�����Ĳ���
 #include"func7-2.cpp" // ������(��)�������Ϣ���͵Ķ��弰�����Ĳ���
 #include"c7-1.h" // ͼ������(�ڽӾ���)�洢�ṹ
 #include"bo7-1.cpp" // ͼ������(�ڽӾ���)�洢�ṹ�Ļ�������
 typedef char PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 // ��ά���飬��ֵֻ������0��1������char�����Լ��ٴ洢�ռ���˷�
 typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ��ά����
#include"func7-8.cpp" // ���������и��Զ���֮����̾����Floyd�㷨

 void path(MGraph G,PathMatrix P,int i,int j)
 { // �������Ϊi�������е����Ϊj���յ�������·����;�������ĳ���
   int k,m=i; // ��������Ÿ���m
   printf("���ξ����ĳ��У�\n");
   while(m!=j) // δ���յ����
   { G.arcs[m][m].adj=INFINITY; // �Խ�Ԫ�ظ�ֵ�����
     for(k=0;k<G.vexnum;k++)
       if(G.arcs[m][k].adj<INFINITY&&P[m][j][k])
       { // m��k��ֱ��ͨ·����k��m��j�����·����
         printf("%s ",G.vexs[m].name);
         G.arcs[m][k].adj=G.arcs[k][m].adj=INFINITY; // ��ֱ��ͨ·��Ϊ��ͨ
         m=k; // �����ĳ�����Ÿ���m����������
         break;
       }
   }
   printf("%s\n",G.vexs[j].name); // ����յ����
 }

 void main()
 {
   MGraph g;
   int i,j,k,q=1;
   PathMatrix p; // ��ά����
   DistancMatrix d; // ��ά����
   char filename[8]="map.txt"; // �����ļ���
   CreateFromFile(g,filename,0); // ͨ���ļ�map.txt����û�������Ϣ��������g
   for(i=0;i<g.vexnum;i++)
     g.arcs[i][i].adj=0;
     // ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0����Ϊ������ͬ�������Ϊ0
   ShortestPath_FLOYD(g,p,d); // ��ÿ�Զ��������·������func7-8.cpp��
   while(q)
   { printf("��ѡ��1 ��ѯ  0 ����\n");
     scanf("%d",&q);
     if(q)
     { printf("���д��룺\n");
       for(i=0;i<g.vexnum;i++)
       { printf("%2d.%-8s",i+1,g.vexs[i].name);
         if(i%7==6) // ���7�����ݾͻ���
           printf("\n");
       }
       printf("\n������Ҫ��ѯ�������д��� �յ���д��룺");
       scanf("%d%d",&i,&j);
       if(d[i-1][j-1]<INFINITY) // ��ͨ·
       { printf("%s��%s����̾���Ϊ%d\n",g.vexs[i-1].name,g.vexs[j-1].name,
         d[i-1][j-1]);
         path(g,p,i-1,j-1); // �����·�����������е��յ������;�������ĳ���
       }
       else
         printf("%s��%sû��·����ͨ\n",g.vexs[i-1].name,g.vexs[j-1].name);
       printf("��%s��%s�йص�p����\n",g.vexs[i-1].name,g.vexs[j-1].name);
       for(k=0;k<g.vexnum;k++)
         printf("%2d",p[i-1][j-1][k]);
       printf("\n");
     }
   }
 }
