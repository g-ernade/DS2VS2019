#pragma once
#include"Basic.h"
//������ԭc4-1.h,bo4-1.cpp
// c4-1.h ���Ķ���˳��洢�ṹ���ڽ̿����73ҳ
#define MAX_STR_LEN 40 // �û�����255(1���ֽ����ܱ�ʾ���������)���ڶ�����󴮳�
typedef unsigned char SString[MAX_STR_LEN + 1]; // 0�ŵ�Ԫ��Ŵ��ĳ���
typedef SString String;
 // bo4-1.cpp �����ö���˳��洢�ṹ(��c4-1.h����)�Ļ�������(12��)��
 // �����㷨4.2��4.3��4.5��SString�����飬�ʲ���Ҫ��������
#define DestroyString ClearString // DestroyString()��ClearString()������ͬ
#define InitString ClearString // InitString()��ClearString()������ͬ
Status StrAssign(SString T, char* chars)
{ // ����һ����ֵ����chars�Ĵ�T
	int i;
	if (strlen(chars) > MAX_STR_LEN) // chars�ĳ��ȴ�����󴮳�
		return ERROR;
	else
	{
		T[0] = strlen(chars); // 0�ŵ�Ԫ��Ŵ��ĳ���
		for (i = 1; i <= T[0]; i++) // ��1�ŵ�Ԫ���ƴ�������
			T[i] = *(chars + i - 1);
		return OK;
	}
}

void StrCopy(SString T, SString S)
{ // �ɴ�S���Ƶô�T
	int i;
	for (i = 0; i <= S[0]; i++)
		T[i] = S[i];
}

Status StrEmpty(SString S)
{ // ��SΪ�մ����򷵻�TRUE�����򷵻�FALSE
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}

int StrCompare(SString S, SString T)
{ // ��ʼ��������S�ʹ�T����
  // �����������S>T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; ++i)
		if (S[i] != T[i])
			return S[i] - T[i];
	return S[0] - T[0];
}

int StrLength(SString S)
{ // ���ش�S��Ԫ�ظ���
	return S[0];
}

void ClearString(SString S)
{ // ��ʼ��������S���ڡ������������S��Ϊ�մ�
	S[0] = 0; // ���Ϊ��
}

Status Concat(SString T, SString S1, SString S2) // �㷨4.2�޸�
{ // ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE�����򷵻�FALSE
	int i;
	if (S1[0] + S2[0] <= MAX_STR_LEN) // δ�ض�
	{
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	}
	else // �ض�S2
	{
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= MAX_STR_LEN - S1[0]; i++) // ������Ϊֹ
			T[S1[0] + i] = S2[i];
		T[0] = MAX_STR_LEN;
		return FALSE;
	}
}

Status SubString(SString Sub, SString S, int pos, int len)
{ // ��Sub���ش�S���Ե�pos���ַ��𳤶�Ϊlen���Ӵ����㷨4.3
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1) // pos��len��ֵ������Χ
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub[i] = S[pos + i - 1];
	Sub[0] = len;
	return OK;
}

int Index1(SString S, SString T, int pos)
{ // �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ�����ֵΪ0��
  // ���У�T�ǿգ�1��pos��StrLength(S)���㷨4.5
	int i, j; // ָʾ����S���Ӵ�T�ĵ�ǰ�Ƚ��ַ�
	if (1 <= pos && pos <= S[0]) // pos�ķ�Χ����
	{
		i = pos; // ������S�ĵ�pos���ַ���ʼ���Ӵ�T�ĵ�1���ַ��Ƚ�
		j = 1;
		while (i <= S[0] && j <= T[0])
			if (S[i] == T[j]) // ��ǰ���ַ����
			{
				++i; // �����ȽϺ���ַ�
				++j;
			}
			else // ��ǰ���ַ������
			{
				i = i - j + 2; // ��ָ��������¿�ʼƥ��
				j = 1;
			}
		if (j > T[0]) // ����S�д����Ӵ�T
			return i - T[0];
		else // ����S�в������Ӵ�T
			return 0;
	}
	else // pos�ķ�Χ������
		return 0;
}

