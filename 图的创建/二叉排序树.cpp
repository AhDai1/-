#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct BTNode
{
	int data;
	struct BTNode *lchild, *rchild;
}BTNode;
BTNode* Serch_BST(BTNode *root, int key)
{
	BTNode *cur = root;
	while (cur != NULL)
	{
		if (cur->data == key)
			return cur;
		else if (cur->data < key)
			cur = cur->rchild;
		else if (cur->data > key)
			cur = cur->lchild;
	}
	return NULL;
}
void Insert_BST(BTNode **root, int key)
{
	if ((*root) == NULL)
	{
		*root = new BTNode;
		(*root)->data = key;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		return;
	}
	if (Serch_BST(*root, key) != NULL)
		return;
	BTNode *Node = new BTNode;
	Node->data = key;
	Node->lchild = NULL;
	Node->rchild = NULL;
	BTNode *cur = *root;
	BTNode *parent = NULL;
	while (cur != NULL)
	{
		parent = cur;
		if (key < cur->data )
			cur = cur->lchild;
		else if (key > cur->data)
			cur = cur->rchild;
		else
			break;
	}
	if (key < parent->data)
		parent->lchild = Node;
	else
		parent->rchild = Node;

}
void InOrderTraverse(BTNode *root)
{
	if (root == NULL)
		return;
	InOrderTraverse(root->lchild);
	cout << root->data << " ";
	InOrderTraverse(root->rchild);
}
void Delete_BST(BTNode *root, int key)
{
	BTNode *cur = root;
	BTNode *parent = NULL;
	while (cur != NULL)
	{
		if (key < cur->data)
		{
			parent = cur;
			cur = cur->lchild;
		}
		else if (key > cur->data)
		{
			parent = cur;
			cur = cur->rchild;
		}
		else
			break;
	}
	if (cur == NULL)
		return;
	if (cur->rchild == NULL)//������Ϊ��
	{
		if (parent != NULL)//cur�ĸ��ڵ㲻Ϊ��
		{
			if (parent->lchild == cur)//���ɾ������parent����ڵ�
			{
				parent->lchild = cur->lchild;//����ɾ���Ľڵ���ڵ㸳ֵ�����ڵ����ڵ�
			}
			else
			{
				parent->rchild = cur->lchild;
			}

		}
		else
		{
			root = cur->lchild;
		}
	}
	else if (cur->lchild == NULL)
	{
		if (parent != NULL)
		{
			if (parent->lchild == cur)
			{
				parent->lchild = cur->rchild;
			}
			else
			{
				parent->rchild = cur->rchild;
			}
		}
		else
		{
			root = cur->rchild;
		}
	}
	else//������������Ϊ��
	{
		BTNode *Node = cur->lchild;
		BTNode *PNode = cur;
		//�����滻�Ľ��������ӽ��
		while (Node->rchild != NULL)// ��Ϊ�ҽ����ڸ�����ֵ���������ӽ����ӽ���ɾ���Ľ��
		{
			PNode = Node;
			Node = Node->rchild;
		}
		//���������ӽڵ�ʱ,��Ҫ����������ӽ���ֵ
		if (PNode == cur)
		{
			PNode->lchild = Node->lchild;
		}
		//Node�϶��Ǵ���PNode��ֵ
		else
		{
			PNode->rchild = Node->lchild;
		}
		cur->data = Node->data;
	}
}
int main()
{
	BTNode *root = NULL;
	int arr[10] = { 5,6,1,3,9,7,4,2,10,8 };
	for (int i = 0; i < 10; i++)
		Insert_BST(&root, arr[i]);
	InOrderTraverse(root);
	Delete_BST(root, 6);
	cout << endl;
	InOrderTraverse(root);
	return 0;
}
