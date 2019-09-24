#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define MaxSize 100 

typedef int dataType;
typedef struct {
	dataType data[MaxSize];
	int size;
} SqList;

//����˳��� 
SqList* CreateList() {
	SqList* t = (SqList*)malloc(sizeof(SqList));
	t->size = 0;
	return t;
}

//��˳���ĵ�k��λ�ò���Ԫ��x 
void Insert(SqList* l, int k, dataType x) {
	if (k < 1 || k > l->size + 1) exit(1);
	if (l->size == MaxSize) exit(1);
	for (int i = l->size; i >= k; i--)
		l->data[i] = l->data[i - 1];
	l->data[k - 1] = x;
	l->size++;
}

//ɾ��˳���ĵ�k��Ԫ��
void Delete(SqList* l, int k) {
	if (k < 1 || k > l->size) exit(1);
	for (int i = k; i < l->size; i++)
		l->data[i - 1] = l->data[i];
	l->size--;
}

//�ж�˳����Ƿ�Ϊ��
int Empty(SqList* l) {
	return l->size == 0;
}

//�ж�˳����Ƿ���
int Full(SqList* l) {
	return l->size == MaxSize;
}


//��˳����i��Ԫ�ص�ֵ
dataType GetData(SqList* l, int i) {
	if (i < 1 || i > l->size) exit(1);
	return l->data[i-1];
}

//����ֵΪx��Ԫ��
int Locate(SqList* l, dataType x) {
	for (int i = 0; i < l->size; i++)
		if (l->data[i] ==  x)
			return i + 1;
	return 0;
}








//���˳��� 
void Print(SqList* l) {
	for (int i = 0; i < l->size; i++)
		printf("%d ", l->data[i]);
	printf("\n");
}

int main() {
	SqList* pl = CreateList();
	Insert(pl, 1, 10); // ��ʱ˳������� 10
	Insert(pl, 1, 20); // ��ʱ˳������� 20 10 �ڶ�λ�� 10
	Delete(pl, 2); // ��ʱ˳������� 20
	Insert(pl, 1, 30); // ��ʱ˳������� 30 20 �ڶ�λ�� 20
	Insert(pl, 1, 40); // ��ʱ˳������� 40 30 20 �ڶ�λ�� 30
	Print(pl);
	printf("%d", GetData(pl, 2));
}
