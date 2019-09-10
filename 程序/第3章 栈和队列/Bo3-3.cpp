 // bo3-3.cpp �õ�����Ļ�������ʵ��������(�洢�ṹ��c3-2.h����)�Ļ�������(9��)
 typedef QElemType ElemType; // ���嵥�����Ԫ������Ϊ���е�Ԫ������
 #define LinkList QueuePtr // ���嵥���������Ϊ��Ӧ�������е�����
 #define LNode QNode
 #include"bo2-2.cpp" // ������Ļ�������
 void InitQueue(LinkQueue &Q)
 { // ����һ���ն���Q
  InitList(Q.front); // ��Q.frontΪͷָ�룬���������(���õ�����Ļ�������)
  Q.rear=Q.front; // Q.rear��Q.front��ָͬ�������е�ͷ���
 }

 void DestroyQueue(LinkQueue &Q)
 { // ���ٶ���Q(���ۿշ����)
   DestroyList(Q.front); // ����Q.frontΪͷָ�����������Q.frontΪ��
   Q.rear=Q.front; // ��Q.rearҲΪ��
 }

 void ClearQueue(LinkQueue &Q)
 { // ������Q��Ϊ�ն���
   ClearList(Q.front); // �����Q.frontΪͷָ�������ͷ����ָ����Ϊ��
   Q.rear=Q.front; // Q.rearҲָ��ն��е�ͷ���
 }

 Status QueueEmpty(LinkQueue Q)
 { // ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
   return ListEmpty(Q.front); // ��Q.frontΪͷָ��ĵ�����Ϊ�գ������QΪ�գ���֮��Ȼ
 }

 int QueueLength(LinkQueue Q)
 { // �����Q�ĳ���
   return ListLength(Q.front); // ����Q�ĳ��ȼ�Ϊ��Q.frontΪͷָ��ĵ�����ĳ���
 }

 Status GetHead(LinkQueue Q,QElemType &e)
 { // ������Q���գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
   return GetElem(Q.front,1,e); // ��ͷԪ�ؼ�Ϊ��Q.frontΪͷָ��ĵ�����ĵ�1��Ԫ��
 }

 void EnQueue(LinkQueue &Q,QElemType e)
 { // ����Ԫ��eΪ����Q���µĶ�βԪ��
   ListInsert(Q.front,ListLength(Q.front)+1,e); // �����һ��Ԫ��֮�����e
 }

 Status DeQueue(LinkQueue &Q,QElemType &e)
 { // ������Q���գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(Q.front->next==Q.rear) // ���н���1��Ԫ��(ɾ����Ҳ�Ƕ�βԪ��)
     Q.rear=Q.front; // ���βָ��ָ��ͷ���
   return ListDelete(Q.front,1,e); // ɾ����Q.frontΪͷָ��ĵ�����ĵ�1��Ԫ��
 }

 void QueueTraverse(LinkQueue Q,void(*visit)(QElemType))
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit()
   ListTraverse(Q.front,visit); // ���ζ���Q.frontΪͷָ��ĵ������Ԫ�ص���visit()
 }
