 // algo5-1.cpp �䳤������(������ʵ�θ����ɱ�)���ʾ��
 #include"c1.h"
 typedef int ElemType; // ����ElemTypeΪ����
 ElemType Max(int num,...) // �������ܣ�����num�����е����ֵ
 { // ��...����ʾ�䳤������λ���βα�����ǰ�����������һ���̶�����
   va_list ap; // ����ap�Ǳ䳤����������(C���Ե���������)����stdarg.h��
   int i;
   ElemType m,n;
   if(num<1)
     exit(OVERFLOW);
   va_start(ap,num); // apָ��̶�����num�����ʵ�α�
   m=va_arg(ap,ElemType); // ��ȡap��ָ��ʵ�Σ�������ΪElemType�����丳��m��ap�����
   for(i=1;i<num;++i) // �ӵ�2���������һ����
   { n=va_arg(ap,ElemType); // ���ζ�ȡap��ָ��ʵ�Σ����丳��n��ap�����
     if(m<n)
       m=n; // m�д�����ֵ
   }
   va_end(ap); // ��va_start()��ԣ������Ա䳤������Ķ�ȡ��ap����ָ��䳤������
   return m; // �����ֵ����
 }

 void main()
 {
  printf("1.���ֵΪ%d\n",Max(4,7,9,5,8)); // ��4�����������ֵ��ap���ָ��7
  printf("2.���ֵΪ%d\n",Max(3,17,36,25)); // ��3�����������ֵ��ap���ָ��17
 }
