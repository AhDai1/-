#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int a[20] = { 1,3,5,7,8,9,11 };
	int b[20] = { 2,4,6,10,13 };
	int c[40] = { 0 };
	int i, j, k, p;
	int len_b = 5;
	int len_c = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i] < b[j])
			{
				for (k = len_b - 1; k >= j; k--)
				{
					b[k + 1] = b[k];
				}
				b[j] = a[i];
				len_b++;
			}
		}
	}
	len_c = len_b;
	for (p = 0; p < len_b; p++)
	{
		c[p] = b[p];
	}
	for (i = 0; i < len_c; i++)
		cout << c[i] << " ";
	return 0;
}
