 // algo8-3.cpp ��̬���ұ�(��̬����)�Ĳ����������㷨9.3��9.4
 #include"c1.h"
 #include"func8-3.cpp" // ��������Ԫ�����͵Ķ��弰�����Ĳ���
 #include"c8-1.h" // ��̬���ұ��˳��洢�ṹ
 #include"c8-2.h" // ��������ֵ�͹ؼ��ֱȽϵ�Լ��
 #include"bo8-1.cpp" // ��̬���ұ�(˳���������)�Ļ�������(7��)
 typedef ElemType TElemType; // �����������Ԫ������Ϊ����Ԫ������
 #include"c6-2.h" // ��������Ĵ洢�ṹ
 #include"bo6-2.cpp" // ����InitBiTree()��DestroyBiTree()��InOrderTraverse()����
 #define N 100 // ��̬���ұ������������sw[]�����õ�
 Status SecondOptimal(BiTree &T,ElemType R[],int sw[],int low,int high)
 { // �������R[low..high]�����ۼ�Ȩֵ��sw(����sw[0]==0)�ݹ鹹����Ų�����T���㷨9.3
   int j,i=low; // ����С��Piֵ����ţ���ֵ��Ϊ��low==high(������1��Ԫ��)ʱ��ֵ
   double dw=sw[high]+sw[low-1]; // �̿���ʽ9-13�еĹ̶���
   double min=fabs(sw[high]-sw[low]); // ��Pi����Сֵ����ֵ��Ϊ��low==highʱ��ֵ
   for(j=low+1;j<=high;++j) // ��low��highʱ��ѡ����С�ġ�Piֵ
     if(fabs(dw-sw[j]-sw[j-1])<min) // �ҵ�С��min��ֵ
     { i=j; // ��������С��Piֵ�����
       min=fabs(dw-sw[j]-sw[j-1]); // ���¡�Pi����Сֵ
     }
   if(!(T=(BiTree)malloc(sizeof(BiTNode)))) // ���ɽ��ʧ��
     return ERROR;
   T->data=R[i]; // ������С��Piֵ������Ԫ�ظ���������������
   if(i==low) // ����С��Piֵ���������С���
     T->lchild=NULL; // ����������
   else // ����С��Piֵ����Ų�����С���
     SecondOptimal(T->lchild,R,sw,low,i-1); // �ݹ鹹����Ų���������
   if(i==high) // ����С��Piֵ�������������
     T->rchild=NULL; // ����������
   else // ����С��Piֵ����Ų���������
     SecondOptimal(T->rchild,R,sw,i+1,high); // �ݹ鹹����Ų���������
   return OK;
 }

 void FindSW(int sw[],SSTable ST)
 { // ���������ST�и�����Ԫ�ص�Weight�����ۼ�Ȩֵ����sw��CreateSOSTree()����
   int i;
   sw[0]=0; // �ñ߽�ֵ
   printf("\nsw=0 ");
   for(i=1;i<=ST.length;i++) // ��С��������ۼ�Ȩֵsw[i]�����
   { sw[i]=sw[i-1]+ST.elem[i].weight; // �ۼ�Ȩֵ[i]=�ۼ�Ȩֵ[i-1]+[i]��Ȩֵ
     printf("%5d",sw[i]);
   }
 }

 typedef BiTree SOSTree; // ���Ų��������ö�������Ĵ洢�ṹ
 void CreateSOSTree(SOSTree &T,SSTable ST)
 { // �������ST����һ�ô��Ų�����T��ST������Ԫ�غ���Ȩ��weight���㷨9.4
   int sw[N+1]; // �ۼ�Ȩֵ����
   if(ST.length==0) // ST�ǿձ�
     T=NULL; // ���Ų�����TΪ��
   else // ST����
   { FindSW(sw,ST); // ���������ST�и�����Ԫ�ص�weight�����ۼ�Ȩֵ��sw
     SecondOptimal(T,ST.elem,sw,1,ST.length);
     // �������ST[1..ST.length]�����ۼ�Ȩֵ��sw(����sw[0]==0)�ݹ鹹����Ų�����T
   }
 }

 Status Search_SOSTree(SOSTree &T,KeyType key)
 { // �ڴ��Ų�����T�в������ؼ��ֵ���key��Ԫ�ء��ҵ��򷵻�OK��Tָ���Ԫ�أ����򷵻�FALSE
   while(T) // T�ǿ�
     if(T->data.key==key) // ��T�����ؼ������ֵ����key
       return OK; // �ҵ�������OK
     else if(T->data.key>key) // ��T�����ؼ������ֵ����key
       T=T->lchild; // Tָ��T������������������
     else // ��T�����ؼ������ֵС��key
       T=T->rchild; // Tָ��T������������������
   return FALSE; // ���Ų�����T�в����ڴ���Ԫ��
 }

 void main()
 {
   SSTable st;
   SOSTree t;
   Status i;
   KeyType s;
   Creat_OrdFromFile(st,"f8-3.txt"); // �������ļ������ǽ���̬���ұ�st
   printf("       ");
   Traverse(st,Visit); // ˳������ǽ���̬���ұ�st
   CreateSOSTree(t,st); // �������st������Ų�����t
   printf("\n����������ҵ��ַ���");
   InputKey(s); // �ɼ�������ؼ���s����func8-3.cpp��
   i=Search_SOSTree(t,s); // �ڴ��Ų�����t�в������ؼ��ֵ���s��Ԫ��
   if(i) // �ҵ�������OK��tָ���Ԫ��
     printf("%c��Ȩֵ��%d\n",s,t->data.weight);
   else // δ�ҵ�������FALSE
     printf("���в����ڴ��ַ�\n");
   DestroyBiTree(t); // ������ϣ����ٴ��Ų�����t
 }
