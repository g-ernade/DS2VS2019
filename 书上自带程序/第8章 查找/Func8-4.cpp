 // func8-4.cpp �����㷨9.5(a)��bo6-2.cpp��algo8-4.cpp��algo8-5.cpp����
 #include"bo6-2.cpp" // ����InitBiTree()��DestroyBiTree()��InOrderTraverse()����
 #define InitDSTable InitBiTree // ���������������ƽ����������ʼ���������Ĳ���ͬ
 #define DestroyDSTable DestroyBiTree // ���ٶ�����������ƽ������������ٶ������Ĳ���ͬ
 #define TraverseDSTable InOrderTraverse
 // ���ؼ���˳�����������������ƽ�����������������������Ĳ���ͬ

 BiTree SearchBST(BiTree T,KeyType key)
 { // �ڸ�ָ��T��ָ������������ƽ��������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ�أ�
   // �����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ�롣�㷨9.5(a)
   if(!T||EQ(key,T->data.key)) // ��T�ջ�����ҵĹؼ��ֵ���T��ָ���Ĺؼ���
     return T; // ���ҽ���������ָ��T
   else if LT(key,T->data.key) // �����ҵĹؼ���С��T��ָ���Ĺؼ���
     return SearchBST(T->lchild,key); // ���������м����ݹ����
   else // �����ҵĹؼ��ִ���T��ָ���Ĺؼ���
     return SearchBST(T->rchild,key); // ���������м����ݹ����
 }
