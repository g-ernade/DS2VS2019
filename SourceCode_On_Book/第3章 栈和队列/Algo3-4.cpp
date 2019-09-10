 // algo3-4.cpp ����ջ����Թ�����(ֻ���һ���⣬�㷨3.3)
 #include"c1.h"
 struct PosType // �Թ�����λ������
 { int x; // ��ֵ
   int y; // ��ֵ
 };
 // ȫ�ֱ���
 PosType begin,end; // �Թ����������,��������
 PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}};
 // {������,������}���ƶ���������Ϊ��������

 #define MAXLENGTH 25 // ���Թ����������Ϊ25
 typedef int MazeType[MAXLENGTH][MAXLENGTH]; // �Թ���������[��][��]
 MazeType m; // �Թ�����
 int x,y; // �Թ�������,����

 void Print()
 { // ����Թ��Ľ�(m����)
   int i,j;
   for(i=0;i<x;i++)
   { for(j=0;j<y;j++)
       printf("%3d",m[i][j]);
     printf("\n");
   }
 }

 void Init()
 { // �趨�Թ�����(ǽֵΪ0��ͨ��ֵΪ1)
   int i,j,x1,y1;
   printf("�������Թ�������,����(������ǽ)��");
   scanf("%d,%d",&x,&y);
   for(i=0;i<y;i++) // �����ܱ�ֵΪ0(��ǽ)
   { m[0][i]=0; // �ϱ�
     m[x-1][i]=0; // �±�
   }
   for(i=1;i<x-1;i++)
   { m[i][0]=0; // ���
     m[i][y-1]=0; // �ұ�
   }
   for(i=1;i<x-1;i++)
     for(j=1;j<y-1;j++)
       m[i][j]=1; // �������ǽ�����඼��ͨ������ֵΪ1
   printf("�������Թ���ǽ��Ԫ����");
   scanf("%d",&j);
   printf("�����������Թ���ǽÿ����Ԫ������,������\n");
   for(i=1;i<=j;i++)
   { scanf("%d,%d",&x1,&y1);
     m[x1][y1]=0; // �޸���ǽ��ֵΪ0
   }
   printf("�Թ��ṹ���£�\n");
   Print();
   printf("��������ڵ�����,������");
   scanf("%d,%d",&begin.x,&begin.y);
   printf("��������ڵ�����,������");
   scanf("%d,%d",&end.x,&end.y);
 }

 int curstep=1; // ��ǰ�㼣����ֵ(����ڴ�)Ϊ1
 struct SElemType // ջ��Ԫ�����͡��ڽ̿����51ҳ
 { int ord; // ͨ������·���ϵġ���š�
   PosType seat; // ͨ�������Թ��еġ�����λ�á�
   int di; // �Ӵ�ͨ����������һͨ����ġ�����(0��3��ʾ������)
 };

 #include"c3-1.h" // ����˳��ջ�洢�ṹ
 #include"bo3-1.cpp" // ����˳��ջ�Ļ�����������

 // ����ǽԪ��ֵΪ0����ͨ��·��Ϊ1������̽����ͨ��·��Ϊ-1��ͨ��·��Ϊ�㼣
 Status Pass(PosType b)
 { // ���Թ�m��b���ֵΪ1(��ͨ��·��)������OK�����򣬷���ERROR
   if(m[b.x][b.y]==1)
     return OK;
   else
     return ERROR;
 }

 void FootPrint(PosType b)
 { // ʹ�Թ�m��b���ֵ��Ϊ�㼣(curstep)
   m[b.x][b.y]=curstep;
 }

 void NextPos(PosType &b,int di)
 { // ���ݵ�ǰλ��b���ƶ�����di���޸�bΪ��һλ��
   b.x+=direc[di].x;
   b.y+=direc[di].y;
 }

 void MarkPrint(PosType b)
 { // ʹ�Թ�m��b���ֵ��Ϊ-1(���Ϊ����̽�ɴ˲��ܵ����յ��·��)
   m[b.x][b.y]=-1;
 }

 Status MazePath(PosType start,PosType end) // �㷨3.3
 { // ���Թ�m�д��ڴ����start������end��ͨ���������һ�������ջ��(��ջ�׵�ջ��)��
   // ������TRUE�����򷵻�FALSE
   PosType curpos=start; // ��ǰλ�������
   SqStack S; // ˳��ջ
   SElemType e; // ջԪ��
   InitStack(S); // ��ʼ��ջ
   do
   { if(Pass(curpos)) // ��ǰλ�ÿ���ͨ��������δ���ߵ�����ͨ����
     { FootPrint(curpos); // �����㼣(ʹ�Թ�m�ĵ�ǰλ�õ�ֵΪcurstep)
       e.ord=curstep; // ջԪ�ص����Ϊ��ǰ�㼣curstep
       e.seat=curpos; // ջԪ�ص�λ��Ϊ��ǰλ��
       e.di=0; // �ӵ�ǰλ�ó�������һλ������
       Push(S,e); // ��ջ��ǰλ�ü�״̬
       curstep++; // �㼣��1
       if(curpos.x==end.x&&curpos.y==end.y) // �����յ�(����)
         return TRUE;
       NextPos(curpos,e.di); // �ɵ�ǰλ�ü��ƶ�����ȷ����һ����ǰλ�ã��Ը���curpos
     }
     else // ��ǰλ�ò���ͨ��
     { if(!StackEmpty(S)) // ջ����
       { Pop(S,e); // ��ջ��ǰһλ��
         curstep--; // �㼣��1
         while(e.di==3&&!StackEmpty(S)) // ǰһλ�ô������һ������(��)��ջ����
         { MarkPrint(e.seat); // ��ǰһλ���������䲻�ܵ����յ�ı��(-1)
           Pop(S,e); // ���˻�һ��
           curstep--; // �㼣�ټ�1
         }
         if(e.di<3) // δ�����һ������(��)
         { e.di++; // ����һ������̽��
           Push(S,e); // ��ջ��λ�õ���һ������
           curstep++; // �㼣��1
           curpos=e.seat; // ȷ����ǰλ��
           NextPos(curpos,e.di); // �ɵ�ǰλ�ü��ƶ�����ȷ����һ����ǰλ�ã��Ը���curpos
         }
       }
     }
   }while(!StackEmpty(S));
   return FALSE;
 }

 void main()
 {
   Init(); // ��ʼ���Թ�
   if(MazePath(begin,end)) // ��ͨ·
   { printf("���Թ�����ڵ����ڵ�һ��·�����£�\n");
     Print(); // �����ͨ·(m����)
   }
   else
     printf("���Թ�û�д���ڵ����ڵ�·��\n");
 }
