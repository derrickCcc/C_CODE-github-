#define _CRT_SECURE_NO_WARNINGS
#include "BTree.h"
#include "Queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	root->val = a[(*pi)++];
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);

	return root;
}

// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) 
		 + BinaryTreeSize(root->right) 
		 + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) 
		 + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) 
		 + BinaryTreeLevelKSize(root->right, k - 1);

}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;

	return BinaryTreeFind(root->right, x);
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreePrevOrder(root->left);
	printf("%c ", root->val);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%c ", root->val);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{

	Queue pq;
	QueueInit(&pq);
	if(root)
		QueuePush(&pq, root);
	while (!QueueEmpty(&pq))
	{
		BTNode* cur = QueueFront(&pq);
		QueuePop(&pq);
		printf("%c ", cur->val);

		if(cur->left)
			QueuePush(&pq, cur->left);
		if(cur->right)
			QueuePush(&pq, cur->right);

	}

	QueueDestroy(&pq);
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);
	if (root)
		QueuePush(&pq, root);

	while (!QueueEmpty(&pq))
	{
		BTNode* head = QueueFront(&pq);
		QueuePop(&pq);

		if (head)
		{
			QueuePush(&pq, head->left);
			QueuePush(&pq, head->right);
		}
		else
			break;
	}

	while (!QueueEmpty(&pq))
	{
		BTNode* head = QueueFront(&pq);
		QueuePop(&pq);

		if (head)
		{
			QueueDestroy(&pq);
			return 0;
		}
	}

	QueueDestroy(&pq);
	return 1;
}