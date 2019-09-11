 // bo8-1.cpp ��̬���ұ�(˳���������)�Ļ�������(7��)�������㷨9.1��9.2
 void Creat_SeqFromFile(SSTable &ST,char* filename)
 { // ����������������ļ����쾲̬˳����ұ�ST
   int i;
   FILE *f; // �ļ�ָ������
   f=fopen(filename,"r"); // �������ļ�������f��ʾ
   fscanf(f,"%d",&ST.length); // ���ļ���������Ԫ�ظ���
   ST.elem=(ElemType*)calloc(ST.length+1,sizeof(ElemType));
   // ��̬����ST.length+1������Ԫ�ؿռ�(0�ŵ�Ԫ����)
   if(!ST.elem) // ����ʧ��
     exit(OVERFLOW);
   for(i=1;i<=ST.length;i++)
     InputFromFile(f,ST.elem[i]);
     // ���ļ��������뾲̬˳����ұ�ST������Ԫ�أ���func8-1.cpp��
   fclose(f); // �ر������ļ�
 }

 void Ascend(SSTable &ST)
 { // �ؽ���̬���ұ�Ϊ���ؼ��ַǽ�������
   int i,j,k;
   for(i=1;i<ST.length;i++)
   { k=i; // k�浱ǰ�ؼ�����Сֵ�����
     ST.elem[0]=ST.elem[i]; // ���Ƚ�ֵ��[0]��Ԫ
     for(j=i+1;j<=ST.length;j++) // ��Ԫ��[i]֮�����
       if LT(ST.elem[j].key,ST.elem[0].key) // ��ǰԪ�صĹؼ���С�ڴ��Ƚ�Ԫ�صĹؼ���
       { k=j; // ����ǰԪ�ص���Ŵ���k
         ST.elem[0]=ST.elem[j]; // ����ǰԪ�ص�ֵ��[0]��Ԫ
       }
     if(k!=i) // �б�[i]��С��ֵ�򽻻�
     { ST.elem[k]=ST.elem[i];
       ST.elem[i]=ST.elem[0];
     }
   }
 }

 void Creat_OrdFromFile(SSTable &ST,char* filename)
 { // ����������ɺ�n������Ԫ�ص�����r���찴�ؼ��ַǽ�����ұ�ST
   Creat_SeqFromFile(ST,filename); // ��������Ĳ��ұ�ST
   Ascend(ST); // ������Ĳ��ұ�ST�ؽ�Ϊ���ؼ��ַǽ�����ұ�
 }

 Status Destroy(SSTable &ST)
 { // ��ʼ��������̬���ұ�ST���ڡ�������������ٱ�ST
   free(ST.elem); // �ͷŶ�̬�洢�ռ�
   ST.elem=NULL; // ָ�����ÿ�
   ST.length=0; // ��Ϊ0
   return OK;
 }

 int Search_Seq(SSTable ST,KeyType key)
 { // ��˳���ST��˳����������ؼ��ֵ���key������Ԫ�ء�
   // ���ҵ����򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0���㷨9.1
   int i;
   ST.elem[0].key=key; // �ڱ����ؼ��ִ�[0]��Ԫ
   for(i=ST.length;!EQ(ST.elem[i].key,key);--i); // �Ӻ���ǰ��
   return i; // �Ҳ���ʱ��iΪ0
 }

 int Search_Bin(SSTable ST,KeyType key)
 { // �������ST���۰���������ؼ��ֵ���key������Ԫ�ء�
   // ���ҵ����򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0���㷨9.2
   int mid,low=1,high=ST.length; // �������ֵ
   while(low<=high) // ���ҷ�Χ����0
   { mid=(low+high)/2; // ��ֵ
     if EQ(key,ST.elem[mid].key) // ��ֵ�Ǵ�����Ԫ��
       return mid; // ���������
     else if LT(key,ST.elem[mid].key) // �ؼ���С����ֵ
       high=mid-1; // ������ǰ��������в���
     else
       low=mid+1; // �����ں��������в���
   }
   return 0; // ˳����в����ڴ�����Ԫ��
 }

 void Traverse(SSTable ST,void(*Visit)(ElemType))
 { // ��ʼ��������̬���ұ�ST���ڣ�Visit()�Ƕ�Ԫ�ز�����Ӧ�ú���
   // �����������˳���ST��ÿ��Ԫ�ص��ú���Visit()1���ҽ�1��
   int i;
   ElemType *p=++ST.elem; // pָ���1��Ԫ��
   for(i=1;i<=ST.length;i++) // ���ζ�����Ԫ��
     Visit(*p++); // ���ú���Visit()��pָ����һ��Ԫ��
 }
