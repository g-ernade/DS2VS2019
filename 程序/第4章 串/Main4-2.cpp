 // main4-2.cpp ����bo4-2.cpp��������
 #include"c1.h"
 #include"c4-2.h" // ���Ķѷ���洢�ṹ
 #include"bo4-2.cpp" // �����öѷ���洢�ṹ�Ļ�������(12��)
 typedef HString String; // ���������������StringΪHString����
 #include"func4-1.cpp" // ��洢�ṹ�޹ص�������������
 void main()
 {
   int i;
   char c,*p="God bye!",*q="God luck!";
   HString t,s,r;
   InitString(t); // HString���ͱ����ʼ��
   InitString(s);
   InitString(r);
   StrAssign(t,p); // ���ַ���p������ת��HString���ͣ�����t
   printf("��tΪ");
   StrPrint(t); // �����t
   printf("����Ϊ%d�����շ�%d(1:�� 0:��)\n",StrLength(t),StrEmpty(t));
   StrAssign(s,q); // ���ַ���q������ת��HString���ͣ�����s
   printf("��sΪ");
   StrPrint(s); // �����s
   i=StrCompare(s,t); // �Ƚϴ�s�ʹ�t�Ĵ�С
   if(i<0)
     c='<';
   else if(i==0)
     c='=';
   else
     c='>';
   printf("��s%c��t\n",c);
   Concat(r,t,s); // ���Ӵ�t�ʹ�s���õ���r
   printf("��t���Ӵ�s�����Ĵ�rΪ");
   StrPrint(r); // �����r
   StrAssign(s,"oo"); // ���ַ���"oo"ת��HString���ͣ�����s
   printf("��sΪ");
   StrPrint(s); // �����s
   StrAssign(t,"o"); // ���ַ���"o"ת��HString���ͣ�����t
   printf("��tΪ");
   StrPrint(t); // �����t
   Replace(r,t,s); // ����r�кʹ�t��ͬ���Ӵ��ô�s����
   printf("�Ѵ�r�кʹ�t��ͬ���Ӵ��ô�s����󣬴�rΪ");
   StrPrint(r); // �����r
   ClearString(s); // ��մ�s
   printf("��s��պ󣬴���Ϊ%d���շ�%d(1:�� 0:��)\n",StrLength(s),StrEmpty(s));
   SubString(s,r,6,4); // ���ɵĴ�sΪ�Ӵ�r�ĵ�6���ַ����4���ַ�
   printf("��sΪ�Ӵ�r�ĵ�6���ַ����4���ַ�������Ϊ%d����sΪ",s.length);
   StrPrint(s); // �����s
   StrCopy(t,r); // �ɴ�r���Ƶô�t
   printf("�ɴ�r���Ƶô�t����tΪ");
   StrPrint(t); // �����t
   StrInsert(t,6,s); // �ڴ�t�ĵ�6���ַ�ǰ���봮s
   printf("�ڴ�t�ĵ�6���ַ�ǰ���봮s�󣬴�tΪ");
   StrPrint(t); // �����t
   StrDelete(t,1,5); // �Ӵ�t�ĵ�1���ַ���ɾ��5���ַ�
   printf("�Ӵ�t�ĵ�1���ַ���ɾ��5���ַ��󣬴�tΪ");
   StrPrint(t); // �����t
   printf("%d�ǴӴ�t�ĵ�1���ַ��𣬺ʹ�s��ͬ�ĵ�1���Ӵ���λ��\n",Index(t,s,1));
   printf("%d�ǴӴ�t�ĵ�2���ַ��𣬺ʹ�s��ͬ�ĵ�1���Ӵ���λ��\n",Index(t,s,2));
   DestroyString(t); // ���ٲ���ͬ���
 }
