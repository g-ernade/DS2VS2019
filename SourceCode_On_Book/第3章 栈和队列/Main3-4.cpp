 // main3-4.cpp ѭ������ ����bo3-4.cpp��������
 #include"c1.h"
 typedef int QElemType; // �������Ԫ��Ϊ����
 #include"c3-3.h" // ���е�˳��洢�ṹ(ѭ������)
 #include"bo3-4.cpp" // ѭ�����д洢�ṹ�Ļ�������(9��)
 #define ElemType QElemType // ��func2-2.cpp�е�ElemType���Ͷ���ΪQElemType����
 #include"func2-2.cpp" // ����equal()��comp()��print()��print1()��print2()����

 void main()
 {
   Status j;
   int i=0,m;
   QElemType d;
   SqQueue Q;
   InitQueue(Q); // ��ʼ������Q��ʧ�����˳�
   printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("���������Ͷ���Ԫ��(������%d��)��-1Ϊ��ǰ��������",MAX_QSIZE-1);
   do
   { scanf("%d",&d); // �ɼ����������Ͷ���Ԫ��
     if(d==-1) // ���������ǰ������
       break; // �˳���������ѭ��
     i++; // ������+1
     EnQueue(Q,d); // ��������Ԫ��
   }while(i<MAX_QSIZE-1); // ����Ԫ�صĸ�������������ķ�Χ
   printf("���г���Ϊ%d��",QueueLength(Q));
   printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("����%d���ɶ�ͷɾ��Ԫ�أ���β����Ԫ�أ�\n",MAX_QSIZE);
   for(m=1;m<=MAX_QSIZE;m++)
   { DeQueue(Q,d); // ɾ����ͷԪ�أ���ֵ����d
     printf("ɾ����Ԫ����%d��������������Ԫ�أ�",d);
     scanf("%d",&d); // ����Ҫ��ӵ�Ԫ�ظ�d
     EnQueue(Q,d); // ��d���
   }
   m=QueueLength(Q); // mΪ����Q�ĳ���
   printf("���ڶ����е�Ԫ��Ϊ");
   QueueTraverse(Q,print); // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���print()
   printf("�����β������%d��Ԫ�ء�",i+MAX_QSIZE);
   if(m-2>0)
     printf("�����ɶ�ͷɾ��%d��Ԫ�أ�",m-2);
   while(QueueLength(Q)>2)
   { DeQueue(Q,d); // ɾ����ͷԪ�أ���ֵ����d
     printf("ɾ����Ԫ��ֵΪ%d��",d);
   }
   j=GetHead(Q,d); // ����ͷԪ�ظ���d
   if(j) // ����Q����
     printf("���ڶ�ͷԪ��Ϊ%d\n",d);
   ClearQueue(Q); // ��ն���Q
   printf("��ն��к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   DestroyQueue(Q); // ���ٶ���Q
 }
