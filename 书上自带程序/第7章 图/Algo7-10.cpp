 // algo7-10.cpp ʵ���㷨7.16�ĳ���
 #include"c1.h"
 #include"func7-1.cpp" // ����������Ϣ���͵Ķ��弰�����Ĳ���
 #include"func7-2.cpp" // ������(��)�������Ϣ���͵Ķ��弰�����Ĳ���
 #include"c7-1.h" // ͼ������(�ڽӾ���)�洢�ṹ
 #include"bo7-1.cpp" // ͼ������(�ڽӾ���)�洢�ṹ�Ļ�������
 typedef char PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 // ��ά���飬��ֵֻ������0��1������char�����Լ��ٴ洢�ռ���˷�
 typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ��ά����
 #include"func7-8.cpp" // ���������и��Զ���֮����̾����Floyd�㷨

 void main()
 {
   MGraph g;
   int i,j,k;
   PathMatrix p; // ��ά����
   DistancMatrix d; // ��ά����
   CreateDN(g); // ����������g
   for(i=0;i<g.vexnum;i++)
     g.arcs[i][i].adj=0;
     // ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0����Ϊ������ͬ�������Ϊ0
   Display(g); // ���������g
   ShortestPath_FLOYD(g,p,d); // ��ÿ�Զ��������·������func7-8.cpp��
   printf("d����\n");
   for(i=0;i<g.vexnum;i++)
   { for(j=0;j<g.vexnum;j++)
       printf("%6d",d[i][j]);
     printf("\n");
   }
   printf("p����\n");
   for(i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
       if(i!=j)
       { printf("��%s��%s������",g.vexs[i].name,g.vexs[j].name);
         for(k=0;k<g.vexnum;k++)
           if(p[i][j][k]==1)
             printf("%s ",g.vexs[k].name);
         printf("\n");
       }
 }
