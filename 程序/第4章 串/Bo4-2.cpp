 // bo4-2.cpp �����öѷ���洢�ṹ(��c4-2.h����)�Ļ�������(12��)�������㷨4.4

 #define DestroyString ClearString // DestroyString()��ClearString()������ͬ

 void InitString(HString &S)
 { // ��ʼ��(�����մ�)�ַ���S������
   S.length=0;
   S.ch=NULL;
 }

 void ClearString(HString &S)
 { // ��S��Ϊ�մ����ڽ̿����77ҳ
   free(S.ch); // �ͷ�S.ch��ָ�ռ�
   InitString(S); // ��ʼ����S
 }

 void StrAssign(HString &T,char* chars)
 { // ����һ����ֵ���ڴ�����chars�Ĵ�T���ڽ̿����76ҳ
   int i,j;
   if(T.ch) // Tָ��ĳ�洢��Ԫ
     free(T.ch); // �ͷ�Tԭ�д洢�ռ�
   i=strlen(chars); // ��chars�ĳ���i
   if(!i) // chars�ĳ���Ϊ0
     InitString(T); // ���ɿմ�
   else // chars�ĳ��Ȳ�Ϊ0
   { T.ch=(char*)malloc(i*sizeof(char)); // ���䴮�洢�ռ�
     if(!T.ch) // ���䴮�洢�ռ�ʧ��
       exit(OVERFLOW);
     for(j=0;j<i;j++) // ���䴮�洢�ռ�ɹ��󣬸��ƴ�chars[]����T
       T.ch[j]=chars[j];
     T.length=i; // ���´�T�ĳ���
   }
 }

 void StrCopy(HString &T,HString S)
 { // ��ʼ��������S���ڡ�����������ɴ�S���Ƶô�T
   int i;
   if(T.ch) // ��T����
     free(T.ch); // �ͷŴ�Tԭ�д洢�ռ�
   T.ch=(char*)malloc(S.length*sizeof(char)); // ���䴮�洢�ռ�
   if(!T.ch) // ���䴮�洢�ռ�ʧ��
     exit(OVERFLOW);
   for(i=0;i<S.length;i++) // �ӵ�1���ַ������һ���ַ�
     T.ch[i]=S.ch[i]; // ��һ�����ַ�
   T.length=S.length; // ���ƴ���
 }

 Status StrEmpty(HString S)
 { // ��ʼ��������S���ڡ��������������SΪ�գ��򷵻�TRUE�����򷵻�FALSE
   if(S.length==0&&S.ch==NULL) // �մ���־
     return TRUE;
   else
     return FALSE;
 }

 int StrCompare(HString S,HString T)
 { // ����S>��T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0���ڽ̿����77ҳ
   int i;
   for(i=0;i<S.length&&i<T.length;++i) // ����Ч��Χ��
     if(S.ch[i]!=T.ch[i]) // ��һ�Ƚ��ַ�
       return S.ch[i]-T.ch[i]; // ����ȣ��򷵻�2�ַ�ASCII��֮��
   return S.length-T.length; // ����Ч��Χ�ڣ��ַ���ȣ������Ȳ��ȣ����س���֮��
 }

 int StrLength(HString S)
 { // ���ش�S��Ԫ�ظ�������Ϊ���ĳ��ȡ��ڽ̿����77ҳ
   return S.length;
 }

 void Concat(HString &T,HString S1,HString S2)
 { // �ô�T�����ɴ�S1�ʹ�S2���Ӷ��ɵ��´����ڽ̿����77ҳ
   int i;
   if(T.ch) // ��T����
     free(T.ch); // �ͷŴ�Tԭ�д洢�ռ�
   T.length=S1.length+S2.length; // ��T�ĳ���=��S1�ĳ���+��S2�ĳ���
   T.ch=(char*)malloc(T.length*sizeof(char)); // ���䴮T�Ĵ洢�ռ�
   if(!T.ch) // ���䴮�洢�ռ�ʧ��
     exit(OVERFLOW);
   for(i=0;i<S1.length;i++) // ����S1���ַ���һ���Ƹ���T
     T.ch[i]=S1.ch[i];
   for(i=0;i<S2.length;i++) // ����S2���ַ���һ���Ƹ���T(���ڴ�S1���ַ�֮��)
     T.ch[S1.length+i]=S2.ch[i];
 }

 Status SubString(HString &Sub,HString S,int pos,int len)
 { // ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
   // ���У�1��pos��StrLength(S)��0��len��StrLength(S)-pos+1���ڽ̿����77ҳ
   int i;
   if(pos<1||pos>S.length||len<0||len>S.length-pos+1) // pos��len��ֵ������Χ
     return ERROR; // �޷���Sub�����Ӵ�
   if(Sub.ch) // ��Sub����
     free(Sub.ch); // �ͷŴ�Subԭ�д洢�ռ�
   if(!len) // ���Ӵ�
     InitString(Sub); // ��ʼ����Sub
   else // �����Ӵ�
   { Sub.ch=(char*)malloc(len*sizeof(char)); // ���䴮Sub�Ĵ洢�ռ�
     if(!Sub.ch) // ���䴮�洢�ռ�ʧ��
       exit(OVERFLOW);
     for(i=0;i<=len-1;i++) // ����S��pos���ַ��𳤶�Ϊlen���Ӵ����ַ���һ���Ƹ���Sub
       Sub.ch[i]=S.ch[pos-1+i];
     Sub.length=len; // ��Sub�ĳ���
   }
   return OK;
 }

 Status StrInsert(HString &S,int pos,HString T) // �㷨4.4
 { // 1��pos��StrLength(S)+1���ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
   int i;
   if(pos<1||pos>S.length+1) // pos���Ϸ�
     return ERROR;
   if(T.length) // T�ǿ�
   { S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char)); // �ط�S�洢�ռ�
     if(!S.ch) // ���·��䴮S�Ĵ洢�ռ�ʧ��
       exit(OVERFLOW);
     for(i=S.length-1;i>=pos-1;--i) // Ϊ����T���ڳ�λ��
       S.ch[i+T.length]=S.ch[i];
     for(i=0;i<T.length;i++) // ����T
       S.ch[pos-1+i]=T.ch[i];
     S.length+=T.length; // ���´�S�ĳ���
   }
   return OK;
 }

 Status StrDelete(HString &S,int pos,int len)
 { // �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
   int i;
   if(S.length<pos+len-1) // pos��len��ֵ������Χ
     return ERROR;
   for(i=pos-1;i<=S.length-len;i++) // ����ɾ���Ӵ�֮����ַ���һǰ��
     S.ch[i]=S.ch[i+len];
   S.length-=len; // ���´�S�ĳ���
   S.ch=(char*)realloc(S.ch,S.length*sizeof(char)); // ���·��䴮S�Ĵ洢�ռ�(����)
   return OK;
 }

 void StrPrint(HString S)
 { // ����ַ���S������
   int i;
   for(i=0;i<S.length;i++)
     printf("%c",S.ch[i]);
   printf("\n");
 }
