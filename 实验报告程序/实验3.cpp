#include<stdio.h>
#include<stdlib.h>
typedef struct node { 
	int data;
	struct node* next;
}  Lnode;
Lnode* create(int n)
{
	int i;
	Lnode* h, * p, * r = (Lnode*)malloc(sizeof(Lnode)); //*���������ṹ��ָ��*h*p*r,�ֱ�����rһ��Lnode���ʹ�С���ڴ�ռ䣬���ѷ���ռ���׵�ַǿ��ת����Lnode *���͵�*
	r->data = n;h = r;						//*��n��ֵ���ڵ�r��data,��*r��*h��ָ��β���*
	for (i = n - 1; i > 0; i--)
	{
		p = (Lnode*)malloc(sizeof(Lnode));	//*�ֱ�����pһ��Lnode���ʹ�С���ڴ�ռ䣬���ѷ���ռ���׵�ַǿ��ת����Lnode *���͵�*
		p ->data = i;
		p->next = h;
		h = p;
	}
	r->next = h;   return h;
}

void jeseph(Lnode* p, int m)
{
	Lnode* q; int j = 0;
	printf("outqueue order : ");

	if (m == 1) {  //*�޸�m=1ʱ��ѭ�����㷨����߼�����*
		do {
			printf(" %d  ", p->data);
			p = p->next;
		} while (((p->next)->data) != 1);
		printf(" %d  ", p->data);
		exit(0);
	};


	do {
		j++;
		if (j == m-1)
		{
			q = p->next;			//*��p�ĺ�̽ڵ㸳ֵΪq*
			p->next = q->next;		//*q�ĺ�̽ڵ�,Ҳ����ԭ��p�ĺ�̵ĺ�̽ڵ�,��ֵ��p�ĺ�̽ڵ�,�൱������ԭ��p�ĺ�̽ڵ�*

			printf(" %d  ", q->data);
			j = 0; free(q);			//*��������,�ͷ�ԭ��p�ĺ�̽ڵ���ڴ�*
		}	

		p = p->next;
	} while (p->next != p);
	printf(" %d\n", p->data);
	free(p);
}
void main()
{
	Lnode* h; int m, n;
	printf("\n input n, m = ");
	scanf(" %d, %d", &n, &m);
	h = create(n);
	jeseph(h, m);
}


