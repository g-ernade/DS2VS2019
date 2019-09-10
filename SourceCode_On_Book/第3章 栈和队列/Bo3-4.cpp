 // bo3-4.cpp ѭ������(�洢�ṹ��c3-3.h����)�Ļ�������(9��)
 void InitQueue(SqQueue &Q)
 { // ����һ���ն���Q���ڽ̿����64ҳ
   Q.base=(QElemType*)malloc(MAX_QSIZE*sizeof(QElemType));
   if(!Q.base) // �洢����ʧ��
     exit(OVERFLOW);
   Q.front=Q.rear=0;
 }

 void DestroyQueue(SqQueue &Q)
 { // ���ٶ���Q��Q���ٴ���
   if(Q.base) // ����Q����
     free(Q.base); // �ͷ�Q.base��ָ�Ĵ洢�ռ�
   Q.base=NULL; // Q.base��ָ���κδ洢��Ԫ
   Q.front=Q.rear=0;
 }

 void ClearQueue(SqQueue &Q)
 { // ������Q��Ϊ�ն���
   Q.front=Q.rear=0;
 }

 Status QueueEmpty(SqQueue Q)
 { // ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
   if(Q.front==Q.rear) // ���пյı�־
     return TRUE;
   else
     return FALSE;
 }

 Status GetHead(SqQueue Q,QElemType &e)
 { // ������Q���գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
   if(Q.front==Q.rear) // ���п�
     return ERROR;
   e=Q.base[Q.front]; // ����ͷԪ�ص�ֵ����e
   return OK;
 }

 Status EnQueue(SqQueue &Q,QElemType e)
 { // ����Ԫ��eΪ����Q���µĶ�βԪ�ء��ڽ̿����65ҳ
   if((Q.rear+1)%MAX_QSIZE==Q.front) // ������
     return ERROR;
   Q.base[Q.rear]=e; // ��e���ڶ�β
   Q.rear=(Q.rear+1)%MAX_QSIZE; // ��βָ��+1���MAX_QSIZEȡ��
   return OK;
 }

 int QueueLength(SqQueue Q)
 { // ���ض���Q��Ԫ�ظ����������еĳ��ȡ��ڽ̿����64ҳ
   return(Q.rear-Q.front+MAX_QSIZE)%MAX_QSIZE;
 }

 Status DeQueue(SqQueue &Q,QElemType &e) // �ڽ̿����65ҳ
 { // ������Q���գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(Q.front==Q.rear) // ���п�
     return ERROR;
   e=Q.base[Q.front]; // ����ͷԪ�ص�ֵ����e
   Q.front=(Q.front+1)%MAX_QSIZE; // �ƶ���ͷָ��
   return OK;
 }

 void QueueTraverse(SqQueue Q,void(*visit)(QElemType))
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit()
   int i=Q.front; // i���ָ���ͷԪ��
   while(i!=Q.rear) // iָ�����Q�е�Ԫ��
   { visit(Q.base[i]); // ��i��ָԪ�ص��ú���visit()
     i=(i+1)%MAX_QSIZE; // iָ����һ��Ԫ��
   }
   printf("\n");
 }
