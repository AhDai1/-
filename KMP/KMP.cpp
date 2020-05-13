#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void get_next(const char *str, int *next)
{
	int len = strlen(str);
	next[0] = -1;
	int k = -1;
	int j = 0;
#if 0
	while (j < len - 1)
	{
		if (k == -1 || str[j] == str[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
#endif
	/*
		例如：str1:abaca   str2:abab
		当i = 3, j = 3时不相等，j移到1，str1[j]与str2[i]必然不匹配
		所以以下求next的优化版需要做如下判断，减少这一没有必要的比较
	*/
#if 1
	while (j < len - 1)
	{
		if (k == -1 || str[j] == str[k])
		{
			j++;
			k++;
			if (str[k] != str[j])
				next[j] = k;
			else
				next[j] = next[k];
		}
		else
			k = next[k];
	}
#endif

}
int KMP(const char *str1, const char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int next[100];
	get_next(str2, next);
	int i = 0, j = 0;
	while (i < len1&&j < len2)
	{

		if (j == -1 || str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == len2)
		return i - j;
	else
		return -1;
}
int main()
{
	const char *str1 = "bacbababadababacambabacaddababacasdsd";
	const char *str2 = "ababaca";
	int n = KMP(str1, str2);
	printf("%d\n", n);
	return 0;
}
