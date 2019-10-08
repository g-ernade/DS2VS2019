#include<stdio.h>
#include<stdlib.h>
typedef struct node { 
	int data;
	struct node* next;
}  Lnode;
Lnode* create(int n)
{
	int i;
	Lnode* h, * p, * r = (Lnode*)malloc(sizeof(Lnode)); //*建立三个结构体指针*h*p*r,分别分配给r一个Lnode类型大小的内存空间，并把分配空间的首地址强制转换成Lnode *类型的*
	r->data = n;h = r;						//*把n赋值给节点r的data,另*r与*h都指向尾结点*
	for (i = n - 1; i > 0; i--)
	{
		p = (Lnode*)malloc(sizeof(Lnode));	//*分别分配给p一个Lnode类型大小的内存空间，并把分配空间的首地址强制转换成Lnode *类型的*
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

	if (m == 1) {  //*修复m=1时死循环的算法设计逻辑错误*
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
			q = p->next;			//*把p的后继节点赋值为q*
			p->next = q->next;		//*q的后继节点,也就是原来p的后继的后继节点,赋值给p的后继节点,相当于跳过原先p的后继节点*

			printf(" %d  ", q->data);
			j = 0; free(q);			//*计数清零,释放原先p的后继节点的内存*
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


