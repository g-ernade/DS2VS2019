#pragma once
#include"Basic.h"
//包含了原c4-1.h,bo4-1.cpp
// c4-1.h 串的定长顺序存储结构。在教科书第73页
#define MAX_STR_LEN 40 // 用户可在255(1个字节所能表示的最大整数)以内定义最大串长
typedef unsigned char SString[MAX_STR_LEN + 1]; // 0号单元存放串的长度
typedef SString String;
 // bo4-1.cpp 串采用定长顺序存储结构(由c4-1.h定义)的基本操作(12个)，
 // 包括算法4.2、4.3、4.5。SString是数组，故不需要引用类型
#define DestroyString ClearString // DestroyString()与ClearString()作用相同
#define InitString ClearString // InitString()与ClearString()作用相同
Status StrAssign(SString T, char* chars)
{ // 生成一个其值等于chars的串T
	int i;
	if (strlen(chars) > MAX_STR_LEN) // chars的长度大于最大串长
		return ERROR;
	else
	{
		T[0] = strlen(chars); // 0号单元存放串的长度
		for (i = 1; i <= T[0]; i++) // 从1号单元起复制串的内容
			T[i] = *(chars + i - 1);
		return OK;
	}
}

void StrCopy(SString T, SString S)
{ // 由串S复制得串T
	int i;
	for (i = 0; i <= S[0]; i++)
		T[i] = S[i];
}

Status StrEmpty(SString S)
{ // 若S为空串，则返回TRUE；否则返回FALSE
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}

int StrCompare(SString S, SString T)
{ // 初始条件：串S和串T存在
  // 操作结果：若S>T，则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; ++i)
		if (S[i] != T[i])
			return S[i] - T[i];
	return S[0] - T[0];
}

int StrLength(SString S)
{ // 返回串S的元素个数
	return S[0];
}

void ClearString(SString S)
{ // 初始条件：串S存在。操作结果：将S清为空串
	S[0] = 0; // 令串长为零
}

Status Concat(SString T, SString S1, SString S2) // 算法4.2修改
{ // 用T返回S1和S2连接而成的新串。若未截断，则返回TRUE；否则返回FALSE
	int i;
	if (S1[0] + S2[0] <= MAX_STR_LEN) // 未截断
	{
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	}
	else // 截断S2
	{
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= MAX_STR_LEN - S1[0]; i++) // 到串长为止
			T[S1[0] + i] = S2[i];
		T[0] = MAX_STR_LEN;
		return FALSE;
	}
}

Status SubString(SString Sub, SString S, int pos, int len)
{ // 用Sub返回串S的自第pos个字符起长度为len的子串。算法4.3
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1) // pos和len的值超出范围
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub[i] = S[pos + i - 1];
	Sub[0] = len;
	return OK;
}

int Index1(SString S, SString T, int pos)
{ // 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数值为0。
  // 其中，T非空，1≤pos≤StrLength(S)。算法4.5
	int i, j; // 指示主串S和子串T的当前比较字符
	if (1 <= pos && pos <= S[0]) // pos的范围合适
	{
		i = pos; // 从主串S的第pos个字符开始和子串T的第1个字符比较
		j = 1;
		while (i <= S[0] && j <= T[0])
			if (S[i] == T[j]) // 当前两字符相等
			{
				++i; // 继续比较后继字符
				++j;
			}
			else // 当前两字符不相等
			{
				i = i - j + 2; // 两指针后退重新开始匹配
				j = 1;
			}
		if (j > T[0]) // 主串S中存在子串T
			return i - T[0];
		else // 主串S中不存在子串T
			return 0;
	}
	else // pos的范围不合适
		return 0;
}

Status StrInsert(SString S, int pos, SString T)
{ // 初始条件：串S和T存在，1≤pos≤StrLength(S)+1
  // 操作结果：在串S的第pos个字符之前插入串T。完全插入返回TRUE，部分插入返回FALSE
	int i;
	if (pos<1 || pos>S[0] + 1) // pos超出范围
		return ERROR;
	if (S[0] + T[0] <= MAX_STR_LEN) // 完全插入
	{
		for (i = S[0]; i >= pos; i--) // 移动串S中位于pos之后的字符
			S[i + T[0]] = S[i]; // 串S向后移串T的长度，为插入串T准备空间
		for (i = pos; i < pos + T[0]; i++) // 在串S中插入串T
			S[i] = T[i - pos + 1];
		S[0] += T[0]; // 更新串S的长度
		return TRUE; // 完全插入的标记
	}
	else // 部分插入
	{
		for (i = MAX_STR_LEN; i >= pos + T[0]; i--) // 移动串S中位于pos之后且移后仍在串内的字符
			S[i] = S[i - T[0]];
		for (i = pos; i < pos + T[0] && i <= MAX_STR_LEN; i++) // 在串S中插入串T(也可能是部分插入)
			S[i] = T[i - pos + 1];
		S[0] = MAX_STR_LEN; // 串S的长度为串的最大长度
		return FALSE; // 部分插入的标记
	}
}

Status StrDelete(SString S, int pos, int len)
{ // 初始条件：串S存在，1≤pos≤StrLength(S)-len+1
  // 操作结果：从串S中删除自第pos个字符起长度为len的子串
	int i;
	if (pos<1 || pos>S[0] - len + 1 || len < 0) // pos和len的值超出范围
		return ERROR; // 删除不成功的标记
	for (i = pos + len; i <= S[0]; i++) // 对于删除的子串之后的所有字符
		S[i - len] = S[i]; // 向前移动删除子串的长度
	S[0] -= len; // 更新串S的长度
	return OK; // 删除成功的标记
}
void StrPrint(SString S)
{ // 输出字符串S。新增
	int i;
	for (i = 1; i <= S[0]; i++)
		printf("%c", S[i]);
	printf("\n");
}

int Index(String S, String T, int pos) // 算法4.1
{ // T为非空串。若主串S中第pos个字符之后存在与T相等的子串，
  // 则返回第一个这样的子串在S中的位置；否则返回0
	int n, m, i;
	String sub;
	InitString(sub); // 新增
	if (pos > 0)
	{
		n = StrLength(S); // 主串S的长度
		m = StrLength(T); // 模式串T的长度
		i = pos;
		while (i <= n - m + 1) // i从串S的pos到倒数第m个
		{
			SubString(sub, S, i, m); // 子串sub是从主串S的第i个字符起，长度为m的子串
			if (StrCompare(sub, T) != 0) // 子串sub不等于模式串T
				++i; // 继续向后比较
			else // 子串sub等于模式串T
				return i; // 返回模式串T的第1个字符在主串S中的位置
		}
	}
	return 0; // 主串S中不存在与模式T相等的子串
}

Status Replace(String& S, String T, String V)
{ // 初始条件：串S、T和V存在，串T是非空串
  // 操作结果：用串V替换主串S中出现的所有与串T相等的不重叠的子串
	int i = 1; // 从串S的第一个字符起查找串T
	Status k;
	if (StrEmpty(T)) // T是空串
		return ERROR;
	while (i)
	{
		i = Index(S, T, i); // 结果i为从上一个i之后找到的子串T的位置
		if (i) // 串S中存在串T
		{
			StrDelete(S, i, StrLength(T)); // 删除串T
			k = StrInsert(S, i, V); // 在原串T的位置插入串V
			if (!k) // 不能完全插入(定长顺序存储结构有可能发生这种情况)
				return ERROR;
			i += StrLength(V); // 在插入的串V后面继续查找串T
		}
	};
	return OK;
}
