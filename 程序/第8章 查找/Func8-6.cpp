 // func8-6.cpp ������B_���������������
 void Visit(BTNode c,int i) // TraverseDSTable()���õ���֮���׵ķ��ʼ�¼�ĺ���
 { printf("(%d,%d)",c.recptr[i]->key,c.recptr[i]->others.order);
 }

 void InputKey(KeyType &k) // ��֮���׵��ɼ�������ؼ��ֵĺ���
 { scanf("%d",&k);
 }
