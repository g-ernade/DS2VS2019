 // func7-6.cpp ����������Ϣ���͵Ķ��弰�����Ĳ���
 #define MAX_NAME 9 // �����ַ�������󳤶�+1
 struct VertexType // ������Ϣ����
 { char name[MAX_NAME]; // ��������
   int ve,vl; // (����)�¼����緢��ʱ��,�¼���ٷ���ʱ��
 };

 void Visit(VertexType ver) // ���ʶ������Ƶĺ��������ͼҪ�õ�
 { printf("%s ",ver.name);
 }

 void Input(VertexType &ver) // ���붥����Ϣ�ĺ���������ͼҪ�õ�
 { scanf("%s",ver.name);
 }

 void Visitel(VertexType ver) // �������ve��vl��ĺ���
 { printf("%3d%3d",ver.ve,ver.vl);
 }

 void InputFromFile(FILE* f,VertexType &ver) // ���ļ����붥����Ϣ�ĺ���
 { fscanf(f,"%s",ver.name);
 }
