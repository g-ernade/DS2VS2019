 // func7-2.cpp ������(��)�������Ϣ���͵Ķ��弰�����Ĳ���
 #define MAX_INFO 20 // ��(��)�������Ϣ�ַ�������󳤶�+1
 typedef char InfoType; // ��(��)�������Ϣ����

 void InputArc(InfoType* &arc) // ��֮���׵����뻡(��)�������Ϣ�ĺ���
 { char s[MAX_INFO]; // ��ʱ�洢�ռ�
   int m;
   printf("������û�(��)�������Ϣ(<%d���ַ�)��",MAX_INFO);
   gets(s); // �����ַ���(�ɰ����ո�)
   m=strlen(s); // �ַ�������
   if(m) // ���Ȳ�Ϊ0
   { arc=(char*)malloc((m+1)*sizeof(char)); // ��̬���������Ϣ�洢�ռ�
     strcpy(arc,s); // ����s��arc
   }
 }

 void InputArcFromFile(FILE* f,InfoType* &arc) // ���ļ����뻡(��)�������Ϣ�ĺ���
 { char s[MAX_INFO]; // ��ʱ�洢�ռ�
   fgets(s,MAX_INFO,f); // ���ļ������ַ���(�ɰ����ո�)
   arc=(char*)malloc((strlen(s)+1)*sizeof(char)); // ��̬���������Ϣ�洢�ռ�
   strcpy(arc,s); // ����s��arc
 }

 void OutputArc(InfoType* arc) // ��֮���׵������(��)�������Ϣ�ĺ���
 { printf("%s\n",arc);
 }
