 // bo9-2.cpp ��������ĺ����������㷨10.7��10.8
 void QSort(SqList &L,int low,int high)
 { // ��˳���L�е�������L.r[low..high]�����������㷨10.7
   int pivotloc;
   if(low<high) // �����г��ȴ���1
   { pivotloc=Partition(L,low,high);
     // ��L.r[low..high]���ؼ���һ��Ϊ����pivotloc������λ��
     QSort(L,low,pivotloc-1); // �Թؼ���С������ؼ��ֵĵ��ӱ�ݹ��������
     QSort(L,pivotloc+1,high); // �Թؼ��ִ�������ؼ��ֵĸ��ӱ�ݹ��������
   }
 }

 void QuickSort(SqList &L)
 { // ��˳���L�����������㷨10.8
   QSort(L,1,L.length); // ������˳���L����������
 }
