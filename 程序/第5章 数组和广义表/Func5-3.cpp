 // func5-3.cpp��������д��ʽ��ΪSString���ͣ������㷨5.8��bo5-5.cpp��bo5-6.cpp����
 #include"c4-1.h" // ����SString����
 #include"bo4-1.cpp" // SString���͵Ļ�������
 void sever(SString str,SString hstr) // �㷨5.8��SString�����飬����Ҫ��������
 { // ����ȥ������ŵķǿմ�str�ָ�������֣�hstrΪ��һ��','֮ǰ���Ӵ���strΪ֮����Ӵ�
   int n,k=0,i=0; // k����δ��Ե������Ÿ���
   SString ch,c1,c2,c3;
   StrAssign(c1,","); // c1=','
   StrAssign(c2,"("); // c2='('
   StrAssign(c3,")"); // c3=')'
   n=StrLength(str); // nΪ��str�ĳ���
   do // ���������(k=0ʱ)�ĵ�1������
   { ++i;
     SubString(ch,str,i,1); // chΪ��str�ĵ�i���ַ�
     if(!StrCompare(ch,c2)) // ch='('
       ++k; // ��δ��Ե������Ÿ���+1
     else if(!StrCompare(ch,c3)) // ch=')'
       --k; // ��δ��Ե������Ÿ���-1
   }while(i<n&&StrCompare(ch,c1)||k!=0); // iС�ڴ�����ch����������','
   if(i<n) // ��str�д���������','�����ǵ�i���ַ�
   { SubString(hstr,str,1,i-1); // hstr���ش�str','ǰ���ַ�
     SubString(str,str,i+1,n-i); // str���ش�str','����ַ�
   }
   else // ��str�в�����','
   { StrCopy(hstr,str); // ��hstr���Ǵ�str
     ClearString(str); // ','�����ǿմ�
   }
 }