Status StrInsert(SString S, int pos, SString T)
{ // ��ʼ��������S��T���ڣ�1��pos��StrLength(S)+1
  // ����������ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE�����ֲ��뷵��FALSE
	int i;
	if (pos<1 || pos>S[0] + 1) // pos������Χ
		return ERROR;
	if (S[0] + T[0] <= MAX_STR_LEN) // ��ȫ����
	{
		for (i = S[0]; i >= pos; i--) // �ƶ���S��λ��pos֮����ַ�
			S[i + T[0]] = S[i]; // ��S����ƴ�T�ĳ��ȣ�Ϊ���봮T׼���ռ�
		for (i = pos; i < pos + T[0]; i++) // �ڴ�S�в��봮T
			S[i] = T[i - pos + 1];
		S[0] += T[0]; // ���´�S�ĳ���
		return TRUE; // ��ȫ����ı��
	}
	else // ���ֲ���
	{
		for (i = MAX_STR_LEN; i >= pos + T[0]; i--) // �ƶ���S��λ��pos֮�����ƺ����ڴ��ڵ��ַ�
			S[i] = S[i - T[0]];
		for (i = pos; i < pos + T[0] && i <= MAX_STR_LEN; i++) // �ڴ�S�в��봮T(Ҳ�����ǲ��ֲ���)
			S[i] = T[i - pos + 1];
		S[0] = MAX_STR_LEN; // ��S�ĳ���Ϊ������󳤶�
		return FALSE; // ���ֲ���ı��
	}
}

Status StrDelete(SString S, int pos, int len)
{ // ��ʼ��������S���ڣ�1��pos��StrLength(S)-len+1
  // ����������Ӵ�S��ɾ���Ե�pos���ַ��𳤶�Ϊlen���Ӵ�
	int i;
	if (pos<1 || pos>S[0] - len + 1 || len < 0) // pos��len��ֵ������Χ
		return ERROR; // ɾ�����ɹ��ı��
	for (i = pos + len; i <= S[0]; i++) // ����ɾ�����Ӵ�֮��������ַ�
		S[i - len] = S[i]; // ��ǰ�ƶ�ɾ���Ӵ��ĳ���
	S[0] -= len; // ���´�S�ĳ���
	return OK; // ɾ���ɹ��ı��
}
void StrPrint(SString S)
{ // ����ַ���S������
	int i;
	for (i = 1; i <= S[0]; i++)
		printf("%c", S[i]);
	printf("\n");
}

int Index(String S, String T, int pos) // �㷨4.1
{ // TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ���
  // �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
	int n, m, i;
	String sub;
	InitString(sub); // ����
	if (pos > 0)
	{
		n = StrLength(S); // ����S�ĳ���
		m = StrLength(T); // ģʽ��T�ĳ���
		i = pos;
		while (i <= n - m + 1) // i�Ӵ�S��pos��������m��
		{
			SubString(sub, S, i, m); // �Ӵ�sub�Ǵ�����S�ĵ�i���ַ��𣬳���Ϊm���Ӵ�
			if (StrCompare(sub, T) != 0) // �Ӵ�sub������ģʽ��T
				++i; // �������Ƚ�
			else // �Ӵ�sub����ģʽ��T
				return i; // ����ģʽ��T�ĵ�1���ַ�������S�е�λ��
		}
	}
	return 0; // ����S�в�������ģʽT��ȵ��Ӵ�
}

Status Replace(String& S, String T, String V)
{ // ��ʼ��������S��T��V���ڣ���T�Ƿǿմ�
  // ����������ô�V�滻����S�г��ֵ������봮T��ȵĲ��ص����Ӵ�
	int i = 1; // �Ӵ�S�ĵ�һ���ַ�����Ҵ�T
	Status k;
	if (StrEmpty(T)) // T�ǿմ�
		return ERROR;
	while (i)
	{
		i = Index(S, T, i); // ���iΪ����һ��i֮���ҵ����Ӵ�T��λ��
		if (i) // ��S�д��ڴ�T
		{
			StrDelete(S, i, StrLength(T)); // ɾ����T
			k = StrInsert(S, i, V); // ��ԭ��T��λ�ò��봮V
			if (!k) // ������ȫ����(����˳��洢�ṹ�п��ܷ����������)
				return ERROR;
			i += StrLength(V); // �ڲ���Ĵ�V����������Ҵ�T
		}
	};
	return OK;
}
