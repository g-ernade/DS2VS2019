 // func6-4.cpp ��շ��������������
 void main()
 {
   HuffmanTree HT;
   HuffmanCode HC;
   int *w,n,i;
   printf("������Ȩֵ�ĸ���(>1)��");
   scanf("%d",&n);
   w=(int*)malloc(n*sizeof(int)); // ��̬���ɴ��n��Ȩֵ�Ŀռ�
   printf("����������%d��Ȩֵ(����)��\n",n);
   for(i=0;i<=n-1;i++)
     scanf("%d",w+i); // ��������Ȩֵ
   HuffmanCoding(HT,HC,w,n); // ����w�����n��Ȩֵ����շ�����HT��n���շ����������HC
   for(i=1;i<=n;i++)
     puts(HC[i]); // ��������շ�������
 }
