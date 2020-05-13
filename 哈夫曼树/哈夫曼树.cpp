#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
using namespace std;
typedef struct
{
	int weight;
	int parent, lChild, rChild;
}HTNode, *HuffmanTree;
void SeleteMin(HuffmanTree ht, int n, int &s1, int &s2)
{
	long min1 = 888888;
	long min2 = 888888;
	int i;
	for (i = 0; i < n; i++)
	{
		if (ht[i].parent == 0)
		{
			if (min1 > ht[i].weight)
			{
				min1 = ht[i].weight;
				s1 = i;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (ht[i].parent == 0)
		{
			if (min2 > ht[i].weight&&i != s1)
			{
				min2 = ht[i].weight;
				s2 = i;
			}
		}
	}
}
void CreateHuffmanTree(HuffmanTree &ht, int &m,int &N)
{
	int n;
	cout << "请输入共多少个权值:";
	cin >> n;
	m = 2 * n - 1;
	N = n;
	ht = new HTNode[m];
	for (int i = 0; i < m; i++)
	{
		ht[i].parent = ht[i].lChild = ht[i].rChild = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "输入第" << i + 1 << "个权值:";
		cin >> ht[i].weight;
	}
	for (int i = n; i < m; i++)
	{
		int s1, s2;
		SeleteMin(ht, i, s1, s2);
		ht[s1].parent = ht[s2].parent = i;
		ht[i].lChild = s1;
		ht[i].rChild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}
}
void Print(HuffmanTree ht, int m)
{
	cout << "index weight parent lChild rChild" << endl;
	cout << left;    // 左对齐输出 
	for (int i = 0;i < m; i++) 
	{
		cout << setw(5) << i << " ";
		cout << setw(6) << ht[i].weight << " ";
		cout << setw(6) << ht[i].parent << " ";
		cout << setw(6) << ht[i].lChild << " ";
		cout << setw(6) << ht[i].rChild << endl;
	}
}
void DestroyHuffmanTree(HuffmanTree &ht)
{
	delete[] ht;
	ht = NULL;
}
int HuffmanTreeWPL(HuffmanTree ht, int i, int deepth)
{
	if (ht[i].lChild == 0 && ht[i].rChild == 0)
		return ht[i].weight*deepth;
	else
		return HuffmanTreeWPL(ht, ht[i].lChild, deepth + 1) + HuffmanTreeWPL(ht, ht[i].rChild, deepth + 1);
}
/*
	哈夫曼编码
*/

void HuffmanNode(HuffmanTree ht, const int m)
{
	char **HC = new char *[m];
	char *cd = new char[m];
	int temp, count, i;
	for (i = 0; i < m; i++)
	{
		count = 0;
		temp = ht[i].parent;
		int c = i;
		while (temp != 0)
		{
			if (ht[temp].lChild == c)
				cd[count++] = '0';
			else
				cd[count++] = '1';
			c = temp;
			temp = ht[temp].parent;
		}
		cd[count] = '\0';
		HC[i] = new char[count + 1];
		for (int j = count; j > 0; j--)
		{
			HC[i][count - j] = cd[j - 1];
		}
		HC[i][count] = cd[count];
	}
	for (i = 0; i < m; i++)
	{
		cout << ht[i].weight << "的哈夫曼编码:";
		cout << HC[i] << endl;
	}
	for (i = 0; i < m; i++)
	{
		if (HC[i] != NULL)
			delete[] HC[i];
		HC[i] = NULL;
	}
	if (HC != NULL)
	{
		delete[] HC;
		HC = NULL;
	}
	if (cd != NULL)
	{
		delete[] cd;
		cd = NULL;
	}
}
int main()
{
	int m, n;
	HuffmanTree ht;
	CreateHuffmanTree(ht, m, n);
	Print(ht, m);
	int deepth = HuffmanTreeWPL(ht, m - 1 , 0);
	cout << "WPL = " << deepth << endl;
	HuffmanNode(ht, n);
	DestroyHuffmanTree(ht);
	return 0;
}
