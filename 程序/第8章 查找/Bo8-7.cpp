 // bo8-7.cpp ��ϣ�����Ļ��������������㷨9.17��9.18
 void InitHashTable(HashTable &H)
 { // �������������һ���յĹ�ϣ��
   int i;
   H.count=0; // ��ǰԪ�ظ���Ϊ0
   H.sizeindex=0; // ��ʼ�洢������С��Ϊhashsize[0]
   m=hashsize[0]; // ��ϣ�����ȫ�ֱ���
   H.elem=(ElemType*)malloc(m*sizeof(ElemType));
   if(!H.elem)
     exit(OVERFLOW); // �洢����ʧ��
   for(i=0;i<m;i++)
     H.elem[i].key=NULL_KEY; // δ���¼�ı�־
 }

 void DestroyHashTable(HashTable &H)
 { // ��ʼ��������ϣ��H���ڡ�������������ٹ�ϣ��H
   free(H.elem); // �ͷ�H.elem�Ĵ洢�ռ�
   H.elem=NULL;
   H.count=0;
   H.sizeindex=0;
 }

 unsigned Hash(KeyType K)
 { // һ���򵥵Ĺ�ϣ����(mΪ����ȫ�ֱ���)
   return K%m;
 }

 int d(int i) // �������к�����������3���и�����Ҫѡȡ1�У�����2����Ϊע��
 { return i; // ����̽����ɢ��
 //return ((i+1)/2)*((i+1)/2)*(int)pow(-1,i-1); // ����̽����ɢ��
 //return rand(); // α���̽����ɢ��
 }

 void collision(KeyType K,int &p,int i)
 { p=(Hash(K)+d(i))%m; // ���Ŷ�ַ�������ͻ
 }

 Status SearchHash(HashTable H,KeyType K,int &p,int &c)
 { // �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ�أ������ҳɹ�����pָʾ��������
   // Ԫ���ڱ���λ�ã�������SUCCESS��������pָʾ����λ�ã�������UNSUCCESS
   // c���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο����޸��㷨9.17
   p=Hash(K); // ��ù�ϣ��ַ
   while(H.elem[p].key!=NULL_KEY&&!EQ(K,H.elem[p].key))
   { // ��λ�������м�¼������������ҵĹؼ��ֲ����
     c++; // �Ƴ�ͻ����+1
     if(c<m) // ��H���п����ҵ������ַ���޸�
       collision(K,p,c); // �����һ̽���ַp
     else // ��H�в������ҵ������ַ
       break; // �˳�whileѭ��
   }
   if EQ(K,H.elem[p].key) // ���ҳɹ�
     return SUCCESS; // p���ش�������Ԫ��λ��
   else // ���Ҳ��ɹ�
     return UNSUCCESS; // H.elem[p].key==NULL_KEY��p���ص��ǲ���λ��
 }

 void RecreateHashTable(HashTable&); // �Ժ���RecreateHashTable()������
 Status InsertHash(HashTable &H,ElemType e)
 { // ���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�������OK��
   // ����ͻ�����������ؽ���ϣ���㷨9.18
   int p,c=0; // ��ͻ��������ʼΪ0
   if(SearchHash(H,e.key,p,c)) // ���ҳɹ�
     return DUPLICATE; // H��������e����ͬ�ؼ��ֵ�Ԫ�أ����ٲ���
   else if(c<hashsize[H.sizeindex]/2) // δ�ҵ�����ͻ����Ҳcδ�ﵽ���ޣ�(c�ķ�ֵ�ɵ�)
   { H.elem[p]=e; // ��H�в�������Ԫ��e
     ++H.count; // H������Ԫ�ظ���+1
     return OK; // ����ɹ�
   }
   else // δ�ҵ�������ͻ����c�Ѵﵽ����
   { RecreateHashTable(H); // �ؽ���ϣ��
     return UNSUCCESS; // ���벻�ɹ��������²���
   }
 }

 void RecreateHashTable(HashTable &H)
 { // �ؽ���ϣ��H
   int i,count=H.count; // H��ԭ�����ݸ���
   ElemType *p,*elem=(ElemType*)malloc(count*sizeof(ElemType));
   // ��̬���ɴ�Ź�ϣ��Hԭ�����ݵĿռ�
   p=elem; // pָ��elem
   for(i=0;i<m;i++) // ��Hԭ�еĵ�1�����ݵ����1�����ݣ����浽elem��
     if((H.elem+i)->key!=NULL_KEY) // H�ڸõ�Ԫ������
       *p++=*(H.elem+i); // ���������δ���elem
   H.count=0; // H�ĵ�ǰ����Ԫ�ظ���Ϊ0
   H.sizeindex++; // ����洢����Ϊ��һ��������
   m=hashsize[H.sizeindex]; // �µĴ洢����
   H.elem=(ElemType*)realloc(H.elem,m*sizeof(ElemType));
   // ���µĴ洢�����������ɿչ�ϣ��H
   for(i=0;i<m;i++)
     H.elem[i].key=NULL_KEY; // δ���¼�ı�־(��ʼ��)
   for(p=elem;p<elem+count;p++) // ��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����
     InsertHash(H,*p);
   free(elem); // �ͷ�elem�Ĵ洢�ռ�
 }

 void TraverseHash(HashTable H,void(*Visit)(int,ElemType))
 { // ����ϣ��ַ��˳�������ϣ��H
   int i;
   printf("��ϣ��ַ0��%d\n",m-1);
   for(i=0;i<m;i++) // ����������ϣ��H
     if(H.elem[i].key!=NULL_KEY) // H�ڵ�i����Ԫ������
       Visit(i,H.elem[i]); // ���ʵ�i������
 }
