 // main4-1.cpp ����bo4-1.cpp��������
 #include"c1.h"
 #include"c4-1.h" // ���Ķ���˳��洢�ṹ
 #include"bo4-1.cpp" // ����˳��洢�ṹ�Ļ�������(12��)
 typedef SString String; // ���������������StringΪSString����
 #include"func4-1.cpp" // ��洢�ṹ�޹ص�������������

 void main()
 {
   int i,j;
   Status k;
   char s,c[MAX_STR_LEN+1]; // c�а�����������
   SString t,s1,s2;
   printf("�����봮s1��");
   gets(c); // �ɼ��������ַ�����c
   k=StrAssign(s1,c); // ���ַ���cתΪSString���ͣ�����s1
   if(!k) // ��������c�ĳ������ޣ���������MAX_STR_LEN�����󲻻ᷢ��
   { printf("��������MAX_STR_LEN(=%d)\n",MAX_STR_LEN);
     exit(OVERFLOW);
   }
   printf("����Ϊ%d�����շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
   StrCopy(s2,s1); // ���ƴ�s1���ɴ�s2
   printf("����s1���ɵĴ�Ϊ");
   StrPrint(s2); // �����s2
   printf("�����봮s2��");
   gets(c); // �ɼ��������ַ�����c
   StrAssign(s2,c); // ���ַ���cתΪSString���ͣ�����s1���ɲ�Ҫ����ֵ
   i=StrCompare(s1,s2); // �Ƚϴ�s1�ʹ�s2
   if(i<0)
     s='<';
   else if(i==0)
     s='=';
   else
     s='>';
   printf("��s1%c��s2\n",s);
   k=Concat(t,s1,s2); // �ɴ�s1���Ӵ�s2���ɴ�t
   printf("��s1���Ӵ�s2�õ��Ĵ�tΪ");
   StrPrint(t); // �����t
   if(k==FALSE)
     printf("��t�нض�\n");
   ClearString(s1); // ��մ�s1
   printf("��Ϊ�մ��󣬴�s1Ϊ");
   StrPrint(s1); // �����s1
   printf("����Ϊ%d�����շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
   printf("��t���Ӵ����������Ӵ�����ʼλ��,�Ӵ����ȣ�");
   scanf("%d,%d",&i,&j);
   k=SubString(s2,t,i,j); // ��s2Ϊ��t�ĵ�i���ַ��𣬳���Ϊj���Ӵ�
   if(k) // ��s2����
   { printf("�Ӵ�s2Ϊ");
     StrPrint(s2); // �����s2
   }
   printf("�Ӵ�t�ĵ�pos���ַ���ɾ��len���ַ���������pos,len��");
   scanf("%d,%d",&i,&j);
   StrDelete(t,i,j); // ����t�ĵ�i���ַ����j���ַ�ɾ��
   printf("ɾ����Ĵ�tΪ");
   StrPrint(t); // �����t
   i=StrLength(s2)/2; // iΪ��s2���ȵ�һ��ȡ��
   StrInsert(s2,i,t); // �ڴ�s2�ĵ�i���ַ�֮ǰ���봮t
   printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t�󣬴�s2Ϊ",i);
   StrPrint(s2); // �����s2
   i=Index1(s2,t,1); // �Ӵ�s2�ĵ�1���ַ�����Ҵ�t
   printf("s2�ĵ�%d���ַ����t��һ��ƥ��\n",i);
   i=Index(s2,t,1); // �Ӵ�s2�ĵ�1���ַ�����Ҵ�t(��һ�ַ���)
   printf("s2�ĵ�%d���ַ����t��һ��ƥ��\n",i);
   SubString(t,s2,1,1); // ��tΪ��s2�ĵ�1���ַ�
   printf("��tΪ");
   StrPrint(t); // �����t
   Concat(s1,t,t); // ��s1Ϊ2����t
   printf("��s1Ϊ");
   StrPrint(s1); // �����s1
   k=Replace(s2,t,s1); // ����s2�е����в��ص��Ĵ�t���ô�s1�滻
   if(k) // �滻�ɹ�
   { printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ��󣬴�s2Ϊ");
     StrPrint(s2); // �����s2
   }
   DestroyString(s2); // ���ٲ�������ղ���������ͬ
 }
