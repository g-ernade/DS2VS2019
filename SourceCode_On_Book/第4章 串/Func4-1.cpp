 // func4-1.cpp ��洢�ṹ�޹ص�������������
 int Index(String S,String T,int pos) // �㷨4.1
 { // TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ���
   // �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
   int n,m,i;
   String sub;
   InitString(sub); // ����
   if(pos>0)
   { n=StrLength(S); // ����S�ĳ���
     m=StrLength(T); // ģʽ��T�ĳ���
     i=pos;
     while(i<=n-m+1) // i�Ӵ�S��pos��������m��
     { SubString(sub,S,i,m); // �Ӵ�sub�Ǵ�����S�ĵ�i���ַ��𣬳���Ϊm���Ӵ�
       if(StrCompare(sub,T)!=0) // �Ӵ�sub������ģʽ��T
         ++i; // �������Ƚ�
       else // �Ӵ�sub����ģʽ��T
         return i; // ����ģʽ��T�ĵ�1���ַ�������S�е�λ��
     }
   }
   return 0; // ����S�в�������ģʽT��ȵ��Ӵ�
 }

 Status Replace(String &S,String T,String V)
 { // ��ʼ��������S��T��V���ڣ���T�Ƿǿմ�
   // ����������ô�V�滻����S�г��ֵ������봮T��ȵĲ��ص����Ӵ�
   int i=1; // �Ӵ�S�ĵ�һ���ַ�����Ҵ�T
   Status k;
   if(StrEmpty(T)) // T�ǿմ�
     return ERROR;
   while(i)
   { i=Index(S,T,i); // ���iΪ����һ��i֮���ҵ����Ӵ�T��λ��
     if(i) // ��S�д��ڴ�T
     { StrDelete(S,i,StrLength(T)); // ɾ����T
       k=StrInsert(S,i,V); // ��ԭ��T��λ�ò��봮V
       if(!k) // ������ȫ����(����˳��洢�ṹ�п��ܷ����������)
         return ERROR;
       i+=StrLength(V); // �ڲ���Ĵ�V����������Ҵ�T
     }
   };
   return OK;
 }
